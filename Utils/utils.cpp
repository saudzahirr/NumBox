/*
 * Author: Saud Zahir
 * Date: December 10, 2023
 * Description: NumBox utility functions.
 */

#include <iostream>
#include <iomanip>
#include "utils.h"

using namespace std;


// Derivative of a function using Ab initio principle.
double Derivative(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
};


// Linear Algebra Utils.
double** matrixProduct(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cerr << "Error: Matrices cannot be multiplied. Invalid dimensions." << endl;
        return nullptr;
    }

    // Dynamically allocate memory for the output matrix
    double** C = new double*[rowsA];
    for (int i = 0; i < rowsA; ++i) {
        C[i] = new double[colsB];
    }

    // Initialize elements of C to 0
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0.0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
};

double Dot(double* vectorA, double* vectorB, int n) {
    double a = 0.0;
    for (int i = 0; i < n; ++i) {
        a += vectorA[i] * vectorB[i];
    }
    return a;
};

double* Cross(double* vectorA, double* vectorB) {
    double vector[3];
    vector[0] = vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1];
    vector[1] = vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2];
    vector[2] = vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0];
};

// Function to clean up the allocated memory for the matrix
void cleanMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
};

void displayMatrix(double** matrix, int rows, int cols, int cellSize = 8) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(cellSize) << matrix[i][j] << "\t";
        }
        cout << endl;
    }
};

double determinantTriangularMatrix(double** matrix, int n) {
    double det = 1.0;

    // Multiply the diagonal elements
    for (int i = 0; i < n; ++i) {
        det *= matrix[i][i];
    }

    return det;
}

void getSubmatrix(double** matrix, int size, int row, int col, double** submatrix) {
    int subRow = 0, subCol = 0;
    for (int i = 0; i < size; ++i) {
        if (i != row) {
            subCol = 0;
            for (int j = 0; j < size; ++j) {
                if (j != col) {
                    submatrix[subRow][subCol] = matrix[i][j];
                    ++subCol;
                }
            }
            ++subRow;
        }
    }
}

double Determinant(double** matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }

    double det = 0.0;

    // Laplace expansion
    for (int i = 0; i < n; ++i) {
        // Calculate the cofactor (sign * minor) and add it to the determinant
        double** submatrix = new double*[n - 1];
        for (int j = 0; j < n - 1; ++j) {
            submatrix[j] = new double[n - 1];
        }

        getSubmatrix(matrix, n, 0, i, submatrix);

        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * Determinant(submatrix, n - 1);

        // Deallocate memory for submatrix
        for (int j = 0; j < n - 1; ++j) {
            delete[] submatrix[j];
        }
        delete[] submatrix;
    }

    return det;
}
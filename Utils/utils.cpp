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

void Cross(double* vectorA, double* vectorB, double* vector) {
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
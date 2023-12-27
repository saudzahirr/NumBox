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
double** matrixAdd(double** A, double** B, int n, int m) {
    double** C = new double*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new double[m];
        for (int j = 0; j < m; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
};

double** matrixSub(double** A, double** B, int n, int m) {
    double** C = new double*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new double[m];
        for (int j = 0; j < m; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
};

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

double** matrixScalarProduct(double** A, int m, int n, double c) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = c * A[i][j];
        }
    }
    return A;
};

double** Transpose(double** matrix, int n, int m) {
    double** transposedMatrix = new double*[m];
    for (int i = 0; i < m; ++i) {
        transposedMatrix[i] = new double[n];
    }

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
};

bool equalMatrices(double** A, double** B, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            double roundedA = round(A[i][j] * 1E12) / 1E12;
            double roundedB = round(B[i][j] * 1E12) / 1E12;
            if (fabs(roundedA - roundedB) > TOLERANCE) {
                return false;
            }
        }
    }
    return true;
};

bool equalVectors(double* vectorA, double* vectorB, int n) {
    for (int i = 0; i < n; ++i) {
        double roundedA = round(vectorA[i] * 1E12) / 1E12;
        double roundedB = round(vectorB[i] * 1E12) / 1E12;
        if (fabs(roundedA - roundedB) > TOLERANCE) {
            return false;
        }
    }
    return true;
}

double* vectorAdd(double* vectorA, double* vectorB, int n) {
    double* vector = new double[n];
    for (int i = 0; i < n; ++i) {
        vector[i] = vectorA[i] + vectorB[i];
    }
    return vector;
};

double* vectorSub(double* vectorA, double* vectorB, int n) {
    double* vector = new double[n];
    for (int i = 0; i < n; ++i) {
        vector[i] = vectorA[i] - vectorB[i];
    }
    return vector;
};

double* vectorScalarProduct(double* v, int n, double c) {
    for (int i = 0; i < n; ++i) {
        v[i] = c * v[i];
    }
    return v;
};

double* vectorProduct(double** A, int rowsA, int colsA, double* v, int rowsB) {
    if (colsA != rowsB) {
        cerr << "Matrix and vector dimensions are not compatible for multiplication.\n";
        return nullptr;
    }

    double* x = new double[rowsA];

    for (int i = 0; i < rowsA; ++i) {
        x[i] = 0.0;
        for (int j = 0; j < colsA; ++j) {
            x[i] += A[i][j] * v[j];
        }
    }
    return x;
};

double** outerProduct(double* vectorA, int m, double* vectorB, int n) {
    double** matrix = new double*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new double[n];
    }

    // Compute the outer product
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = vectorA[i] * vectorB[j];
        }
    }

    return matrix;
}

double Dot(double* vectorA, double* vectorB, int n) {
    double a = 0.0;
    for (int i = 0; i < n; ++i) {
        a += vectorA[i] * vectorB[i];
    }
    return a;
};

double* Cross(double* vectorA, double* vectorB) {
    double* vector = new double[3];
    vector[0] = vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1];
    vector[1] = vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2];
    vector[2] = vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0];
    return vector;
};

double Norm(double* x, int n) {
    return sqrt(Dot(x, x, n));
};

double Max(double* x, int n) {
    double a = 0.0;
    for (int i = 0; i < n; ++i) {
        a = max(x[i], a);
    }
    return a;
};

double Min(double* x, int n) {
    double a = 0.0;
    for (int i = 0; i < n; ++i) {
        a = min(x[i], a);
    }
    return a;
};

double* divideVector(double* v, int n, double s) {
    for (int i = 0; i < n; ++i) {
        v[i] = v[i] / s;
    }
    return v;
};

double** divideMatrix(double** A, int m, int n, double s) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = A[i][j] /s;
        }
    }
    return A;
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

void displayVector(double* vector, int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            cout << vector[i] << ", ";
        }
        else {
            cout << vector[i];
        }
    }
    cout << "]" << endl;
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
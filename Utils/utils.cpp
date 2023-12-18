/*
 * Author: Saud Zahir
 * Date: December 10, 2023
 * Description: NumBox utility functions.
 */

#include <iostream>
#include "utils.h"

using namespace std;

// Matrix multiplication.
double* multiplyMatrices(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cerr << "Error: Matrices cannot be multiplied. Invalid dimensions." << endl;
        return nullptr;
    }

    // Dynamically allocate memory for the output matrix
    double* C = new double[rowsA * colsB];

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i * colsB + j] = 0.0;
            for (int k = 0; k < colsA; ++k) {
                C[i * colsB + j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Derivative of a function using Ab initio principle.
double calculateDerivative(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}
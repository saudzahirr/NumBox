/*
 * Author: Saud Zahir
 * Date: December 18, 2023
 * Description: Cholesky LU Decomposition Method decomposes a matrix A (A = LU) into
 * a lower triangular matrix (L), an upper triangular matrix (U).
 */

#include <iostream>
#include <cmath>
#include "doolittle.h"
#include "../Utils/utils.h"

using namespace std;

void choleskyDecomposition(double** A, double**& L, int n) {
    L = new double*[n];
    for (int i = 0; i < n; ++i) {
        L[i] = new double[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            L[i][j] = 0.0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0.0;

            if (i == j) {
                for (int k = 0; k < j; ++k) {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; ++k) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

void displayMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int n = 4;

    double** A = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    // Define a matrix (4D array)
    A[0][0] = 10.0; A[0][1] = -1.0; A[0][2] = 2.0; A[0][3] = 0;
    A[1][0] = -1.0; A[1][1] = 11.0; A[1][2] = -1.0; A[1][3] = 3.0;
    A[2][0] = 2.0; A[2][1] = -1.0; A[2][2] = 10.0; A[2][3] = -1.0;
    A[3][0] = 0.0; A[3][1] = 3.0; A[3][2] = -1.0; A[3][3] = 8.0;

    double** L;
    choleskyDecomposition(A, L, n);

    // Display the results
    cout << "Matrix A:" << endl;
    displayMatrix(A, n, n);

    cout << "\nMatrix L:" << endl;
    displayMatrix(L, n, n);


    // Clean up memory
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] L[i];
    }
    delete[] A;
    delete[] L;

    return 0;
}
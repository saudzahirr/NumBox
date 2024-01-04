#include <iostream>
#include "cholesky.h"
#include "../Utils/utils.h"

using namespace std;

double** forwardSubstitution(double** L, int n) {
    // Create and initialize the identity matrix
    double** I = new double*[n];
    for (int i = 0; i < n; ++i) {
        I[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            I[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Forward substitution
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i == j) {
                // Diagonal elements
                double factor = 1.0 / L[i][i];
                for (int k = 0; k < n; ++k) {
                    L[i][k] *= factor;
                    I[i][k] *= factor;
                }
            } else if (i > j) {
                // Off-diagonal elements
                double factor = L[i][j];
                for (int k = 0; k < n; ++k) {
                    L[i][k] -= factor * L[j][k];
                    I[i][k] -= factor * I[j][k];
                }
            }
        }
    }

    return I;
}

int main() {
    const int n = 4;
    double** A = new double*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    const double MATRIX_A[n][n] = {
        {10.0, -1.0, 2.0, 0.0},
        {-1.0, 11.0, -1.0, 3.0},
        {2.0, -1.0, 10.0, -1.0},
        {0.0, 3.0, -1.0, 8.0}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = MATRIX_A[i][j];
        }
    }

    double** L;
    choleskyDecomposition(A, L, n);

    double** I = forwardSubstitution(L, n);

    // Display the inverse matrix
    cout << "Inverse of L:\n";
    displayMatrix(I, n, n, 8);

    double** X = matrixProduct(Transpose(I, n, n), n, n, I, n, n);

    cout << "Inverse of A:\n";
    displayMatrix(X, n, n, 8);

    double** U = matrixProduct(X, n, n, A, n, n);
    cout << "Inverse of AA^-1:\n";
    displayMatrix(U, n, n, 8);

    cleanMatrix(A, n);
    cleanMatrix(L, n);
    cleanMatrix(I, n);
    cleanMatrix(X, n);
    cleanMatrix(U, n);

    return 0;
}

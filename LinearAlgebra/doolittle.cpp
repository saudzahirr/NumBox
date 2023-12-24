/*
 * Author: Saud Zahir
 * Date: December 17, 2023
 * Description: Doolittle LU Decomposition Method decomposes a matrix A (A = LU) into
 * a lower triangular matrix (L), an upper triangular matrix (U).
 */

#include <iostream>
#include "../Utils/utils.h"
#include "doolittle.h"

using namespace std;


void doolittleLU(double** A, double**& L, double**& U, int n) {
    // Allocate memory for L and U matrices
    L = new double*[n];
    U = new double*[n];
    for (int i = 0; i < n; i++) {
        L[i] = new double[n];
        U[i] = new double[n];
    }

    // Initialize L and U matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

    // Perform Doolittle LU decomposition
    for (int i = 0; i < n; i++) {
        // Upper Triangular
        for (int k = i; k < n; k++){
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }
 
        // Lower Triangular
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1;
            else {
                double sum = 0.0;
                for (int j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
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

    double** L, ** U;
    doolittleLU(A, L, U, n);

    // Display the results
    cout << "Matrix A:" << endl;
    displayMatrix(A, n, n, 8);

    cout << "\nMatrix L:" << endl;
    displayMatrix(L, n, n, 8);

    cout << "\nMatrix U:" << endl;
    displayMatrix(U, n, n, 8);

    // Clean up memory
    cleanMatrix(A, n);
    cleanMatrix(L, n);
    cleanMatrix(U, n);

    return 0;
}

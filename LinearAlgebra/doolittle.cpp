/*
 * Author: Saud Zahir
 * Date: December 17, 2023
 * Description: Doolittle LU Decomposition Method decomposes a matrix A (A = LU) into
 * a lower triangular matrix (L), an upper triangular matrix (U).
 */

#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "doolittle.h"

using namespace std;


void doolittleLU(double** A, double**& L, double**& U, int n) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Doolittle's LU Decomposition ...");
    DEBUG_OUT("Matrix A: \n" + getMatrixString(A, n, n, 8));

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

    DEBUG_OUT("Doolittle's Lower Triangular Matrix: \n" + getMatrixString(L, n, n, 8));
    DEBUG_OUT("Doolittle's Upper Triangular Matrix: \n" + getMatrixString(U, n, n, 8));

    time_req = clock() - time_req;
    INFO_OUT("Execution time for Doolittle's LU algorithm: "
            + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");
}

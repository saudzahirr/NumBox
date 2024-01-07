/*
 * Author: Saud Zahir
 * Date: December 17, 2023
 * Description: Crout Decomposition Method decomposes a matrix A (A = LU) into
 * a lower triangular matrix (L), an upper triangular matrix (U).
 */

#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "crout.h"

using namespace std;


void croutLU(double** A, double**& L, double**& U, int n) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Crout's LU Decomposition ...");
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

    for (int j = 0; j < n; j++) {
        for (int i = j; i < n; i++) {
            double sum = 0.0;
            for (int k = 0; k < j; k++) {
                sum = sum + L[i][k] * U[k][j];
            }
            L[i][j] = A[i][j] - sum;
        }

        for (int i = j; i < n; i++) {
            double sum = 0.0;
            for (int k = 0; k < j; k++) {
                sum = sum + L[j][k] * U[k][i];
            }
            U[j][i] = (A[j][i] - sum) / L[j][j];
        }
    }

    DEBUG_OUT("Crout's Lower Triangular Matrix: \n" + getMatrixString(L, n, n, 8));
    DEBUG_OUT("Crout's Upper Triangular Matrix: \n" + getMatrixString(U, n, n, 8));

    time_req = clock() - time_req;
    INFO_OUT("Execution time for Crout's LU algorithm: "
            + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");
}

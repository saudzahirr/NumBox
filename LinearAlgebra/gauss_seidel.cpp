/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Gauss-Seidel iterative algorithm to solve linear system of equations.
 */


#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "gauss_seidel.h"

using namespace std;


double* GaussSeidelMethod(double** A, double* b, double* x, int n) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Gauss-Seidel Method ...");
    DEBUG_OUT("Matrix A: \n" + getMatrixString(A, n, n, 8));

    double* x_k = new double[n];

    // Gauss-Seidel method elementwise formula.
    for (int a = 1; a <= ITERATIONS; ++a) {
        for (int i = 0; i < n; ++i) {
            double S1 = 0;
            double S2 = 0;
            for (int j = 0; j < i; ++j) {
                S1 += A[i][j] * x_k[j];
            }
            for (int j = i + 1; j < n; ++j) {
                S2 += A[i][j] * x[j];
            }

            if (A[i][i] != 0) {
                x_k[i] = (b[i] - S1 - S2) / A[i][i];
            }
            else {
                ERROR_OUT("Division by zero encountered. Gauss-Seidel method did not converge!");
                delete[] x_k;
                return nullptr;
            }
        }

        // Absolute error evaluation
        double max_diff = 0.0;
        for (int i = 0; i < n; ++i) {
            double diff = abs(x_k[i] - x[i]);
            if (diff > max_diff) {
                max_diff = diff;
            }
        }

        for (int i = 0; i < n; ++i) {
            x[i] = x_k[i];
        }

        if (max_diff < TOLERANCE) {
            INFO_OUT("Gauss-Seidel method converged at "
                    + to_string(a) + " iterations.");
            
            DEBUG_OUT("x = " + getVectorString(x, n));

            time_req = clock() - time_req;
            INFO_OUT("Execution time for Gauss-Seidel Method: "
            + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

            delete[] x_k;
            return x;
        }
    }
    delete[] x_k;

    ERROR_OUT("Gauss-Seidel method did not converge!");
    return nullptr;
}

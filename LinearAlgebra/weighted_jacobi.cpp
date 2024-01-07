/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Weighted jacobi iterative algorithm to solve linear system of equations.
 */


#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "weighted_jacobi.h"

using namespace std;


double* WeightedJacobiMethod(double** A, double* b, double* x, double w, int n) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Weighted Jacobi Method ...");
    DEBUG_OUT("Matrix A: \n" + getMatrixString(A, n, n, 8));

    double* x_k = new double[n];

    // Jacobi method elementwise formula.
    for (int a = 1; a <= ITERATIONS; ++a) {
        for (int i = 0; i < n; ++i) {
            double S = 0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    S += A[i][j] * x[j];
                }
            }

            if (A[i][i] != 0) {
                x_k[i] =  (1 - w) * x[i] + (w / A[i][i]) * (b[i] - S);
            }
            else {
                ERROR_OUT("Division by zero encountered. Weighted Jacobi method did not converge!");
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
            INFO_OUT("Weighted Jacobi method converged at " + to_string(a + 1) + " iterations.");
            
            DEBUG_OUT("x = " + getVectorString(x, n));

            time_req = clock() - time_req;
            INFO_OUT("Execution time for Weighted Jacobi Method: "
                    + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

            delete[] x_k;
            return x;
        }
    }
    delete[] x_k;

    ERROR_OUT("Weighted Jacobi method did not converge!");
    return nullptr;
}

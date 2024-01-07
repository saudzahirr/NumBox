/*
 * Author: Saud Zahir
 * Date: December 21, 2023
 * Description: Successive over-relaxation (SOR) iterative algorithm to solve linear system of equations.
 *              Successive over-relaxation (SOR) is a variant of the Gauss–Seidel method for solving a
 *              linear system of equations, resulting in faster convergence.
 */


#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "sor.h"

using namespace std;


double* SuccessiveOverRelaxation(double** A, double* b, double* x, double w, int n) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Successive Over-Relaxation Method ...");
    DEBUG_OUT("Matrix A: \n" + getMatrixString(A, n, n, 8));

    double* x_k = new double[n];

    // SOR method element-wise formula.
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
                x_k[i] = (1 - w) * x[i] + (w / A[i][i]) * (b[i] - S1 - S2);
            }
            else {
                ERROR_OUT("Division by zero encountered. SOR method did not converge!");
                delete[] x_k;
                return nullptr;
            }
        }

        // Relative error evaluation
        double max_relative_diff = 0.0;
        for (int i = 0; i < n; ++i) {
            double relative_diff = abs((x_k[i] - x[i]) / x_k[i]);
            if (relative_diff > max_relative_diff) {
                max_relative_diff = relative_diff;
            }
        }

        for (int i = 0; i < n; ++i) {
            x[i] = x_k[i];
        }

        if (max_relative_diff < TOLERANCE) {
            INFO_OUT("Successive Over-Relaxation (SOR) Method converged at "
                    + to_string(a) + " iterations.");
            
            DEBUG_OUT("x = " + getVectorString(x, n));

            time_req = clock() - time_req;
            INFO_OUT("Execution time for Successive Over-Relaxation (SOR) Method: "
            + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

            delete[] x_k;
            return x;
        }
    }
    delete[] x_k;

    ERROR_OUT("SOR method did not converge!");
    return nullptr;
}

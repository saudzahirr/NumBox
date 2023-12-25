/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Weighted jacobi iterative algorithm to solve linear system of equations.
 */


#include <iostream>
#include "../Utils/utils.h"
#include "weighted_jacobi.h"

using namespace std;


double* WeightedJacobiMethod(double** A, double* b, double* x, double w, int n) {
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
            x_k[i] =  (1 - w) * x[i] + (w / A[i][i]) * (b[i] - S);
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
            cout << "Weighted Jacobi method converged at " << a + 1 << " iterations." << endl;
            delete[] x_k;
            return x;
        }
    }
    delete[] x_k;

    cerr << "Weighted Jacobi method did not converge!" << endl;
    return nullptr;
}

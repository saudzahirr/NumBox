/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Gauss-Seidel iterative algorithm to solve linear system of equations.
 */


#include <iostream>
#include "gauss_seidel.h"

using namespace std;

#define ITERATIONS 1000
#define TOLERANCE 1E-32

double* GaussSeidelMethod(double** A, double* b, double* x, int n) {
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
            x_k[i] = (b[i] - S1 - S2) / A[i][i];
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
            cout << "Gauss-Seidel method converged at " << a << " iterations." << endl;
            for (int i = 0; i < n; ++i) {
                cout << "x[" << i << "] = " << x[i] << endl;
            }
            delete[] x_k;
            break;
        }
    }
    delete[] x_k;

    return x;
}

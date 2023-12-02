/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Jacobi iterative algorithm to solve linear system of equations.
 */


#include <iostream>

using namespace std;

#define ITERATIONS 1000
#define TOLERANCE 1E-32

double* JacobiMethod(double** A, double* b, double* x, int n) {
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
            x_k[i] = (b[i] - S) / A[i][i];
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
            cout << "Jacobi method converged at " << a + 1 << " iterations." << endl;
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
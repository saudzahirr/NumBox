/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Jacobi iterative algorithm to solve linear system of equations.
 */


#include <iostream>
#include "jacobi.h"
#include "../Utils/utils.h"


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
            delete[] x_k;
            return x;
        }
    }
    delete[] x_k;

    cerr << "Jacobi method did not converge!" << endl;
    return nullptr;
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
    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    double* U = JacobiMethod(A, b, x, n);
    if (U != nullptr) {
        for (int i = 0; i < n; ++i) {
            cout << "x[" << i << "] = " << U[i] << endl;
        }
        delete[] U; // Clean up dynamic memory
    }

    // Clean up dynamic memory
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
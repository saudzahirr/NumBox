/*
 * Author: Saud Zahir
 * Date: December 21, 2023
 * Description: Successive over-relaxation (SOR) iterative algorithm to solve linear system of equations.
 *              Successive over-relaxation (SOR) is a variant of the Gauss–Seidel method for solving a
 *              linear system of equations, resulting in faster convergence.
 */


#include <iostream>
#include "../Utils/utils.h"
#include "sor.h"

using namespace std;


double* SuccessiveOverRelaxation(double** A, double* b, double* x, double w, int n) {
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
            } else {
                cerr << "Division by zero encountered. SOR method did not converge!" << endl;
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
            cout << "SOR method converged at " << a << " iterations." << endl;
            delete[] x_k;
            return x;
        }
    }
    delete[] x_k;

    cerr << "SOR method did not converge!" << endl;
    return nullptr;
}


int main() {
    const int n = 4;
    const double w = 1.25;

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

    double* U = SuccessiveOverRelaxation(A, b, x, w, n);
    if (U != nullptr) {
        for (int i = 0; i < n; ++i) {
            cout << "x[" << i << "] = " << U[i] << endl;
        }
        delete[] U; // Clean up dynamic memory
    }

        cleanMatrix(A, n);

    return 0;
}

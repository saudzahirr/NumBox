/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Gauss-Seidel iterative algorithm to solve linear system of equations.
 */


#include <iostream>

using namespace std;

#define ITERATIONS 1000
#define TOLERANCE 1E-32

void GaussSeidelMethod(double** A, double* b, double* x, int n) {
    double* x_k = new double[n];

    // Gauss-Seidel method elementwise formula.
    for (int a = 1; a <= ITERATIONS; ++a) {
        for (int i = 0; i < n; ++i) {
            double S1 = 0;
            double S2 = 0;
            for (int j = 0; j < i - 1; ++j) {
                S1 += A[i][j] * x_k[j];
            }
            for (int j = a + 1; j <= n; ++j) {
                S2 += A[i][j] * x[j];
            }
            x_k[i] = (b[i] - S1 - S2) / A[i][i];
        }

        // Absolute error evaluation
        double max_diff = 0.0;
        for (int i = 0; i < n; ++i) {
            double diff = std::abs(x_k[i] - x[i]);
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
}

int main() {
    const int n = 3;

    double** A = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    // Define a matrix (3D array)
    A[0][0] = 4.0; A[0][1] = -1.0; A[0][2] = 1.5;
    A[1][0] = 2.2; A[1][1] = 4.0; A[1][2] = -1.0;
    A[2][0] = 0.5; A[2][1] = -1.3; A[2][2] = 2.0;
    double b[3] = {1.5, 1.0, 1.2};
    double x[3] = {0.0, 0.0, 0.0};

    GaussSeidelMethod(A, b, x, n);

    // Clean up dynamic memory
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

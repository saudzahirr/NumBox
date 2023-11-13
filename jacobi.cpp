#include <iostream>

using namespace std;

#define ITERATIONS 1000
#define TOLERANCE 1E-6

double JacobiMethod(double** A, double* b, double* x, int n) {
    // Jacobi method elementwise formula.
    for (int a = 0; a < ITERATIONS; ++a) {
        for (int i = 0; i < n; ++i) {
            double S = 0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    S += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - S) / A[i][i];
        }
    }
    return 0;
}

int main() {
    const int n = 3;

    double** A = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    // Define a matrix (2D array)
    A[0][0] = 4.0; A[0][1] = -1.0; A[0][2] = 1.5;
    A[1][0] = 2.2; A[1][1] = 4.0; A[1][2] = -1.0;
    A[2][0] = 0.5; A[2][1] = -1.3; A[2][2] = 2.0;
    double b[3] = {1.5, 1.0, 1.2};
    double x[3] = {0.0, 0.0, 0.0};

    JacobiMethod(A, b, x, n);

    for (int i = 0; i < 3; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }


    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

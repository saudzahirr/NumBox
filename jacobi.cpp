#include <iostream>

using namespace std;

#define ITERATIONS 1000

double JacobiMethod(double A[3][3], double b[3], double x[3], int n) {
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
    // Define a matrix (2D array)
    double A[3][3] = {
        {4.0, -1.0, 1.5},
        {2.2, 4, -1.0},
        {0.5, -1.3, 2.0}
    };
    double b[3] = {1.5, 1.0, 1.2};
    double x[3] = {0.0, 0.0, 0.0};
    
    int n = 3;

    JacobiMethod(A, b, x, n);

    for (int i = 0; i < 3; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}

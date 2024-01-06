#ifndef HELPERS_H
#define HELPERS_H

#include <cmath>

#define CUBIC_ROOT 1.5213797068045675696040808322544385144283898284279039090904980154
#define TRANSCENDENTAL_ROOT 0.966876881413510626654237834545340028268547068798811

double cubicPolynomial(double x) {
    return pow(x, 3) - x - 2;
};

double cubicPolynomialg(double x) {
    return cbrt(x + 2);
};

double transcendentalFunction(double x) {
    return x * sin(2 * x) - pow(x, 3);
};

double gaussianFunction(double x) {
    return exp(-x * x);
}

double** createMatrix() {
    const int n = 4;
    double** A = new double*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    return A;
};

void initializeMatrix(double** A) {
    const int n = 4;
    const double MATRIX_A[n][n] = {
        {10.0, -1.0, 2.0, 0.0},
        {-1.0, 11.0, -1.0, 3.0},
        {2.0, -1.0, 10.0, -1.0},
        {0.0, 3.0, -1.0, 8.0}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = MATRIX_A[i][j];
        }
    }
};

#endif
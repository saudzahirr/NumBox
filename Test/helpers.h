#ifndef HELPERS_H
#define HELPERS_H

#include <random>
#include <ctime>
#include <cmath>

using namespace std;

#define CUBIC_ROOT 1.5213797068045675696040808322544385144283898284279039090904980154
#define TRANSCENDENTAL_ROOT 0.966876881413510626654237834545340028268547068798811

#define MATRIX_SIZE 128

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

double** createMatrix(const int n) {
    double** A = new double*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    return A;
};

void initializeMatrix(double** A, const int n) {
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

void initializeRandomMatrix(double** A, const int n) {
    // Seed the random number generator with a random device
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Generate a random double between 0 and 1
            A[i][j] = distribution(gen);
        }
    }
}

#endif
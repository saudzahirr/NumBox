#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <math.h>

#include "test_numerical_integration.h"

#include "../Logger/logger.h"
#include "../Utils/utils.h"

#include "../RootFindingAlgorithms/bolzano.h"
#include "../RootFindingAlgorithms/newton_raphson.h"
#include "../RootFindingAlgorithms/regula_falsi.h"
#include "../RootFindingAlgorithms/secant_method.h"
#include "../RootFindingAlgorithms/fixed_point.h"

#include "../Integration/simpsons.h"

#include "../LinearAlgebra/cholesky.h"
#include "../LinearAlgebra/crout.h"
#include "../LinearAlgebra/doolittle.h"
#include "../LinearAlgebra/gauss_seidel.h"
#include "../LinearAlgebra/jacobi.h"
#include "../LinearAlgebra/rayleigh_quotient.h"
#include "../LinearAlgebra/sor.h"
#include "../LinearAlgebra/von_mises.h"
#include "../LinearAlgebra/weighted_jacobi.h"

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

// Test Bolzano's Method
void testBolzanoMethod() {
    double a = 0;
    double b = 2;
    double root = CUBIC_ROOT;

    setColor(MAGENTA);
    info("Testing Bolzano (Bisection) Method");
    setColor(DEFAULT);
    info("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    double x = BolzanosMethod(cubicPolynomial, a, b);
    setColor(YELLOW);
    info("f(" + to_string(x) + ") = " + to_string(cubicPolynomial(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }
};

// Test Newton Raphson Method
void testNewtonRaphsonMethod() {
    double x0 = 1;
    double root = TRANSCENDENTAL_ROOT;

    setColor(MAGENTA);
    info("Testing Newton-Raphson's Method");
    setColor(DEFAULT);
    info("Initial: x0 = " + to_string(x0));

    double x = NewtonRaphsonMethod(transcendentalFunction, x0);
    setColor(YELLOW);
    info("f(" + to_string(x) + ") = " + to_string(transcendentalFunction(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }
};

// Test Regula Falsi Method
void testRegulaFalsiMethod() {
    double a = 0.5;
    double b = 1;
    double root = TRANSCENDENTAL_ROOT;

    setColor(MAGENTA);
    info("Testing Regula Falsi Method");
    setColor(DEFAULT);
    info("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    double x = RegulaFalsiMethod(transcendentalFunction, a, b);
    setColor(YELLOW);
    info("f(" + to_string(x) + ") = " + to_string(transcendentalFunction(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }
};

// Test Secant Method
void testSecantMethod() {
    double a = 0;
    double b = 2;
    double root = CUBIC_ROOT;

    setColor(MAGENTA);
    info("Testing Secant Method");
    setColor(DEFAULT);
    info("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    double x = SecantMethod(cubicPolynomial, a, b);
    setColor(YELLOW);
    info("f(" + to_string(x) + ") = " + to_string(cubicPolynomial(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }
};

// Test Fixed Point Method
void testFixedPointMethod() {
    double c = 0;
    double root = CUBIC_ROOT;

    setColor(MAGENTA);
    info("Testing Fixed Point Method");
    setColor(DEFAULT);
    info("Initial: c0 = " + to_string(c));

    double x = FixedPointMethod(c, cubicPolynomialg);
    setColor(YELLOW);
    info("f(" + to_string(x) + ") = " + to_string(cubicPolynomial(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }
};

// Test Cholesky Decomposition
void testCholeskyDecomposition() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    info("Testing Cholesky LU Decomposition");
    setColor(DEFAULT);

    double** L;
    choleskyDecomposition(A, L, n);

    setColor(YELLOW);
    cout << "A = \n";    
    displayMatrix(A, n, n, 8);

    setColor(YELLOW);
    cout << "\nL = \n";
    displayMatrix(L, n, n, 8);

    if (equalMatrices(A, matrixProduct(L, n, n, Transpose(L, n, n), n, n), n, n)) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }

    // Clean up memory
    cleanMatrix(A, n);
    cleanMatrix(L, n);
};

// Test Crout Decomposition
void testCroutDecomposition() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    info("Testing Crout LU Decomposition");
    setColor(DEFAULT);

    double** L, ** U;
    croutLU(A, L, U, n);

    setColor(YELLOW);
    cout << "A = \n";
    displayMatrix(A, n, n, 8);

    setColor(YELLOW);
    cout << "\nL = \n";
    displayMatrix(L, n, n, 8);

    setColor(YELLOW);
    cout << "\nU = \n";
    displayMatrix(U, n, n, 8);

    if (equalMatrices(A, matrixProduct(L, n, n, U, n, n), n, n)) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }

    // Clean up memory
    cleanMatrix(A, n);
    cleanMatrix(L, n);
    cleanMatrix(U, n);
};

// Test Doolittle Decomposition
void testDoolittleDecomposition() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    info("Testing Doolittle LU Decomposition");
    setColor(DEFAULT);

    double** L, ** U;
    doolittleLU(A, L, U, n);

    setColor(YELLOW);
    cout << "A = \n";
    displayMatrix(A, n, n, 8);

    setColor(YELLOW);
    cout << "\nL = \n";
    displayMatrix(L, n, n, 8);

    setColor(YELLOW);
    cout << "\nU = \n";
    displayMatrix(U, n, n, 8);

    if (equalMatrices(A, matrixProduct(L, n, n, U, n, n), n, n)) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }

    // Clean up memory
    cleanMatrix(A, n);
    cleanMatrix(L, n);
    cleanMatrix(U, n);
};

// Test Gauss Seidel Method
void testGaussSeidelMethod() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    setColor(MAGENTA);
    info("Testing Gauss Seidel Method");
    setColor(DEFAULT);

    double* U = GaussSeidelMethod(A, b, x, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    setColor(YELLOW);
    if (U != nullptr) {
        cout << "x = ";
        displayVector(U, n);
    }

    if (equalVectors(X, U, n)) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test Jacobi Method
void testJacobiMethod() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    setColor(MAGENTA);
    info("Testing Jacobi Method");
    setColor(DEFAULT);

    double* U = JacobiMethod(A, b, x, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    setColor(YELLOW);
    if (U != nullptr) {
        cout << "x = ";
        displayVector(U, n);
    }

    if (equalVectors(X, U, n)) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test SOR Method
void testSORMethod() {
    const int n = 4;
    const double w = 1.25;
    double** A = createMatrix();
    initializeMatrix(A);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    setColor(MAGENTA);
    info("Testing Successive Over Relaxation Method (SOR)");
    setColor(DEFAULT);

    double* U = SuccessiveOverRelaxation(A, b, x, w, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    setColor(YELLOW);
    if (U != nullptr) {
        cout << "x = ";
        displayVector(U, n);
    }

    if (equalVectors(X, U, n)) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test Weighted Jacobi Method
void testWeightedJacobiMethod() {
    const int n = 4;
    const double w = 0.5;
    double** A = createMatrix();
    initializeMatrix(A);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    setColor(MAGENTA);
    info("Testing Weighted Jacobi Method");
    setColor(DEFAULT);

    double* U = WeightedJacobiMethod(A, b, x, w, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    setColor(YELLOW);
    if (U != nullptr) {
        cout << "x = ";
        displayVector(U, n);
    }

    if (equalVectors(X, U, n)) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test Von Mises Method
void testVonMisesMethod() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    info("Testing Von Mises Method");
    setColor(DEFAULT);

    double* x = VonMisesIterationMethod(A, n);

    setColor(YELLOW);
    cout << "Eigenvector: \nx = ";
    displayVector(x, n);

    double c = RayleighQuotient(A, x, n);
    setColor(YELLOW);
    debug("Eigenvalue: k = " + to_string(c));

    if (vectorProduct(A, n, n, x, n) == vectorScalarProduct(x, n, c), n) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }

    cleanMatrix(A, n);
};


#endif
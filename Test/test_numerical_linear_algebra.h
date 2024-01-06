#ifndef TEST_NUMERICAL_LINEAR_ALGEBRA_H
#define TEST_NUMERICAL_LINEAR_ALGEBRA_H

#include <iostream>

#include "helpers.h"

#include "../Logger/logger.h"
#include "../Utils/utils.h"

#include "../LinearAlgebra/cholesky.h"
#include "../LinearAlgebra/crout.h"
#include "../LinearAlgebra/doolittle.h"
#include "../LinearAlgebra/gauss_seidel.h"
#include "../LinearAlgebra/jacobi.h"
#include "../LinearAlgebra/rayleigh_quotient.h"
#include "../LinearAlgebra/sor.h"
#include "../LinearAlgebra/von_mises.h"
#include "../LinearAlgebra/weighted_jacobi.h"


// Test Cholesky Decomposition
void testCholeskyDecomposition() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    INFO_OUT("Testing Cholesky LU Decomposition");
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
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
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
    INFO_OUT("Testing Crout LU Decomposition");
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
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
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
    INFO_OUT("Testing Doolittle LU Decomposition");
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
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
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
    INFO_OUT("Testing Gauss Seidel Method");
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
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
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
    INFO_OUT("Testing Jacobi Method");
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
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
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
    INFO_OUT("Testing Successive Over Relaxation Method (SOR)");
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
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
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
    INFO_OUT("Testing Weighted Jacobi Method");
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
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test Von Mises Method
void testVonMisesMethod() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    INFO_OUT("Testing Von Mises Method");
    setColor(DEFAULT);

    double* x = VonMisesIterationMethod(A, n);

    setColor(YELLOW);
    cout << "Eigenvector: \nx = ";
    displayVector(x, n);

    double c = RayleighQuotient(A, x, n);
    setColor(YELLOW);
    DEBUG_OUT("Eigenvalue: k = " + to_string(c));

    if (vectorProduct(A, n, n, x, n) == vectorScalarProduct(x, n, c), n) {
        setColor(GREEN);
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

#endif
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
    double** A = createMatrix(n);
    initializeMatrix(A, n);
    
    PRINT("Testing Cholesky LU Decomposition");

    double** L;
    choleskyDecomposition(A, L, n);

    if (equalMatrices(A, matrixProduct(L, n, n, Transpose(L, n, n), n, n), n, n)) {
        TEST_PASSED("Test Passed!");
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
    double** A = createMatrix(n);
    initializeMatrix(A, n);

    PRINT("Testing Crout LU Decomposition");    

    double** L, ** U;
    croutLU(A, L, U, n);

    if (equalMatrices(A, matrixProduct(L, n, n, U, n, n), n, n)) {
        TEST_PASSED("Test Passed!");
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
    double** A = createMatrix(n);
    initializeMatrix(A, n);

    PRINT("Testing Doolittle LU Decomposition");

    double** L, ** U;
    doolittleLU(A, L, U, n);

    if (equalMatrices(A, matrixProduct(L, n, n, U, n, n), n, n)) {
        TEST_PASSED("Test Passed!");        
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
    double** A = createMatrix(n);
    initializeMatrix(A, n);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    PRINT("Testing Gauss Seidel Method");

    double* U = GaussSeidelMethod(A, b, x, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    if (equalVectors(X, U, n)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test Jacobi Method
void testJacobiMethod() {
    const int n = 4;
    double** A = createMatrix(n);
    initializeMatrix(A, n);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};
    
    PRINT("Testing Jacobi Method");

    double* U = JacobiMethod(A, b, x, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    if (equalVectors(X, U, n)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test SOR Method
void testSORMethod() {
    const int n = 4;
    double** A = createMatrix(n);
    const double w = 1.25;
    initializeMatrix(A, n);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};
    
    PRINT("Testing Successive Over Relaxation Method (SOR)");

    double* U = SuccessiveOverRelaxation(A, b, x, w, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    if (equalVectors(X, U, n)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test Weighted Jacobi Method
void testWeightedJacobiMethod() {
    const int n = 4;
    double** A = createMatrix(n);
    const double w = 0.5;
    initializeMatrix(A, n);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    PRINT("Testing Weighted Jacobi Method");
    
    double* U = WeightedJacobiMethod(A, b, x, w, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    if (equalVectors(X, U, n)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

// Test Von Mises Method
void testVonMisesMethod() {
    const int n = 4;
    double** A = createMatrix(n);
    initializeMatrix(A, n);
    
    PRINT("Testing Von Mises Method");

    double* x = VonMisesIterationMethod(A, n);
    double c = RayleighQuotient(A, x, n);

    if (vectorProduct(A, n, n, x, n) == vectorScalarProduct(x, n, c), n) {    
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }

    cleanMatrix(A, n);
};

#endif
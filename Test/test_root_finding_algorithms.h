#ifndef TEST_ROOT_FINDING_ALGORITHMS
#define TEST_ROOT_FINDING_ALGORITHMS

#include "../Logger/logger.h"
#include "../Utils/utils.h"

#include "../RootFindingAlgorithms/bolzano.h"
#include "../RootFindingAlgorithms/newton_raphson.h"
#include "../RootFindingAlgorithms/regula_falsi.h"
#include "../RootFindingAlgorithms/secant_method.h"
#include "../RootFindingAlgorithms/fixed_point.h"

// Test Bolzano's Method
void testBolzanoMethod() {
    double a = 0;
    double b = 2;
    double root = CUBIC_ROOT;
    
    PRINT("Testing Bolzano (Bisection) Method");  

    double x = BolzanosMethod(cubicPolynomial, a, b);

    if (abs(root - x) < TOLERANCE) {
        
        TEST_PASSED("Test Passed!");
        
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
};

// Test Newton Raphson Method
void testNewtonRaphsonMethod() {
    double x0 = 1;
    double root = TRANSCENDENTAL_ROOT;

    PRINT("Testing Newton-Raphson's Method");

    double x = NewtonRaphsonMethod(transcendentalFunction, x0);

    if (abs(root - x) < TOLERANCE) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
};

// Test Regula Falsi Method
void testRegulaFalsiMethod() {
    double a = 0.5;
    double b = 1;
    double root = TRANSCENDENTAL_ROOT;

    PRINT("Testing Regula Falsi Method");

    double x = RegulaFalsiMethod(transcendentalFunction, a, b);

    if (abs(root - x) < TOLERANCE) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
};

// Test Secant Method
void testSecantMethod() {
    double a = 0;
    double b = 2;
    double root = CUBIC_ROOT;

    
    PRINT("Testing Secant Method");

    double x = SecantMethod(cubicPolynomial, a, b);

    if (abs(root - x) < TOLERANCE) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
};

// Test Fixed Point Method
void testFixedPointMethod() {
    double c = 1.5;
    double root = CUBIC_ROOT;

    PRINT("Testing Fixed Point Method");

    double x = FixedPointMethod(c, cubicPolynomialg, 1, 2);

    if (abs(root - x) < TOLERANCE) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
};

#endif
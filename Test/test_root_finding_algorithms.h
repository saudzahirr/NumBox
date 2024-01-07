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

    setColor(MAGENTA);
    PRINT("Testing Bolzano (Bisection) Method");
    setColor(DEFAULT);
    INFO_OUT("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    double x = BolzanosMethod(cubicPolynomial, a, b);
    setColor(YELLOW);
    INFO_OUT("f(" + to_string(x) + ") = " + to_string(cubicPolynomial(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        TEST_PASSED("Test Passed!");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
};

// Test Newton Raphson Method
void testNewtonRaphsonMethod() {
    double x0 = 1;
    double root = TRANSCENDENTAL_ROOT;

    setColor(MAGENTA);
    PRINT("Testing Newton-Raphson's Method");
    setColor(DEFAULT);
    INFO_OUT("Initial: x0 = " + to_string(x0));

    double x = NewtonRaphsonMethod(transcendentalFunction, x0);
    setColor(YELLOW);
    INFO_OUT("f(" + to_string(x) + ") = " + to_string(transcendentalFunction(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        TEST_PASSED("Test Passed!");
        setColor(DEFAULT);
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

    setColor(MAGENTA);
    PRINT("Testing Regula Falsi Method");
    setColor(DEFAULT);
    INFO_OUT("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    double x = RegulaFalsiMethod(transcendentalFunction, a, b);
    setColor(YELLOW);
    INFO_OUT("f(" + to_string(x) + ") = " + to_string(transcendentalFunction(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        TEST_PASSED("Test Passed!");
        setColor(DEFAULT);
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

    setColor(MAGENTA);
    PRINT("Testing Secant Method");
    setColor(DEFAULT);
    INFO_OUT("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    double x = SecantMethod(cubicPolynomial, a, b);
    setColor(YELLOW);
    INFO_OUT("f(" + to_string(x) + ") = " + to_string(cubicPolynomial(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        TEST_PASSED("Test Passed!");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
};

// Test Fixed Point Method
void testFixedPointMethod() {
    double c = 0;
    double root = CUBIC_ROOT;

    setColor(MAGENTA);
    PRINT("Testing Fixed Point Method");
    setColor(DEFAULT);
    INFO_OUT("Initial: c0 = " + to_string(c));

    double x = FixedPointMethod(c, cubicPolynomialg);
    setColor(YELLOW);
    INFO_OUT("f(" + to_string(x) + ") = " + to_string(cubicPolynomial(x)));

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        TEST_PASSED("Test Passed!");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
};

#endif
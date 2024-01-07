#ifndef TEST_NUMERICAL_INTEGRATION_H
#define TEST_NUMERICAL_INTEGRATION_H

#include <iostream>

#include "helpers.h"

#include "../Logger/logger.h"
#include "../Utils/utils.h"

#include "../Integration/trapezoid.h"
#include "../Integration/simpsons.h"
#include "../Integration/booles.h"
#include "../Integration/milne.h"
#include "../Integration/weddle.h"
#include "../Integration/riemann.h"
#include "../Integration/rombergs.h"
#include "../Integration/gaussian_quadrature.h"
#include "../Integration/monte_carlo.h"


// Trapezoid Rule
void testTrapezoidRule() {
    double integration;

    PRINT("Testing Trapezoid Rule");    

    integration = trapezoidRule(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Simpson's 1/3 Rule
void testSimpsonsRule() {
    double integration;

    PRINT("Testing Simpson's 1/3 Rule");

    integration = simpsonsRule(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Simpson's 3/8 Rule
void testSimpsonsThreeEighthRule() {
    double integration;

    PRINT("Testing Simpson's 3/8 Rule");

    integration = simpsonsThreeEighthRule(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");    
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Boole's Rule
void testBoolesRule() {
    double integration;

    PRINT("Testing Boole's Rule");

    integration = boolesRule(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");   
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Milne's Rule
void testMilnesRule() {
    double integration;

    PRINT("Testing Milne's Rule");

    integration = milnesRule(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Weddle's Rule
void testWeddlesRule() {
    double integration;

    PRINT("Testing Weddle's Rule");

    integration = weddlesRule(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Riemann's Summation
void testRiemannSum() {
    double integration;
    
    PRINT("Testing Riemann's Sum");

    integration = riemannSum(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Romberg's Method
void testRombergsMethod() {
    double integration;
    
    PRINT("Testing Romberg's Method");

    integration = rombergsMethod(gaussianFunction, -10, 10, 16);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Gaussian Quadrature Method
void testGaussianQuadratureMethod() {
    double integration;

    PRINT("Testing Gaussian Quadrature Method");    

    integration = gaussianQuadrature(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

// Monte-Carlo Method
void testMonteCarloMethod() {
    double integration;

    PRINT("Testing Monte-Carlo Method");

    integration = monteCarloIntegration(gaussianFunction, -100, 100, 1000000);

    DEBUG_OUT("Area under gaussian curve is " + to_string(integration));

    if (roundToNDecimals(integration, 8) == roundToNDecimals(sqrt(PI), 8)) {
        TEST_PASSED("Test Passed!");
    }
    else {
        ERROR_OUT("Test Failed!");
    }
}

#endif
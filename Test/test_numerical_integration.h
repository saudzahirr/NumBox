#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <math.h>


#include "../Logger/logger.h"
#include "../Utils/utils.h"


#include "../Integration/simpsons.h"


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

// Simpson's 1/3 Rule
void testSimpsonsRule() {
    double integration;

    setColor(MAGENTA);
    info("Testing Simpson's 1/3 Rule");
    setColor(DEFAULT);

    integration = simpsonsRule(gaussianFunction, -100, 100, 1000000, true);
    
    debug("Area under gaussian curve using Simpson's 1/3 rule is" + to_string(integration));

    if (roundToNDecimals(integration, 2) == roundToNDecimals(sqrt(PI), 2)) {
        setColor(GREEN);
        info("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        error("Test Failed!\n");
    }
}

#endif
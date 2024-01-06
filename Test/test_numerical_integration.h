#ifndef TEST_NUMERICAL_INTEGRATION_H
#define TEST_NUMERICAL_INTEGRATION_H

#include <iostream>

#include "helpers.h"

#include "../Logger/logger.h"
#include "../Utils/utils.h"

#include "../Integration/simpsons.h"


// Simpson's 1/3 Rule
void testSimpsonsRule() {
    double integration;

    setColor(MAGENTA);
    INFO_OUT("Testing Simpson's 1/3 Rule");
    setColor(DEFAULT);

    integration = simpsonsRule(gaussianFunction, -100, 100, 1000000, true);
    
    DEBUG_OUT("Area under gaussian curve using Simpson's 1/3 rule is " + to_string(integration));

    if (roundToNDecimals(integration, 2) == roundToNDecimals(sqrt(PI), 2)) {
        setColor(GREEN);
        INFO_OUT("Test Passed!\n");
        setColor(DEFAULT);
    }
    else {
        ERROR_OUT("Test Failed!\n");
    }
}

#endif
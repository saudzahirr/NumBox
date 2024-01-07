/*
 * Author: Saud Zahir
 * Date: December 24, 2023
 * Description: Secant method root finding algorithm.
 */

#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "secant_method.h"

using namespace std;


double SecantMethod(double (*f)(double), double x0, double x1) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Fixed-Point Method ...");
    DEBUG_OUT("Interval: [" + to_string(x0) + ", " + to_string(x1) + "]");

    int i;
    double x;
    for (i = 0; i < ITERATIONS; i++) {
        double Df = (f(x1) - f(x0)) / (x1 - x0);

        if (abs(Df) == 0) {
            ERROR_OUT("Critical point: " + formatPrecision(x) + ". Iteration stopped at " + to_string(i));
            return NAN;
        }

        // Secant Method.
        x = x1 - f(x1) / Df;
        
        x0 = x1;
        x1 = x;

        if (fabs(f(x)) < TOLERANCE) {
            DEBUG_OUT("The root of the function at " + to_string(i)
            + " number of iterations is: " + formatPrecision(x));

        time_req = clock() - time_req;
        INFO_OUT("Execution time for Secant Method: "
                + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

            return x;
        }
    }
    ERROR_OUT("Secant method failed to converge!");
    return NAN;
}


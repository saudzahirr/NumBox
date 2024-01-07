/*
 * Author: Saud Zahir
 * Date: December 28, 2023
 * Description: Fixed point method root finding algorithm.
 *  f(x) = x - g(x), then c_i is a root if f(c_i) = 0
 *  c_i = c_i-1 - g(c_i-1) 
 */

#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "fixed_point.h"

using namespace std;


double FixedPointMethod(double c, double (*g)(double), double a, double b) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Fixed-Point Method ...");
    DEBUG_OUT("Initial : x0 = " + formatPrecision(c));
    DEBUG_OUT("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    INFO_OUT("Applying Fixed-Point Theorem on g(x) ...");

    double dg_a = abs(Derivative(g, a, 1E-10));
    double dg_b = abs(Derivative(g, b, 1E-10));

    if (dg_a > 1 || dg_b > 1) {
        ERROR_OUT("Function g(x) failed Fixed-Point Theorem!");
    }

    for (int i = 0; i < ITERATIONS; ++i) {
        double c = g(c);

        if (abs(c - g(c)) == 0) {
            DEBUG_OUT("The root of the function at "
                    + to_string(i + 1) + " number of iterations is: "
                    + formatPrecision(c));

            time_req = clock() - time_req;
            INFO_OUT("Execution time for Fixed-Point Method: "
                    + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

            return c;
        }
    }

    ERROR_OUT("Fixed-point method did not converge within "
            + to_string(ITERATIONS) + " iterations");
    return NAN;
}

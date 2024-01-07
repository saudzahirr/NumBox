/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Newton-Raphson root finding algorithm.
 */

#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "newton_raphson.h"

using namespace std;


double NewtonRaphsonMethod(double (*f)(double), double x0) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Newton-Raphson Algorithm ...");
    DEBUG_OUT("Initial : x0 = " + formatPrecision(x0));

    int i = 0;
    double x = x0;

    for (i = 0; i < ITERATIONS; i++) {
        double df = Derivative(f, x, 1E-10);

        if (fabs(df) < 1E-8) {
            ERROR_OUT("Critical point: " + formatPrecision(x) + ". Iteration stopped at " + to_string(i));
            return NAN;
        }

        // Newton-Raphson Method.
        x = x - f(x) / df;

        if (abs(roundToNDecimals(f(x), 15)) == 0) {
            break;
        }
    }

    DEBUG_OUT("The root of the function at " + to_string(i)
            + " number of iterations is: " + formatPrecision(x));

    DEBUG_OUT("f(" + to_string(x) + ") = " + to_string(f(x)));

    time_req = clock() - time_req;
    INFO_OUT("Execution time for Newton-Raphson's Algorithm: "
            + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

    return x;
}

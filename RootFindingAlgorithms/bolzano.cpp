/*
 * Author: Saud Zahir
 * Date: December 22, 2023
 * Description: Bolzano's (Bisection) method root finding algorithm.
 */


#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "bolzano.h"

using namespace std;


double BolzanosMethod(double (*f)(double), double a, double b) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Bolzano's Bisection Algorithm ...");
    DEBUG_OUT("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    double p = 0.0;

    if (f(a) * f(b) < 0) {
        for (int i = 0; i < ITERATIONS; i++) {
            p = (a + b) / 2;
            if (f(a) * f(p) < 0) {
                b = p;
            }
            
            else if (f(p) * f(b) < 0) {
                a = p;
            }

            else if (round(f(a) * f(b)) == 0) {
                DEBUG_OUT("The root of the function at "
                        + to_string(i) + " number of iterations is: "
                        + formatPrecision(p));
                break;
            }

            else {
                WARNING_OUT("Bolzano's method did not converge!");
                break;
            }

        }
    }

    else {
        ERROR_OUT("Bolzano's method failed!");
    }

    DEBUG_OUT("f(" + to_string(p) + ") = " + to_string(f(p)));

    time_req = clock() - time_req;
    INFO_OUT("Execution time for Bolzano's bisection Algorithm: "
            + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

    return p;
}

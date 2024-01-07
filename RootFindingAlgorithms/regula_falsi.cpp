/*
 * Author: Saud Zahir
 * Date: December 23, 2023
 * Description: Regula Falsi (False Position) method root finding algorithm.
 */

#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "regula_falsi.h"

using namespace std;


double RegulaFalsiMethod(double (*f)(double), double a, double b) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Regula-Falsi Method ...");
    DEBUG_OUT("Interval: [" + to_string(a) + ", " + to_string(b) + "]");

    int i = 0;
    double p = 0.0;

    if (f(a) * f(b) < 0) {
        for (i = 0; i < ITERATIONS; i++) {
            // Regula-Falsi root update formula
            p = (a * f(b) - b * f(a)) / (f(b) - f(a));

            if (f(a) * f(p) < 0) {
                b = p;

                if (abs(roundToNDecimals(f(p), 15)) == 0) {
                    break;
                }
            }
            
            else if (f(p) * f(b) < 0) {
                a = p;

                if (abs(roundToNDecimals(f(p), 15)) == 0) {
                    break;
                }
            }

            else if (abs(roundToNDecimals(f(a) * f(b), 16)) == 0) {
                break;
            }

            else {
                WARNING_OUT("Regula-Falsi method did not converge!");
                break;
            }

        }

        DEBUG_OUT("The root of the function at "
                + to_string(i) + " number of iterations is: "
                + formatPrecision(p));
        
        DEBUG_OUT("f(" + to_string(p) + ") = " + to_string(f(p)));
        
        time_req = clock() - time_req;
        INFO_OUT("Execution time for Regula-Falsi Method: "
                + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

        return p;
    }

    else {
        ERROR_OUT("Regula-Falsi method failed!");
        return NAN;
    }
}

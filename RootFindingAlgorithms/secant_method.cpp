/*
 * Author: Saud Zahir
 * Date: December 24, 2023
 * Description: Secant method root finding algorithm.
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "secant_method.h"

using namespace std;


double SecantMethod(double (*f)(double), double x0, double x1) {
    int i;
    double x;
    for (i = 0; i < ITERATIONS; i++) {
        double Df = (f(x1) - f(x0)) / (x1 - x0);

        // Secant Method.
        x = x1 - f(x1) / Df;
        
        x0 = x1;
        x1 = x;

        if (fabs(f(x)) < TOLERANCE) {
            cout << "The root of the function at " << i << " number of iterations is: " << endl;
            cout << "x = " << x << endl;
            return x;
        }
    }
    cerr << "Secant method did not converge within the specified range." << endl;
    return NAN;
}


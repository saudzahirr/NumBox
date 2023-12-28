/*
 * Author: Saud Zahir
 * Date: December 28, 2023
 * Description: Fixed point method root finding algorithm.
 *  f(x) = x - g(x), then c_i is a root if f(c_i) = 0
 *  c_i = c_i-1 - g(c_i-1) 
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "fixed_point.h"

using namespace std;


double FixedPointMethod(double c, double (*g)(double)) {
    for (int i = 0; i < ITERATIONS; ++i) {
        double c = g(c);

        if (abs(c - g(c)) == 0) {
            cout << "Iterations: " << i + 1 << endl;
            return c;
        }
    }

    cerr << "Fixed-point method did not converge within " << ITERATIONS << " iterations." << endl;
    return NAN;
}

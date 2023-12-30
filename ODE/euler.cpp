/*
 * Author: Saud Zahir
 * Date: December 28, 2023
 * Description: Euler's method.
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "euler.h"

using namespace std;


double* EulersMethod(void (*f)(double, double*, double*), double* y0, double t0, int n, double h, double tmax) {
    double* y = new double[n];
    double t = t0;

    for (int iter = 0; iter < ITERATIONS; ++iter) {
        double dydt[n];
        f(t, y0, dydt);

        for (int i = 0; i < n; ++i) {
            y0[i] = y0[i] + h * dydt[i];
        }

        t += h;

        if (t == tmax) {
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        y[i] = y0[i];
    }

    return y;
}

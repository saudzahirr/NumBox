/*
 * Author: Saud Zahir
 * Date: December 27, 2023
 * Description: Trapezoidal rule.
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "trapezoid.h"

using namespace std;


double trapezoidRule(double (*f)(double), double a, double b, int n) {
    double h = h = (b - a) / n;

    double sum = f(a) + f(b);
    double x = 0.0;

    for (int i = 1; i < n; i++) {
        x = a + i * h;

        sum += 2 * f(x);
    }
    sum *= (h/2);

    return sum;
}

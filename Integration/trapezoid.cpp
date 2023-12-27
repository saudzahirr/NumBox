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


double trapezoidRule(double (*f)(double), double a, double b, int n, bool closed) {
    double h = 0.0;

    if (closed) {
        h = (b - a) / n;
    }

    else {
        h = (b - a) / (n + 2);
    }

    double sum = f(a) + f(b);
    double x = 0.0;

    for (int i = 1; i < n; i++) {
        if (closed) {
            x = a + i * h;
        }

        else {
            x = a + (i + 1) * h;
        }

        sum += 2 * f(x);
    }
    sum *= (h/2);

    return sum;
}

double gaussianFunction(double x) {
    return exp(-x * x);
}

int main() {
    double integration;
    integration = trapezoidRule(gaussianFunction, -100, 100, 1000000, true);
    cout << integration << endl;
    cout << sqrt(PI) << endl; 
    cout << abs(integration - sqrt(PI)) << endl;
}
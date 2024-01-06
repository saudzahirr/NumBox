/*
 * Author: Saud Zahir
 * Date: December 27, 2023
 * Description: Simpson's 1/3 and 3/8 rule.
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "simpsons.h"

using namespace std;


double simpsonsRule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;

    double sum = f(a) + f(b);
    double x = 0.0;

    for (int i = 1; i < n; i++) {
        x = a + i * h;

        if (i % 2 == 0) {
            sum += 2 * f(x);
        }

        else {
            sum += 4 * f(x);
        }
    }
    sum *= (h/3);

    return sum;
}

double simpsonsThreeEighthRule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;

    double sum = f(a) + f(b);
    double x = 0.0;

    for (int i = 1; i < n; i++) {
        x = a + i * h;

        if (i % 3 == 0) {
            sum += 2 * f(x);
        }

        else {
            sum += 3 * f(x);
        }
    }
    sum *= (3*h/8);

    return sum;
}

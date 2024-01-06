/*
 * Author: Saud Zahir
 * Date: January 06, 2024
 * Description: Milne's rule for numerical integration.
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include "../Utils/utils.h"
#include "milne.h"

using namespace std;

double milnesRule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }

    for (int i = 2; i < n - 1; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    sum *= h/3;

    return sum;
}

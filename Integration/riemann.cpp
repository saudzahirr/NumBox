/*
 * Author: Saud Zahir
 * Date: January 06, 2024
 * Description: Riemann summation for numerical integration.
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include "../Utils/utils.h"
#include "riemann.h"

using namespace std;


double riemannSum(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

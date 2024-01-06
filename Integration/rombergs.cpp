/*
 * Author: Saud Zahir
 * Date: December 27, 2023
 * Description: Romberg's method.
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "rombergs.h"
#include "trapezoid.h"

using namespace std;


double rombergsMethod(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / pow(2, n);

    double** R = new double*[n + 1];

    for (int i = 0; i <= n; ++i) {
        R[i] = new double[n + 1];
    }

    for (int i = 0; i <= n; i++) {
        R[i][0] = trapezoidRule(f, a, b, pow(2, i));
    }

    // Apply Richardson extrapolation to compute the remaining entries
    for (int m = 1; m <= n; m++) {
        for (int k = m; k<=n; k++) {
            R[k][m] = R[k][m - 1] + (1 / (pow(4, m) - 1)) * (R[k][m - 1] - R[k - 1][m - 1]);
        }
    }

    return R[n][n];
}

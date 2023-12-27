/*
 * Author: Saud Zahir
 * Date: December 27, 2023
 * Description: Gaussian curvature method.
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "gaussian_quadrature.h"

using namespace std;


double gaussianQuadrature(double (*f)(double), double a, double b, int n) {
    // Gaussian quadrature points and weights for the interval [-1, 1]
    const double x[] = {-0.5773502691896257, 0.5773502691896257};
    const double w[] = {1.0, 1.0};

    double integral = 0.0;

    // Transformation to the interval [a, b]
    double h = 0.5 * (b - a);
    double m = 0.5 * (b + a);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            // Gaussian quadrature formula
            double xi = m + h * x[j];
            integral += w[j] * f(xi);
        }
    }

    // Scale by the interval width
    integral *= h;

    return integral;
}

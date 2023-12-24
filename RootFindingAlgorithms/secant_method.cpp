/*
 * Author: Saud Zahir
 * Date: December 24, 2023
 * Description: Secant method root finding algorithm.
 */

#include <iostream>
#include <cmath>
#include "secant_method.h"

using namespace std;


double SecantMethod(double (*f)(double), double x0, double x1, int iterations, double tolerance = 1E-16) {
    double x;
    for (int i = 0; i < iterations; i++) {
        double Df = (f(x1) - f(x0)) / (x1 - x0);

        // Secant Method.
        x = x1 - f(x1) / Df;
        
        x0 = x1;
        x1 = x;

        if (fabs(f(x)) < tolerance) {
            cout << "Converged after " << i << " iterations." << endl;
            return x;
        }
    }
    cerr << "Secant method did not converge within the specified number of iterations." << endl;
    return NAN;
}




double function(double x) {
    return pow(x, 3) - x - 2; //  x * sin(2 * x) - pow(x, 3); //
}


int main() {
    int iterations = 1000;
    double tolerance = 1E-32;
    double x = SecantMethod(function, 0.2, 1, iterations, tolerance);
    cout << "x = " << x << endl;
    return 0;
}

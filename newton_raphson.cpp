/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Newton-Raphson root finding algorithm.
 */

#include <iostream>
#include <cmath>

using namespace std;


// Derivative of a function using Ab initio principle.
double calculateDerivative(double (*f)(double), double x, double h = 1E-10) {
    return (f(x + h) - f(x)) / h;
}


double NewtonRaphsonMethod(double (*f)(double), double x0, int iterations, double tolerance = 1E-16) {
    int i = 0;
    double x = x0;

    for (i = 0; i < iterations; i++) {
        double df = calculateDerivative(f, x);

        if (fabs(df) < 1e-8) {
            cout << x << " is a critical point, breaking iteration at " << i << "..." << endl;
            return NAN;
        }

        // Newton-Raphson Method.
        x = x - f(x) / df;

        if (floor(log10(f(x))) == floor(log10(tolerance))) {
            break;
        }
    }

    cout << "The root of the function at " << i << " number of iterations is: " << endl;
    cout << x << endl;

    return x;
}



double function(double x) {
    return x * sin(2 * x) - pow(x, 3);
}


int main() {
    int iterations = 200;
    double x0 = 1;

    NewtonRaphsonMethod(function, x0, iterations);
    return 0;
}

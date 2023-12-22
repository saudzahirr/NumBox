/*
 * Author: Saud Zahir
 * Date: December 23, 2023
 * Description: Bolzano's (Bisection) method root finding algorithm.
 */

#include <iostream>
#include <cmath>
#include "regula_falsi.h"

using namespace std;


double RegulaFalsiMethod(double (*f)(double), double a, double b, int iterations, double tolerance = 1E-16) {
    double p = 0.0;

    if (f(a) * f(b) < 0) {
        for (int i = 0; i < iterations; i++) {
            // Regula-Falsi root update formula
            p = (a * f(b) - b * f(a)) / (f(b) - f(a));

            if (f(a) * f(p) < 0) {
                b = p;
            }
            
            else if (f(p) * f(b) < 0) {
                a = p;
            }

            else if (round(f(a) * f(b)) == 0) {
                cout << "The root of the function at " << i << " number of iterations is: " << endl;
                cout << "x = " << p << endl;
                break;
            }

            else {
                cout << "Bolzano's method did not converge" << endl;
                break;
            }

        }
    }

    else {
        cerr << "Regula-Falsi method failed!" << endl;
    }

    return p;
}



double function(double x) {
    return x * sin(2 * x) - pow(x, 3); // pow(x, 3) - x - 2;
}


int main() {
    int iterations = 2000;
    double a = 0.5;
    double b = 1.0;

    double x = RegulaFalsiMethod(function, a, b, iterations);
    cout << "f(" << x <<") = " << function(x) << endl;
    return 0;
}

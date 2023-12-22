/*
 * Author: Saud Zahir
 * Date: December 22, 2023
 * Description: Bolzano's (Bisection) method root finding algorithm.
 */

#include <iostream>
#include <cmath>
#include "bolzano.h"
#include "../Utils/utils.h"

using namespace std;


double BolzanosMethod(double (*f)(double), double a, double b, int iterations, double tolerance = 1E-16) {
    double p = 0.0;

    if (f(a) * f(b) < 0) {
        for (int i = 0; i < iterations; i++) {
            p = (a + b) / 2;
            if (f(a) * f(p) < 0) {
                b = p;
            }
            
            else if (f(p) * f(b) < 0) {
                a = p;
            }

            else {
                cout << "The root of the function at " << i << " number of iterations is: " << endl;
                cout << "x = " << p << endl;
                break;
            }

        }
    }

    else {
        cerr << "Bolzano's method failed!" << endl;
    }

    return p;
}



double function(double x) {
    return pow(x, 3) - x - 2;
}


int main() {
    int iterations = 2000;
    double a = 0;
    double b = 2;

    double x = BolzanosMethod(function, a, b, iterations);
    cout << "f(" << x <<") = " << function(x) << endl;
    return 0;
}

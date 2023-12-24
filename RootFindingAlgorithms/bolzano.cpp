/*
 * Author: Saud Zahir
 * Date: December 22, 2023
 * Description: Bolzano's (Bisection) method root finding algorithm.
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "bolzano.h"

using namespace std;


double BolzanosMethod(double (*f)(double), double a, double b) {
    double p = 0.0;

    if (f(a) * f(b) < 0) {
        for (int i = 0; i < ITERATIONS; i++) {
            p = (a + b) / 2;
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
        cerr << "Bolzano's method failed!" << endl;
    }

    return p;
}

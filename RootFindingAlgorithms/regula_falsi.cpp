/*
 * Author: Saud Zahir
 * Date: December 23, 2023
 * Description: Regula Falsi (False Position) method root finding algorithm.
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "regula_falsi.h"

using namespace std;


double RegulaFalsiMethod(double (*f)(double), double a, double b) {
    int i = 0;
    double p = 0.0;

    if (f(a) * f(b) < 0) {
        for (i = 0; i < ITERATIONS; i++) {
            // Regula-Falsi root update formula
            p = (a * f(b) - b * f(a)) / (f(b) - f(a));

            if (f(a) * f(p) < 0) {
                b = p;

                if (abs(roundToNDecimals(f(p), 15)) == 0) {
                    break;
                }
            }
            
            else if (f(p) * f(b) < 0) {
                a = p;

                if (abs(roundToNDecimals(f(p), 15)) == 0) {
                    break;
                }
            }

            else if (abs(roundToNDecimals(f(a) * f(b), 16)) == 0) {
                break;
            }

            else {
                cout << "Regula-Falsi method did not converge" << endl;
                break;
            }

        }

        cout << "The root of the function at " << i << " number of iterations is: " << endl;
        cout << "x = " << p << endl;

        return p;
    }

    else {
        cerr << "Regula-Falsi method failed!" << endl;
        return NAN;
    }
}

/*
 * Author: Saud Zahir
 * Date: December 27, 2023
 * Description: Boole's rule.
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include "../Utils/utils.h"
#include "booles.h"

using namespace std;


double boolesRule(double (*f)(double), double a, double b, int n, bool closed) {
    double h = 0.0;

    if (closed) {
        h = (b - a) / n;
    }

    else {
        h = (b - a) / (n + 2);
    }

    double sum = 7 * (f(a) + f(b));
    double x = 0.0;

    for (int i = 1; i < n; i++) {
        if (closed) {
            x = a + i * h;
        }

        else {
            x = a + (i + 1) * h;
        }

        if (i % 4 == 1 || i % 4 == 3) {
            sum += 32 * f(x);
        }
        
        else if (i % 4 == 2) {
            sum += 12 * f(x);
        } 
        
        else {
            sum += 14 * f(x);
        }
    }
    sum *= (2*h/45);

    return sum;
}

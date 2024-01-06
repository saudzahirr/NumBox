/*
 * Author: Saud Zahir
 * Date: January 06, 2024
 * Description: Weddle's rule for numerical integration.
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include "../Utils/utils.h"
#include "weddle.h"

using namespace std;

double weddlesRule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;

    double sum = 3 * (f(a) + f(b));
    double x = 0.0;

    for (int i = 1; i < n; i++) {
        x = a + i * h;

        if (i % 6 == 1 || i % 6 == 5) {
            sum += 5 * f(x);
        }
        
        else if (i % 6 == 2 || i % 6 == 4) {
            sum += 6 * f(x);
        } 
        
        else {
            sum += f(x);
        }
    }
    sum *= (3*h/10);

    return sum;
}

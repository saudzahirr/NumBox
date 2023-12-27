/*
 * Author: Saud Zahir
 * Date: December 27, 2023
 * Description: Monte-Carlo Integration.
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include "../Utils/utils.h"
#include "monte_carlo.h"

using namespace std;


double monteCarloIntegration(double (*f)(double), double a, double b, int n) {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        // Generate a random point in the interval [a, b]
        double randomPoint = a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);

        // Evaluate the function at the random point and add to the sum
        sum += f(randomPoint);
    }

    double average = sum / n;

    return (b - a) * average;
}

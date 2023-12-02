#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

// Derivative of a function using Ab initio principle.
double calculateDerivative(double (*f)(double), double x, double h = 1E-10);

// Newton-Raphson Method to find the root of a function.
double NewtonRaphsonMethod(double (*f)(double), double x0, int iterations, double tolerance = 1E-16);

// Function to be evaluated.
double function(double x);

#endif

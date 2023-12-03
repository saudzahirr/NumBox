#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

// Derivative of a function using Ab initio principle.
double calculateDerivative(double (*f)(double), double x, double h);

// Newton-Raphson Method to find the root of a function.
double NewtonRaphsonMethod(double (*f)(double), double x0, int iterations, double tolerance);

// Function to be evaluated.
double function(double x);

#endif

#ifndef BOLZANO_H
#define BOLZANO_H

/**
 * Bolzano's Method for root finding.
 *
 * @param f The function for which the root is to be found.
 * @param a The lower bound of the interval.
 * @param b The upper bound of the interval.
 * @return The approximate root of the function within the specified interval.
 */
double BolzanosMethod(double (*f)(double), double a, double b);

#endif

#ifndef REGULA_FALSI_H
#define REGULA_FALSI_H

/**
 * Regula Falsi (False Position) Method for root finding.
 *
 * @param f The function for which the root is to be found.
 * @param a The lower bound of the interval.
 * @param b The upper bound of the interval.
 *
 * @return The approximate root of the function within the specified interval.
 */
double RegulaFalsiMethod(double (*f)(double), double a, double b);

#endif

#ifndef SIMPSONS_H
#define SIMPSONS_H

double simpsonsRule(double (*f)(double), double a, double b, int n, bool closed);

double simpsonsThreeEighthRule(double (*f)(double), double a, double b, int n, bool closed);


#endif
#ifndef SECANTMETHOD_H
#define SECANTMETHOD_H

double SecantMethod(double (*f)(double), double x0, double x1, int iterations, double tolerance);

#endif
#ifndef EULER_H
#define EULER_H

double* EulersMethod(void (*f)(double, double*, double*), double* y0, double t0, int n, double h, double tmax);


#endif
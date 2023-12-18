#ifndef UTILS
#define UTILS

// Matrix multiplication.
double* multiplyMatrices(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB);

// Derivative of a function using Ab initio principle.
double calculateDerivative(double (*f)(double), double x, double h);

#endif

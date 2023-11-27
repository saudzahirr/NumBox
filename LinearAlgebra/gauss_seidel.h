#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

/**
 * Solves a linear system of equations using the Gauss-Seidel iterative algorithm.
 *
 * @param A      Coefficient matrix of the linear system.
 * @param b      Output vector of the linear system.
 * @param x      Initial guess for the solution.
 * @param n      Size of the linear system.
 * @return       Pointer to the solution vector. The memory is allocated dynamically.
 */
double* GaussSeidelMethod(double** A, double* b, double* x, int n);

#endif  // GAUSS_SEIDEL_H

#ifndef WEIGHTED_JACOBI_H
#define WEIGHTED_JACOBI_H

/**
 * Solves a linear system of equations using the Weighted-Jacobi iterative algorithm.
 *
 * @param A      Coefficient matrix of the linear system.
 * @param b      Output vector of the linear system.
 * @param x      Initial guess for the solution.
 * @param n      Size of the linear system.
 * @return       Pointer to the solution vector. The memory is allocated dynamically.
 */
double* WeightedJacobiMethod(double** A, double* b, double* x, int n);

#endif  // WEIGHTED_JACOBI_H

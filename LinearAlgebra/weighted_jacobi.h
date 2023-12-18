#ifndef WEIGHTED_JACOBI_H
#define WEIGHTED_JACOBI_H

/**
 * @brief Weighted Jacobi Method
 * 
 * This method solves a linear system of equations (Ax = b) using Weighted Jacobi algorithm.
 *
 * @param A      Coefficient matrix of the linear system.
 * @param b      Output vector of the linear system.
 * @param x      Initial guess for the solution.
 * @param w      Weight paramater for algorithm.
 * @param n      Size of the linear system.
 * @return       Pointer to the solution vector. The memory is allocated dynamically.
 */
double* WeightedJacobiMethod(double** A, double* b, double* x, double w, int n);

#endif  // WEIGHTED_JACOBI_H

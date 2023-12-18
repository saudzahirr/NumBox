#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

/**
 * @brief Gauss Seidel Method
 * 
 * This method solves a linear system of equations (Ax = b) using Gauss-Seidel algorithm.
 *
 * @param A Coefficient matrix of the linear system.
 * @param b Right-hand side vector of the linear system.
 * @param x Initial guess for the solution (input) and the resulting solution (output).
 * @param n Size of the linear system.
 * @return Pointer to the converged solution vector. The memory is allocated dynamically.
 */
double* GaussSeidelMethod(double** A, double* b, double* x, int n);

#endif // GAUSS_SEIDEL_H

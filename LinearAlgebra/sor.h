#ifndef SOR_H
#define SOR_H

/**
 * @brief Successive over-relaxation (SOR)
 * 
 * This method solves a linear system of equations (Ax = b) using Gauss-Seidel algorithm.
 *
 * @param A Coefficient matrix of the linear system.
 * @param b Right-hand side vector of the linear system.
 * @param x Initial guess for the solution (input) and the resulting solution (output).
 * @param w weight parameter.
 * @param n Size of the linear system.
 * @return Pointer to the converged solution vector. The memory is allocated dynamically.
 */
double* SuccessiveOverRelaxation(double** A, double* b, double* x, double w, int n);

#endif // SOR_H

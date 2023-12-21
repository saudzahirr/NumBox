#ifndef SOR_H
#define SOR_H

/**
 * @brief Successive Over-Relaxation (SOR) method to solve a linear system of equations.
 *
 * @param A Coefficient matrix of the linear system.
 * @param b Right-hand side vector of the linear system.
 * @param x Initial guess for the solution (input) and the resulting solution (output).
 * @param w Relaxation parameter.
 * @param n Size of the linear system.
 * @return Pointer to the converged solution vector. The memory is allocated dynamically.
 */
double* SuccessiveOverRelaxation(double** A, double* b, double* x, double w, int n);

#endif // SOR_H

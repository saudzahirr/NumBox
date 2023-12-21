#ifndef CHOLESKY_H
#define CHOLESKY_H

/**
 * @brief Cholesky Decomposition Method.
 *
 * This method decomposes a symmetric positive-definite matrix A (A = LL^T) into a lower
 * triangular matrix (L) and its transpose (L^T) using the Cholesky decomposition algorithm.
 *
 * @param A Symmetric positive-definite matrix to be decomposed.
 *          Input matrix (A) and output lower triangular matrix (L).
 * @param L Lower triangular matrix (output).
 * @param n Size of the matrix.
 */
void choleskyDecomposition(double** A, double**& L, int n);

#endif // CHOLESKY_H

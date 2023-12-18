#ifndef CROUT_H
#define CROUT_H

/**
 * @brief Crout Decomposition Method.
 *
 * This method decomposes a matrix A (A = LU) into a lower triangular matrix (L) and an
 * upper triangular matrix (U) using the Crout LU decomposition algorithm.
 *
 * @param A Matrix to be decomposed. Input matrix (A) and output matrices (L and U).
 * @param L Lower triangular matrix (output).
 * @param U Upper triangular matrix (output).
 * @param n Size of the matrix.
 */
void croutLU(double** A, double**& L, double**& U, int n);

#endif // CROUT_H

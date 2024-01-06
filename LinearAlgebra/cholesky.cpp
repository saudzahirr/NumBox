/*
 * Author: Saud Zahir
 * Date: December 18, 2023
 * Description: Cholesky LU Decomposition Method decomposes a matrix A (A = LL*) into
 * a lower triangular matrix (L).
 */

#include <iostream>
#include <cmath>
#include "../Utils/utils.h"
#include "cholesky.h"

using namespace std;


void choleskyDecomposition(double** A, double**& L, int n) {
    L = new double*[n];
    for (int i = 0; i < n; ++i) {
        L[i] = new double[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            L[i][j] = 0.0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0.0;

            if (i == j) {
                for (int k = 0; k < j; ++k) {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; ++k) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

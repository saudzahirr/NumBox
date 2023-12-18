/*
 * Author: Saud Zahir
 * Date: December 17, 2023
 * Description: Crout Decomposition Method decomposes a matrix A (A = LU) into
 * a lower triangular matrix (L), an upper triangular matrix (U).
 */

#include <iostream>
#include "crout.h"
#include "../Utils/utils.h"

using namespace std;

void croutLU(double** A, double**& L, double**& U, int n) {
    // Initialize L and U matrices
    L = new double*[n];
    U = new double*[n];
    for (int i = 0; i < n; ++i) {
        L[i] = new double[n];
        U[i] = new double[n];
    }

    // Perform Crout LU decomposition
    for (int j = 0; j < n; j++) {
		for (int i = j; i < n; i++) {
			double sum = 0.0;
			for (int k = 0; k < j; k++) {
				sum = sum + L[i][k] * U[k][j];	
			}
			L[i][j] = A[i][j] - sum;
		}

		for (int i = j; i < n; i++) {
			double sum = 0.0;
			for(int k = 0; k < j; k++)
				sum = sum + L[j][k] * U[k][i];
			U[j][i] = (A[j][i] - sum) / L[j][j];
		}
	}
}

void displayMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int n = 4;

    double** A = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    // Define a matrix (4D array)
    A[0][0] = 10.0; A[0][1] = -1.0; A[0][2] = 2.0; A[0][3] = 0;
    A[1][0] = -1.0; A[1][1] = 11.0; A[1][2] = -1.0; A[1][3] = 3.0;
    A[2][0] = 2.0; A[2][1] = -1.0; A[2][2] = 10.0; A[2][3] = -1.0;
    A[3][0] = 0.0; A[3][1] = 3.0; A[3][2] = -1.0; A[3][3] = 8.0;

    double** L, ** U;
    croutLU(A, L, U, n);

    // Display the results
    cout << "Matrix A:" << endl;
    displayMatrix(A, n, n);

    cout << "\nMatrix L:" << endl;
    displayMatrix(L, n, n);

    cout << "\nMatrix U:" << endl;
    displayMatrix(U, n, n);

    // Clean up memory
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] L[i];
        delete[] U[i];
    }
    delete[] A;
    delete[] L;
    delete[] U;

    return 0;
}

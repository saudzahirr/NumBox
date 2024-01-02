#include <iostream>
#include <cmath>
#include <iomanip>
#include "../LinearAlgebra/thomas.h"
#include "../Utils/utils.h"

using namespace std;

// Function to generate Crank-Nicolson matrices A and B
void crankNicolsonMatrices(double alpha, double k, double h, int N, double**& A, double**& B) {
    // Define constants
    double a = alpha * k / (h * h);

    // Set up matrices A and B
    for (int i = 0; i < N; ++i) {
        A[i][i] = 1.0 + 2.0 * a;
        B[i][i] = 1.0 - 2.0 * a;

        if (i > 0) {
            A[i][i - 1] = -a;
            B[i][i - 1] = a;
        }

        if (i < N - 1) {
            A[i][i + 1] = -a;
            B[i][i + 1] = a;
        }
    }
}

// Function to deallocate memory for matrices
void deallocateMatrices(double** A, double** B, int N) {
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
}

int main() {
    // Example usage
    double alpha = 0.1;  // Diffusion coefficient
    double k = 0.01;    // Time step
    double h = 0.1;     // Spatial step size
    int N = 10;         // Number of spatial grid points

    // Matrices A and B
    double** A = new double*[N];

    for (int i = 0; i < N; ++i) {
        A[i] = new double[N];
    }
    double** B = new double*[N];
    for (int i = 0; i < N; ++i) {
        B[i] = new double[N];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = 0.0;
            B[i][j] = 0.0;
        }
    }

    // Generate Crank-Nicolson matrices
    crankNicolsonMatrices(alpha, k, h, N, A, B);

    // Display matrices (for demonstration purposes)
    cout << "Matrix A:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(8) << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nMatrix B:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(8) << B[i][j] << " ";
        }
        cout << "\n";
    }

    // Deallocate memory for matrices
    deallocateMatrices(A, B, N);

    return 0;
}

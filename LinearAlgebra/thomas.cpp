/*
 * Author: Saud Zahir
 * Date: November 12, 2023
 * Description: Thomas algorithm to solve tridiagonal linear system of equations.
 */


#include "thomas.h"

using namespace std;

double* thomasAlgorithm(double** A, double* b, int n) {
    // Allocate memory for the solution vector x
    double* x = new double[n];

    // Forward elimination
    for (int i = 1; i < n; ++i) {
        double factor = A[i][i-1] / A[i-1][i-1];
        A[i][i] -= factor * A[i-1][i];
        b[i] -= factor * b[i-1];
    }

    // Backward substitution
    x[n-1] = b[n-1] / A[n-1][n-1];
    for (int i = n-2; i >= 0; --i) {
        x[i] = (b[i] - A[i][i+1] * x[i+1]) / A[i][i];
    }

    return x;
}

// int main() {
//     const int n = 4;

//     // Tridiagonal matrix A (assuming A is a banded matrix)
//     double** A = new double*[n];
//     for (int i = 0; i < n; ++i) {
//         A[i] = new double[n];
//     }

//     A[0][0] = 10.0; A[0][1] = -1.0; A[0][2] = 0.0; A[0][3] = 0.0;
//     A[1][0] = -1.0; A[1][1] = 11.0; A[1][2] = -1.0; A[1][3] = 0.0;
//     A[2][0] = 0.0; A[2][1] = -1.0; A[2][2] = 10.0; A[2][3] = -1.0;
//     A[3][0] = 0.0; A[3][1] = 0.0; A[3][2] = -1.0; A[3][3] = 8.0;

//     double b[n] = {6.0, 25.0, -11.0, 15.0};


//     // Solve the system using Thomas algorithm
//     double* x = thomasAlgorithm(A, b, n);

//     // x = {372/449, 1026/449, -311/449, 803/449}

//     // Print the solution vector x
//     cout << "Solution vector x:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cout << x[i] << " ";
//     }
//     cout << endl;

//     // Clean up memory
//     delete[] x;
//     for (int i = 0; i < n; ++i) {
//         delete[] A[i];
//     }
//     delete[] A;

//     return 0;
// }
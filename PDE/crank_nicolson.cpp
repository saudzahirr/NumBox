/*
 * Author: Saud Zahir
 * Date: January 06, 2024
 * Description: Crank-Nicolson's method.
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "../LinearAlgebra/gauss_seidel.h"
#include "../Utils/utils.h"
#include "crank_nicolson.h"

using namespace std;

// Function to generate Crank-Nicolson matrices A and B
void crankNicolsonMatrices2D(double alpha, double k, double hx, double hy, int Nx, int Ny, double**& A, double**& B) {
    // Define constants
    double ax = alpha * k / (hx * hx);
    double ay = alpha * k / (hy * hy);

    // Set up matrices A and B
    for (int i = 0; i < Nx; ++i) {
        for (int j = 0; j < Ny; ++j) {
            int idx = i * Ny + j;

            A[idx][idx] = 1.0 + 2.0 * ax + 2.0 * ay;
            B[idx][idx] = 1.0 - 2.0 * ax - 2.0 * ay;

            if (i > 0) {
                A[idx][idx - Ny] = -ax;
                B[idx][idx - Ny] = ax;
            }

            if (i < Nx - 1) {
                A[idx][idx + Ny] = -ax;
                B[idx][idx + Ny] = ax;
            }

            if (j > 0) {
                A[idx][idx - 1] = -ay;
                B[idx][idx - 1] = ay;
            }

            if (j < Ny - 1) {
                A[idx][idx + 1] = -ay;
                B[idx][idx + 1] = ay;
            }
        }
    }
}

// Function to write matrices A and B to a file
void writeMatricesToFile(const char* filename, double** matrix, int rows, int cols) {
    ofstream outFile(filename);

    if (outFile.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                outFile << setw(4) << matrix[i][j] << " ";
            }
            outFile << "\n";
        }

        outFile.close();
        cout << "Matrices written to file: " << filename << endl;
    } else {
        cerr << "Unable to open the file for writing." << endl;
    }
}

// Function to write solution to a file
void writeSolutionToFile(const char* filename, double* u, int Nx, int Ny) {
    ofstream outFile(filename);

    if (outFile.is_open()) {
        for (int i = 0; i < Nx; ++i) {
            for (int j = 0; j < Ny; ++j) {
                int idx = i * Ny + j;
                outFile << "u[" << i << "]" << "[" << j << "] = " << u[idx] << endl;
            }
            outFile << endl;
        }

        outFile.close();
        cout << "Solution written to file: " << filename << endl;
    } else {
        cerr << "Unable to open the file for writing." << endl;
    }
}

void solveHeatEquation2D(double alpha, double k, double hx, double hy, int Nx, int Ny, double*& u) {
    // Time parameters
    double tFinal = 1.0;
    int Nt = static_cast<int>(tFinal / k);

    // Matrices A and B
    double** A = new double*[Nx * Ny];
    for (int i = 0; i < Nx * Ny; ++i) {
        A[i] = new double[Nx * Ny];
    }

    double** B = new double*[Nx * Ny];
    for (int i = 0; i < Nx * Ny; ++i) {
        B[i] = new double[Nx * Ny];
    }

    // Initialize matrices A and B
    for (int i = 0; i < Nx * Ny; ++i) {
        for (int j = 0; j < Nx * Ny; ++j) {
            A[i][j] = 0.0;
            B[i][j] = 0.0;
        }
    }

    // Generate Crank-Nicolson matrices
    crankNicolsonMatrices2D(alpha, k, hx, hy, Nx, Ny, A, B);

    // Initial condition: Set u(x, y, t=0) = sin(pi*x)*sin(pi*y)
    for (int i = 0; i < Nx; ++i) {
        for (int j = 0; j < Ny; ++j) {
            int idx = i * Ny + j;
            double x = i * hx;
            double y = j * hy;
            u[idx] = sin(PI * x) * sin(PI * y);
        }
    }

    // Time-stepping loop
    for (int tStep = 1; tStep <= Nt; ++tStep) {
        // Flatten the 2D array before passing to GaussSeidelMethod
        double* flattenedU = new double[Nx * Ny];
        for (int i = 0; i < Nx * Ny; ++i) {
            flattenedU[i] = u[i];
        }

        double* b = vectorProduct(B, Nx * Ny, Nx * Ny, flattenedU, Nx * Ny);

        double* uVector = GaussSeidelMethod(A, b, flattenedU, Nx * Ny);

        // Write solution to file at each time step
        writeSolutionToFile("solution.txt", uVector, Nx, Ny);

        // Deallocate memory for vectors b and uVector
        delete[] b;
        delete[] uVector;
        delete[] flattenedU;
    }

    // Deallocate memory for matrices A and B
    for (int i = 0; i < Nx * Ny; ++i) {
        delete[] A[i];
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
}

int main() {
    double alpha = 0.1;  // Diffusion coefficient
    double k = 0.01;    // Time step
    double hx = 0.1;    // Spatial step size in x
    double hy = 0.1;    // Spatial step size in y
    int Nx = 32;        // Number of spatial grid points in x
    int Ny = 32;        // Number of spatial grid points in y

    // Matrix A and B
    double** A = new double*[Nx * Ny];
    for (int i = 0; i < Nx * Ny; ++i) {
        A[i] = new double[Nx * Ny];
    }

    double** B = new double*[Nx * Ny];
    for (int i = 0; i < Nx * Ny; ++i) {
        B[i] = new double[Nx * Ny];
    }

    crankNicolsonMatrices2D(alpha, k, hx, hy, Nx, Ny, A, B);

    writeMatricesToFile("matrix_A.txt", A, Nx * Ny, Nx * Ny);
    writeMatricesToFile("matrix_B.txt", B, Nx * Ny, Nx * Ny);

    double* u = new double[Nx * Ny];

    solveHeatEquation2D(alpha, k, hx, hy, Nx, Ny, u);

    cleanMatrix(A, Nx * Ny);
    cleanMatrix(B, Nx * Ny);
    delete[] u;

    return 0;
}

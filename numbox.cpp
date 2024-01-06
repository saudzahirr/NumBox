#include <iostream>
#include <math.h>
#include <ctime>

#include "Logger/logger.h"
#include "Utils/utils.h"

#include "RootFindingAlgorithms/bolzano.h"
#include "RootFindingAlgorithms/newton_raphson.h"
#include "RootFindingAlgorithms/regula_falsi.h"
#include "RootFindingAlgorithms/secant_method.h"

#include "LinearAlgebra/cholesky.h"
#include "LinearAlgebra/crout.h"
#include "LinearAlgebra/doolittle.h"
#include "LinearAlgebra/gauss_seidel.h"
#include "LinearAlgebra/jacobi.h"
#include "LinearAlgebra/rayleigh_quotient.h"
#include "LinearAlgebra/sor.h"
#include "LinearAlgebra/von_mises.h"
#include "LinearAlgebra/weighted_jacobi.h"


using namespace std;

struct LinearAlgebra {
    using Method = double* (*)(double**, double*, double*, int);
    static Method GAUSS_SEIDEL;
    static Method JACOBI;
    // static Method SOR;
    // static Method WEIGHTED_JACOBI;
};

LinearAlgebra::Method LinearAlgebra::GAUSS_SEIDEL = &GaussSeidelMethod;
LinearAlgebra::Method LinearAlgebra::JACOBI = &JacobiMethod;
// LinearAlgebra::Method LinearAlgebra::SOR = &SuccessiveOverRelaxation;
// LinearAlgebra::Method LinearAlgebra::WEIGHTED_JACOBI = &WeightedJacobiMethod;

class LinearSystemOfEquations {
public:
    LinearSystemOfEquations(double** A, double* B, int size)
        : A(A), B(B), size(size), X(new double[size]) {}

    ~LinearSystemOfEquations() {
        delete[] X;
    }

    double* Solve(LinearAlgebra::Method method) {
        return method(A, B, X, size);
    }

private:
    double** A;
    double* B;
    int size;
    double* X;
};


class EigenValueProblem {
public:
    EigenValueProblem(double** A, int size) : A(A), size(size), eigenvalues(nullptr), eigenvectors(nullptr) {
        // Allocate memory for eigenvalues and eigenvectors
        eigenvalues = new double[size];
        eigenvectors = new double*[size];
        for (int i = 0; i < size; ++i) {
            eigenvectors[i] = new double[size];
        }
    }

    ~EigenValueProblem() {
        // Deallocate memory
        delete[] eigenvalues;
        for (int i = 0; i < size; ++i) {
            delete[] eigenvectors[i];
        }
        delete[] eigenvectors;
    }

    void Solve() {
        // Power Iteration with Deflation
        for (int i = 0; i < size; i++) {
            double* x = VonMisesIterationMethod(A, size);
            double c = RayleighQuotient(A, x, size);
            cout << "Eigenvalue: " << c << endl;
            cout << "Eigenvector: ";
            displayVector(x, size);
            cout << endl;
            A = matrixSub(A, matrixScalarProduct(outerProduct(x, size, x, size), size, size, c), size, size);
        }
    }

private:
    double** A;
    int size;
    double* eigenvalues;
    double** eigenvectors;
};




int main() {
    const int n = 4;

    double** A = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    A[0][0] = 10.0; A[0][1] = -1.0; A[0][2] = 2.0; A[0][3] = 0;
    A[1][0] = -1.0; A[1][1] = 11.0; A[1][2] = -1.0; A[1][3] = 3.0;
    A[2][0] = 2.0; A[2][1] = -1.0; A[2][2] = 10.0; A[2][3] = -1.0;
    A[3][0] = 0.0; A[3][1] = 3.0; A[3][2] = -1.0; A[3][3] = 8.0;
    double b[n] = {6.0, 25.0, -11.0, 15.0};

    LinearSystemOfEquations linearSystem(A, b, n);

    clock_t time_req;
    time_req = clock();

    double* x = linearSystem.Solve(LinearAlgebra::GAUSS_SEIDEL);
    displayVector(x, n);
    
    time_req = clock() - time_req;
    INFO_OUT("Execution time for solving linear system of equation using Gauss-Seidel algorithm: " + to_string(time_req/CLOCKS_PER_SEC) + " seconds");

    time_req = clock();
    EigenValueProblem eigenProblem(A, n);
    eigenProblem.Solve();
    time_req = clock() - time_req;
	DEBUG_OUT("Execution time for calculating eigenvalues and eigenvectors using Von Mises iteration and Rayleigh quotient algorithm: " + to_string(time_req/CLOCKS_PER_SEC) + " seconds");

    cleanMatrix(A, n);

    return 0;
}
#include <iostream>
#include <math.h>
#include <windows.h>

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
    static Method SOR;
    static Method WEIGHTED_JACOBI;
};

class LinearSystemOfEquations {
public:
    LinearSystemOfEquations(double** A, double* B, int size)
        : A(A), B(B), size(size), X(new double[size]) {}

    ~LinearSystemOfEquations() {
        delete[] X;
    }

    // Solve the linear system using the specified method
    double* Solve(LinearAlgebra::Method method) {
        return method(A, B, X, size);
    }

private:
    double** A;    // Coefficient matrix
    double* B;     // Right-hand side vector
    int size;      // Size of the system
    double* X;     // Solution vector
};

int main() {
    return 0;
}
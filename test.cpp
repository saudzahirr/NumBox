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

#define CUBIC_ROOT 1.5213797068045675696040808322544385144283898284279039090904980154
#define TRANSCENDENTAL_ROOT 0.966876881413510626654237834545340028268547068798811

double cubicPolynomial(double x) {
    return pow(x, 3) - x - 2;
};

double transcendentalFunction(double x) {
    return x * sin(2 * x) - pow(x, 3);
};

double** createMatrix() {
    const int n = 4;
    double** A = new double*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    return A;
};

void initializeMatrix(double** A) {
    const int n = 4;
    const double MATRIX_A[n][n] = {
        {10.0, -1.0, 2.0, 0.0},
        {-1.0, 11.0, -1.0, 3.0},
        {2.0, -1.0, 10.0, -1.0},
        {0.0, 3.0, -1.0, 8.0}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = MATRIX_A[i][j];
        }
    }
};


// Console display
enum ConsoleColor {
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    GREEN = FOREGROUND_GREEN,
    CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED = FOREGROUND_RED,
    MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    DEFAULT = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};

void setColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
};


void testBolzanoMethod();
void testNewtonRaphsonMethod();
void testRegulaFalsiMethod();
void testSecantMethod();

void testCholeskyDecomposition();
void testCroutDecomposition();
void testDoolittleDecomposition();

void testGaussSeidelMethod();
void testJacobiMethod();
void testSORMethod();
void testWeightedJacobiMethod();

void testVonMisesMethod();


int main() {
    setColor(BLUE);
    cout << "Testing Root Finding Algorithms...\n" << endl;
    setColor(DEFAULT);
    testBolzanoMethod();
    testNewtonRaphsonMethod();
    testRegulaFalsiMethod();
    testSecantMethod();

    setColor(BLUE);
    cout << "Testing LU Decomposition Algorithms...\n" << endl;
    setColor(DEFAULT);
    testCholeskyDecomposition();
    testCroutDecomposition();
    testDoolittleDecomposition();

    setColor(BLUE);
    cout << "Testing Numerical Linear Algebra Algorithms...\n" << endl;
    setColor(DEFAULT);
    testGaussSeidelMethod();
    testJacobiMethod();
    testSORMethod();
    testWeightedJacobiMethod();

    testVonMisesMethod();

    return 0;
}


// Test Bolzano's Method
void testBolzanoMethod() {
    double a = 0;
    double b = 2;
    double root = CUBIC_ROOT;

    setColor(MAGENTA);
    cout << "Testing Bolzano (Bisection) Method" << endl;
    setColor(DEFAULT);
    cout << "Interval: [" << a << ", " << b << "]" << endl;

    double x = BolzanosMethod(cubicPolynomial, a, b);
    setColor(YELLOW);
    cout << "f(" << x <<") = " << cubicPolynomial(x) << endl;

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }
};

// Test Newton Raphson Method
void testNewtonRaphsonMethod() {
    double x0 = 1;
    double root = TRANSCENDENTAL_ROOT;

    setColor(MAGENTA);
    cout << "Testing Newton-Raphson's Method" << endl;
    setColor(DEFAULT);
    cout << "Initial guess x0 = 1" << endl;

    double x = NewtonRaphsonMethod(transcendentalFunction, x0);
    setColor(YELLOW);
    cout << "f(" << x <<") = " << transcendentalFunction(x) << endl;

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }
};

// Test Regula Falsi Method
void testRegulaFalsiMethod() {
    double a = 0.5;
    double b = 1;
    double root = TRANSCENDENTAL_ROOT;

    setColor(MAGENTA);
    cout << "Testing Regula-Falsi Method" << endl;
    setColor(DEFAULT);
    cout << "Interval: [" << a << ", " << b << "]" << endl;

    double x = RegulaFalsiMethod(transcendentalFunction, a, b);
    setColor(YELLOW);
    cout << "f(" << x <<") = " << transcendentalFunction(x) << endl;

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }
};

// Test Secant Method
void testSecantMethod() {
    double a = 0;
    double b = 2;
    double root = CUBIC_ROOT;

    setColor(MAGENTA);
    cout << "Testing Secant Method" << endl;
    setColor(DEFAULT);
    cout << "Interval: [" << a << ", " << b << "]" << endl;

    double x = SecantMethod(cubicPolynomial, a, b);
    setColor(YELLOW);
    cout << "f(" << x <<") = " << cubicPolynomial(x) << endl;

    if (abs(root - x) < TOLERANCE) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }
};

// Test Cholesky Decomposition
void testCholeskyDecomposition() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    cout << "Testing Cholesky LU Decomposition" << endl;
    setColor(DEFAULT);

    double** L;
    choleskyDecomposition(A, L, n);

    setColor(YELLOW);
    cout << "A = \n";    
    displayMatrix(A, n, n, 8);

    setColor(YELLOW);
    cout << "\nL = \n";
    displayMatrix(L, n, n, 8);

    if (equalMatrices(A, matrixProduct(L, n, n, Transpose(L, n, n), n, n), n, n)) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }

    // Clean up memory
    cleanMatrix(A, n);
    cleanMatrix(L, n);
};

// Test Crout Decomposition
void testCroutDecomposition() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    cout << "Testing Crout LU Decomposition" << endl;
    setColor(DEFAULT);

    double** L, ** U;
    croutLU(A, L, U, n);

    setColor(YELLOW);
    cout << "A = \n";
    displayMatrix(A, n, n, 8);

    setColor(YELLOW);
    cout << "\nL = \n";
    displayMatrix(L, n, n, 8);

    setColor(YELLOW);
    cout << "\nU = \n";
    displayMatrix(U, n, n, 8);

    if (equalMatrices(A, matrixProduct(L, n, n, U, n, n), n, n)) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }

    // Clean up memory
    cleanMatrix(A, n);
    cleanMatrix(L, n);
    cleanMatrix(U, n);
};

// Test Doolittle Decomposition
void testDoolittleDecomposition() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    cout << "Testing Doolittle LU Decomposition" << endl;
    setColor(DEFAULT);

    double** L, ** U;
    doolittleLU(A, L, U, n);

    setColor(YELLOW);
    cout << "A = \n";
    displayMatrix(A, n, n, 8);

    setColor(YELLOW);
    cout << "\nL = \n";
    displayMatrix(L, n, n, 8);

    setColor(YELLOW);
    cout << "\nU = \n";
    displayMatrix(U, n, n, 8);

    if (equalMatrices(A, matrixProduct(L, n, n, U, n, n), n, n)) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }

    // Clean up memory
    cleanMatrix(A, n);
    cleanMatrix(L, n);
    cleanMatrix(U, n);
};

// Test Gauss Seidel Method
void testGaussSeidelMethod() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    setColor(MAGENTA);
    cout << "Testing Gauss Seidel Method\n";
    setColor(DEFAULT);

    double* U = GaussSeidelMethod(A, b, x, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    setColor(YELLOW);
    if (U != nullptr) {
        cout << "x = ";
        displayVector(U, n);
    }

    if (equalVectors(X, U, n)) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }
    cleanMatrix(A, n);
};

// Test Jacobi Method
void testJacobiMethod() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    setColor(MAGENTA);
    cout << "Testing Jacobi Method\n";
    setColor(DEFAULT);

    double* U = JacobiMethod(A, b, x, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    setColor(YELLOW);
    if (U != nullptr) {
        cout << "x = ";
        displayVector(U, n);
    }

    if (equalVectors(X, U, n)) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }

    cleanMatrix(A, n);
};

// Test SOR Method
void testSORMethod() {
    const int n = 4;
    const double w = 1.25;
    double** A = createMatrix();
    initializeMatrix(A);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    setColor(MAGENTA);
    cout << "Testing Successive Over Relaxation Method\n";
    setColor(DEFAULT);

    double* U = SuccessiveOverRelaxation(A, b, x, w, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    setColor(YELLOW);
    if (U != nullptr) {
        cout << "x = ";
        displayVector(U, n);
    }

    if (equalVectors(X, U, n)) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }

    cleanMatrix(A, n);
};

// Test Weighted Jacobi Method
void testWeightedJacobiMethod() {
    const int n = 4;
    const double w = 0.5;
    double** A = createMatrix();
    initializeMatrix(A);

    double b[n] = {6.0, 25.0, -11.0, 15.0};
    double x[n] = {0.0, 0.0, 0.0, 0.0};

    setColor(MAGENTA);
    cout << "Testing Weighted Jacobi Method\n";
    setColor(DEFAULT);

    double* U = WeightedJacobiMethod(A, b, x, w, n);
    double X[n] = {1.0, 2.0, -1.0, 1.0};

    setColor(YELLOW);
    if (U != nullptr) {
        cout << "x = ";
        displayVector(U, n);
    }

    if (equalVectors(X, U, n)) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }

    cleanMatrix(A, n);
};

// Test Von Mises Method
void testVonMisesMethod() {
    const int n = 4;
    double** A = createMatrix();
    initializeMatrix(A);

    setColor(MAGENTA);
    cout << "Testing Von Mises Method\n";
    setColor(DEFAULT);

    double* x = VonMisesIterationMethod(A, n);

    setColor(YELLOW);
    cout << "Eigenvector: \nx = ";
    displayVector(x, n);

    double c = RayleighQuotient(A, x, n);
    setColor(YELLOW);
    cout << "Eigenvalue: k = " << c << endl;

    if (vectorProduct(A, n, n, x, n) == vectorScalarProduct(x, n, c), n) {
        setColor(GREEN);
        cout << "Test Passed!\n" << endl;
        setColor(DEFAULT);
    }
    else {
        setColor(RED);
        cout << "Test Failed!\n" << endl;
        setColor(DEFAULT);
    }

    cleanMatrix(A, n);
};

#include <iostream>
#include <math.h>
#include <cassert>

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

double cubicPolynomial(double x) {
    return pow(x, 3) - x - 2;
};

double transcendentalFunction(double x) {
    return x * sin(2 * x) - pow(x, 3);
};

// Test Bolzano's Method
bool testBolzanoMethod() {
    double a = 0;
    double b = 2;
    double root = 1.5213797068045675696040808322544385144283898284279039090904980154;

    cout << "Testing Bolzano's Method for interval [" << a << ", " << b << "]" << endl;

    double x = BolzanosMethod(cubicPolynomial, a, b);
    cout << "f(" << x <<") = " << cubicPolynomial(x) << endl;

    if (abs(root - x) < TOLERANCE) {
        cout << "Test Passed!\n" << endl;
        return true;
    } else {
        cout << "Test Failed!\n" << endl;
        return false;
    }
};

// Test Newton Raphson Method
bool testNewtonRaphsonMethod() {
    double x0 = 1;
    double root = 0.966876881413510626654237834545340028268547068798811;

    cout << "Testing Newton Raphson's Method" << endl;

    double x = NewtonRaphsonMethod(transcendentalFunction, x0);
    cout << "f(" << x <<") = " << transcendentalFunction(x) << endl;

    if (abs(root - x) < TOLERANCE) {
        cout << "Test Passed!\n" << endl;
        return true;
    } else {
        cout << "Test Failed!\n" << endl;
        return false;
    }
};

// Test Regula Falsi Method
bool testRegulaFalsiMethod() {
    double a = 0.5;
    double b = 1;
    double root = 0.966876881413510626654237834545340028268547068798811;

    cout << "Testing Regula Falsi Method for interval [" << a << ", " << b << "]" << endl;

    double x = RegulaFalsiMethod(transcendentalFunction, a, b);
    cout << "f(" << x <<") = " << transcendentalFunction(x) << endl;

    if (abs(root - x) < TOLERANCE) {
        cout << "Test Passed!\n" << endl;
        return true;
    } else {
        cout << "Test Failed!\n" << endl;
        return false;
    }
};

// Test Secant Method
bool testSecantMethod() {
    double a = 0;
    double b = 2;
    double root = 1.5213797068045675696040808322544385144283898284279039090904980154;

    cout << "Testing Secant Method for interval [" << a << ", " << b << "]" << endl;

    double x = SecantMethod(cubicPolynomial, a, b);
    cout << "f(" << x <<") = " << cubicPolynomial(x) << endl;

    if (abs(root - x) < TOLERANCE) {
        cout << "Test Passed!\n" << endl;
        return true;
    } else {
        cout << "Test Failed!\n" << endl;
        return false;
    }
};


int main() {
    cout << "Testing Root Finding Algorithms...\n" << endl;
    assert(testBolzanoMethod() == true);
    assert(testNewtonRaphsonMethod() == true);
    assert(testRegulaFalsiMethod() == true);
    assert(testSecantMethod() == true);

    return 0;
}
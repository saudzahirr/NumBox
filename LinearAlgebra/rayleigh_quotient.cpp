/*
 * Author: Saud Zahir
 * Date: December 24, 2023
 * Description: Rayleigh quotient algorithm to find eigen values.
 */


#include <iostream>
#include <random>
#include "rayleigh_quotient.h"
#include "../Utils/utils.h"

using namespace std;

double RayleighQuotient(double** A, double* x, int n) {
    return Dot(vectorProduct(A, n, n, x, n), x, n) / Norm(x, n);
};
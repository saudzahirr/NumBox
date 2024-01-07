/*
 * Author: Saud Zahir
 * Date: December 24, 2023
 * Description: Rayleigh quotient algorithm to find eigen values.
 */

#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "rayleigh_quotient.h"

using namespace std;


double RayleighQuotient(double** A, double* x, int n) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Calculating eigenvalue using Rayleigh Quotient ...");

    double k = Dot(vectorProduct(A, n, n, x, n), x, n) / Norm(x, n);

    DEBUG_OUT("Eigenvalue: " + to_string(k));

    time_req = clock() - time_req;
    INFO_OUT("Execution time for calculating eigenvalue: "
            + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

    return k;
};
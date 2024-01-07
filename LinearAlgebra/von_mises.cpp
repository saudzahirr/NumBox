/*
 * Author: Saud Zahir
 * Date: December 24, 2023
 * Description: Von Mises (Power method) iterative algorithm to find eigen vectors.
 */


#include <random>
#include <ctime>
#include "../Logger/logger.h"
#include "../Utils/utils.h"
#include "von_mises.h"

using namespace std;


double* VonMisesIterationMethod(double** A, int n) {
    clock_t time_req;
    time_req = clock();

    INFO_OUT("Starting Von Mises Method ...");
    DEBUG_OUT("Matrix A: \n" + getMatrixString(A, n, n, 8));

    INFO_OUT("Initializing random vector for Von Mises iteration ...");

    double* x = new double[n];
    double* u = new double[n];

    random_device rd;
    mt19937 gen(rd());

    // Mean and standard deviation for the normal distribution
    double mean = 0.5;  // Center around 0.5 for values between 0 and 1
    double stddev = 0.25;  // Standard deviation, adjust as needed

    normal_distribution<double> distribution(mean, stddev);

    // Generate random numbers from the normal distribution
    for (int i = 0; i < n; ++i) {
        double random_number = distribution(gen);
        random_number = max(0.0, min(1.0, random_number));
        x[i] = random_number;
    }

    DEBUG_OUT("x0 = " + getVectorString(x, n));

    // Von Mises iterative formula.
    for (int a = 1; a <= ITERATIONS; ++a) {
        u = x;
        x = vectorProduct(A, n, n, x, n);
        // x = divideVector(x, n, Max(x, n));
        x = divideVector(x, n, Norm(x, n));

        double change = 0.0;
        for (int i = 0; i < n; ++i) {
            change += abs(x[i] - u[i]);
            if (change == 0) {
                INFO_OUT("Dominant Eigenvector converged at " + to_string(a) + " iterations.");

                DEBUG_OUT("x = " + getVectorString(x, n));

                time_req = clock() - time_req;
                INFO_OUT("Execution time for Von Mises Method: "
                        + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");
                delete u;
                return x;
            }
        }
    }

    DEBUG_OUT("x = " + getVectorString(x, n));

    time_req = clock() - time_req;
    INFO_OUT("Execution time for Von Mises Method: "
            + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");
    delete u;
    return x;
}

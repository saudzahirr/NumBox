#include <ctime>
#include "utest.h"

using namespace std;

int main() {
    clock_t time_req;
    time_req = clock();

    PRINT("Testing Root Finding Algorithms ...");
    testBolzanoMethod();
    testNewtonRaphsonMethod();
    testRegulaFalsiMethod();
    testSecantMethod();
    testFixedPointMethod();

    PRINT("Testing Numerical Integration ...");
    testTrapezoidRule();
    testSimpsonsRule();
    testSimpsonsThreeEighthRule();
    testBoolesRule();
    testMilnesRule();
    // testWeddlesRule();
    testRiemannSum();
    testRombergsMethod();
    // testGaussianQuadratureMethod();
    // testMonteCarloMethod();

    PRINT("Testing LU Decomposition Algorithms ...");
    testCholeskyDecomposition();
    testCroutDecomposition();
    testDoolittleDecomposition();

    PRINT("Testing Numerical Linear Algebra ...");
    testGaussSeidelMethod();
    testJacobiMethod();
    testSORMethod();
    testWeightedJacobiMethod();

    testVonMisesMethod();

    time_req = clock() - time_req;
    INFO_OUT("Execution time for unittest: " + formatPrecision(time_req/CLOCKS_PER_SEC) + " seconds");

    return 0;
}
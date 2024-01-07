#include "utest.h"

using namespace std;

int main() {
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

    return 0;
}
#include "utest.h"

using namespace std;

int main() {
    setColor(BLUE);
    INFO_OUT("Testing Root Finding Algorithms...");
    setColor(DEFAULT);
    testBolzanoMethod();
    testNewtonRaphsonMethod();
    testRegulaFalsiMethod();
    testSecantMethod();
    testFixedPointMethod();

    setColor(BLUE);
    INFO_OUT("Testing Numerical Integration...");
    setColor(DEFAULT);
    testSimpsonsRule();

    setColor(BLUE);
    INFO_OUT("Testing LU Decomposition Algorithms...");
    setColor(DEFAULT);
    testCholeskyDecomposition();
    testCroutDecomposition();
    testDoolittleDecomposition();

    setColor(BLUE);
    INFO_OUT("Testing Numerical Linear Algebra Algorithms...\n");
    setColor(DEFAULT);
    testGaussSeidelMethod();
    testJacobiMethod();
    testSORMethod();
    testWeightedJacobiMethod();

    testVonMisesMethod();

    return 0;
}
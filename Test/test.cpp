#include "test.h"

using namespace std;

int main() {
    setColor(BLUE);
    info("Testing Root Finding Algorithms...");
    setColor(DEFAULT);
    testBolzanoMethod();
    testNewtonRaphsonMethod();
    testRegulaFalsiMethod();
    testSecantMethod();
    testFixedPointMethod();

    setColor(BLUE);
    info("Testing Numerical Integration...");
    setColor(DEFAULT);
    void testSimpsonsRule();

    setColor(BLUE);
    info("Testing LU Decomposition Algorithms...");
    setColor(DEFAULT);
    testCholeskyDecomposition();
    testCroutDecomposition();
    testDoolittleDecomposition();

    setColor(BLUE);
    info("Testing Numerical Linear Algebra Algorithms...\n");
    setColor(DEFAULT);
    testGaussSeidelMethod();
    testJacobiMethod();
    testSORMethod();
    testWeightedJacobiMethod();

    testVonMisesMethod();

    return 0;
}
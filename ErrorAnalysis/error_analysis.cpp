#include "error_analysis.h"

using namespace std;

double truncationError(double estimatedValue, double trueValue) {
    return trueValue - estimatedValue;
}

double absoluteError(double estimatedValue, double trueValue) {
    return abs(estimatedValue - trueValue);
}

double rootSquareError(double estimatedValue, double trueValue) {
    return sqrt(abs(pow(estimatedValue, 2) - pow(trueValue, 2)));
}

double logError(double estimatedValue, double trueValue) {
    return log10(trueValue) - log10(estimatedValue);
}

double relativeError(double estimatedValue, double trueValue) {
    return abs((estimatedValue - trueValue) / trueValue);
}

double rootSquareRelativeError(double estimatedValue, double trueValue) {
    return sqrt(abs((pow(estimatedValue, 2) - pow(trueValue, 2)) / pow(trueValue, 2)));
}

double meanAbsoluteError(double estimatedValue, double trueValue) {
    return abs((trueValue - estimatedValue) / 2.0);
}

double meanSquaredError(double estimatedValue, double trueValue) {
    return pow((trueValue - estimatedValue), 2) / 2.0;
}

double meanPercentageError(double estimatedValue, double trueValue) {
    return abs((trueValue - estimatedValue) / trueValue) * 100.0;
}

double symmetricPercentageError(double estimatedValue, double trueValue) {
    return abs((trueValue - estimatedValue) / ((trueValue + estimatedValue) / 2.0)) * 100.0;
}

double squaredLogError(double estimatedValue, double trueValue) {
    return pow(log(1 + abs(trueValue - estimatedValue)), 2);
}


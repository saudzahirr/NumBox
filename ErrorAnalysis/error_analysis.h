#ifndef ERROR_ANALYSIS_H
#define ERROR_ANALYSIS_H

#include <cmath>

double truncationError(double estimatedValue, double trueValue);

double absoluteError(double estimatedValue, double trueValue);

double rootSquareError(double estimatedValue, double trueValue);

double logError(double estimatedValue, double trueValue);

double relativeError(double estimatedValue, double trueValue);

double rootSquareRelativeError(double estimatedValue, double trueValue);

double meanAbsoluteError(double estimatedValue, double trueValue);

double meanSquaredError(double estimatedValue, double trueValue);

double meanPercentageError(double estimatedValue, double trueValue);

double symmetricPercentageError(double estimatedValue, double trueValue);

double squaredLogError(double estimatedValue, double trueValue);

#endif // ERROR_ANALYSIS_H

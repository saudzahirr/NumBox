#ifndef UTILS_H
#define UTILS_H

#include <cmath>

#define ITERATIONS 1000
#define TOLERANCE 1E-32
#define PI M_PI

double roundToNDecimals(double value, int n);

// Calculus utils
double Derivative(double (*f)(double), double x, double h);


// Linear Algebra Utils.
double** matrixAdd(double** A, double** B, int n, int m);

double** matrixSub(double** A, double** B, int n, int m);

double** matrixProduct(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB);

double** matrixScalarProduct(double** A, int m, int n, double c);

double** Transpose(double** matrix, int n, int m);

bool equalMatrices(double** A, double** B, int m, int n);

bool equalVectors(double* vectorA, double* vectorB, int n);

double* vectorAdd(double* vectorA, double* vectorB, int n);

double* vectorSub(double* vectorA, double* vectorB, int n);

double* vectorScalarProduct(double* v, int n, double c);

double* vectorProduct(double** A, int rowsA, int colsA, double* v, int rowsB);

double** outerProduct(double* vectorA, int m, double* vectorB, int n);

double Dot(double* vectorA, double* vectorB, int n);

double* Cross(double* vectorA, double* vectorB);

double Norm(double* x, int n);

double Max(double* x, int n);

double Min(double* x, int n);

double* divideVector(double* v, int n, double s);

double** divideMatrix(double** A, int m, int n, double s);

void cleanMatrix(double** matrix, int rows);

void displayMatrix(double** matrix, int rows, int cols, int cellSize);

void displayVector(double* vector, int n);

double determinantTriangularMatrix(double** matrix, int n);

void getSubmatrix(double** matrix, int size, int row, int col, double** submatrix);

double Determinant(double** matrix, int n);


#endif

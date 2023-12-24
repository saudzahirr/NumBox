#ifndef UTILS_H
#define UTILS_H


#define ITERATIONS 1000
#define TOLERANCE 1E-32
#define PI 3.141592654


double Derivative(double (*f)(double), double x, double h);


// Linear Algebra Utils.
double** matrixProduct(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB);

double* vectorProduct(double** A, int rowsA, int colsA, double* v, int rowsB);

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

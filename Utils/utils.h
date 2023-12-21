#ifndef UTILS
#define UTILS


double Derivative(double (*f)(double), double x, double h);


// Linear Algebra Utils.
double** matrixProduct(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB);

double Dot(double* vectorA, double* vectorB, int n);

void Cross(double* vectorA, double* vectorB, double* vector);

void cleanMatrix(double** matrix, int rows);

void displayMatrix(double** matrix, int rows, int cols, int cellSize);


#endif

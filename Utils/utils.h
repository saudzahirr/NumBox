#ifndef UTILS
#define UTILS


double Derivative(double (*f)(double), double x, double h);


// Linear Algebra Utils.
double** matrixProduct(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB);

double Dot(double* vectorA, double* vectorB, int n);

double* Cross(double* vectorA, double* vectorB);

void cleanMatrix(double** matrix, int rows);

void displayMatrix(double** matrix, int rows, int cols, int cellSize);

double determinantTriangularMatrix(double** matrix, int n);

void getSubmatrix(double** matrix, int size, int row, int col, double** submatrix);

double Determinant(double** matrix, int n);


#endif

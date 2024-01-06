#ifndef CRANK_NICOLSON_H
#define CRANK_NICOLSON_H

void crankNicolsonMatrices2D(double alpha, double k, double hx, double hy, int Nx, int Ny, double**& A, double**& B);

void solveHeatEquation2D(double alpha, double k, double hx, double hy, int Nx, int Ny, double*& u);

#endif
#pragma once
#include <string>
const int N=20;

struct Matrix
{
  int matrix[N][N];
  int rows;
  int cols;
};

void getMatrixFromFile(std::ifstream &fin, Matrix& mat);
void outMatrixInFile(std::string path, Matrix& mat);
void processMatrix(Matrix& mat);


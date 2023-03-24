#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

const int N=20;
using namespace std;
struct Matrix
{
  int matrix[N][N];
  int rows;
  int cols;
};

void fillRandom(Matrix& mat);
void outputMatrixInFile(string path, Matrix& mat);


int main(){
    Matrix mat;
    mat.cols=N;
    string path="in.txt";
    fillRandom(mat);
    outputMatrixInFile(path,mat);
    return 0;
}


void fillRandom(Matrix& mat) {
    srand(time(0));
    mat.rows = N;
    mat.cols = N;
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols;j++) {
            mat.matrix[i][j] = rand();
        }
    }
}
void outputMatrixInFile(string path, Matrix& mat){
    ofstream fout;
    fout.open(path);
    fout << mat.rows<<" "<<mat.cols<<'\n';
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            fout <<right<<setw(11) << mat.matrix[i][j] << " ";
        }
        fout<<'\n';
    }
    fout.close();
}

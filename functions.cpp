#include "headers.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
string getPath();

void processMatrix(Matrix& mat) {
bool is_odd = mat.cols % 2 != 0;
int end_col = is_odd ? mat.cols / 2 + 1 : mat.cols / 2;
int start_row = 0, end_row = mat.rows - 1;
int max_row = 0, max_col = 0, max_val = 0;
// Finding the largest element in the left sector of the matrix
for (int col = 0; col < end_col; col++) {
    for (int row = start_row; row <= end_row; row++) {
        int val = abs(mat.matrix[row][col]);
        if (val > max_val || (val == max_val && (row < max_row || (row == max_row && col < max_col)))) {
            max_row = row;
            max_col = col;
            max_val = val;
        }
    }
    start_row++;
    end_row--;
}

// Removing the row and column that contain the largest element
for (int i = max_row; i < mat.rows - 1; i++) {
    for (int j = 0; j < mat.cols; j++) {
        mat.matrix[i][j] = mat.matrix[i + 1][j];
    }
}
mat.rows--;

for (int i = max_col; i < mat.cols - 1; i++) {
    for (int j = 0; j < mat.rows; j++) {
        mat.matrix[j][i] = mat.matrix[j][i + 1];
    }
}
mat.cols--;

}

void getMatrixFromFile(ifstream &fin, Matrix& mat){

    fin >> mat.rows;
    fin >> mat.cols;
    for(int i=0;i<mat.rows;i++){
        for(int k=0;k<mat.cols;k++){
            fin>>mat.matrix[i][k];
        }
    }
    fin.close();
}



void outMatrixInFile(string path, Matrix& mat){
    ofstream fout;
    if(!fout.is_open())
    {
            path="out.txt";
            fout.open(path);
    }
    fout << mat.rows<<" "<<mat.cols<<'\n';
    for (int i = 0; i < mat.rows; i++) {
        for (int k = 0; k < mat.cols; k++) {
            fout <<right<<setw(11) << mat.matrix[i][k] << " ";
        }
        fout<<'\n';
    }
    fout.close();
}


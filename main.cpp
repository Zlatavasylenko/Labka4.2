#include "headers.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void printGroupInfo();
string getPath();

int main() {
    printGroupInfo();
    Matrix mat;
    cout<<"<<<Enter the path to file in where located the matrix>>> "<<endl;
    string path;
    ifstream fin;
    while(1){
        string path=getPath();
         if(path.size()==0){path="in.txt";}
         ifstream fin;
         fin.open(path);
         if(fin.is_open()){break;}
         cout<<"ERROR! Please, try again!"<<endl;
    }
    getMatrixFromFile(fin,mat);
    fin.close();
    path.clear();
    processMatrix(mat);
    cout<<"<<<Enter the path to file in which will be saved the results>>>"<<endl;
    path=getPath();
    if(path.size()==0){path="out.txt";}
    outMatrixInFile(path, mat);
    return 0;
}

void printGroupInfo()
{
    cout << "Group: K-14" << endl;
    cout << "Name: Vasylenko Zlata" << endl;
    cout << "Task: Lab2-2 Array of arrays and dynamic arrays"<<endl;
    cout<<"Variant:173.\n Find the first (with the smallest row number, and with equality of row numbers with the smallest column number)\n of the elements that have the highest modulo value in the left sector of the square matrix (including borders).\n Remove from the matrix the row and column to which it belongs."<< endl<<endl;

}


string getPath(){
    cout << "Write the path:";
    string path;
    getline(cin,path);
    return path;
}



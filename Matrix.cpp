#include "Matrix.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace zich;
using namespace std;

Matrix::Matrix(vector<double> matrix, int row, int col){
    if(row < 0 || col < 0 ){
        throw ("Matrix cant be with negative shape");
    }
    this->row = row;
    this->col = col;
    this->matrix = matrix;
}

Matrix::~Matrix(){
}


//-------------------------------------
// Arithmetic Operators
//-------------------------------------

//Matrix * Matrix
Matrix Matrix::operator * (const Matrix &otherMat){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//Matrix * double
Matrix Matrix:: operator * (double num){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//Matrix + Matrix
Matrix Matrix::operator + (const Matrix &otherMat){
    checkSameSize(*this, otherMat);
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//Matrix - Matrix
Matrix Matrix::operator - (const Matrix &otherMat){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}


//int * Matrix
Matrix zich::operator * (const int& num, const Matrix& mat){
    return mat;
}


//-------------------------------------
// Relational Operators
//-------------------------------------

bool Matrix::operator > (const Matrix &otherMat){return true;}
bool Matrix::operator < (const Matrix &otherMat){return true;}
bool Matrix::operator >= (const Matrix &otherMat){return true;}
bool Matrix::operator <= (const Matrix &otherMat){return true;}
bool Matrix::operator == (const Matrix  &otherMat){return true;}
bool Matrix::operator != (const Matrix &otherMat){return true;}

//-------------------------------------
// Assignment Operators
//-------------------------------------

//Matrix += Matrix
Matrix Matrix::operator += (const Matrix &otherMat){
    checkSameSize(*this, otherMat);
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//Matrix -= Matrix
Matrix Matrix::operator -= (const Matrix &otherMat){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//Matrix *= int
Matrix Matrix::operator *= (int number){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}


//-------------------------------------
// unary operation
//-------------------------------------

//--Matrix
Matrix Matrix::operator -- (){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//++Matrix
Matrix Matrix::operator ++ (){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//-Matrix
Matrix Matrix::operator - (){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//+Matrix
Matrix Matrix::operator + (){
    Matrix ans (this->matrix, this->row, this->col);
    return ans;
}

//-------------------------------------
// friend global IO operators - Input and Output
//-------------------------------------

ostream& zich::operator<<(ostream& out , const Matrix& matrix){
    return out;
}

istream& operator >> (std::istream &input, Matrix const &matrix){
    return input;
}


//-------------------------------------
// Input check
//-------------------------------------

void Matrix::checkNegative(const Matrix &mat){
    if(mat.getCol() < 0 || mat.getRow() < 0){
        throw ("Matrix cant be with negative shape");
    }
}

void Matrix::checkSameSize(const Matrix &matrix1 , const Matrix &matrix2){
    if (matrix1.getCol() != matrix2.getCol() || matrix1.getRow() != matrix2.getRow()){
        throw ("Matrices have to be from the same shape");
    }
}
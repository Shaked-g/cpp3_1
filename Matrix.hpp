#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace zich {
    class Matrix {
        private:
            int row;
            int col;
            vector <double> matrix;
        public:
            Matrix(vector<double> matrix, int row, int col); // Constructor
            ~Matrix(); // Destructor

            //-------------------------------------
	        // Arithmetic Operators
	        //-------------------------------------
            Matrix operator * (const Matrix &mat);
            Matrix operator * (double num);
            Matrix operator + (const Matrix &mat);
            Matrix operator - (const Matrix &mat);

            friend Matrix operator * (const int &num, const Matrix &mat);


            //-------------------------------------
	        // Relational Operators
	        //-------------------------------------
            bool operator > (const Matrix &mat1);
            bool operator >= (const Matrix &mat1);
            bool operator < (const Matrix &mat1);
            bool operator <= (const Matrix &mat1);
            bool operator != (const Matrix &mat1);
            bool operator == (Matrix const &mat1);


            //-------------------------------------
	        // Assignment Operators
	        //-------------------------------------
            Matrix operator += (const Matrix &mat1);
            Matrix  operator -= (const Matrix &mat1);
            Matrix operator *= (int number);


            //-------------------------------------
	        // Unary operation
	        //-------------------------------------
            Matrix operator -- ();
            Matrix operator ++ ();
            Matrix operator + ();
            Matrix operator - ();


            //-------------------------------------
	        // Friend global IO operators - Input and Output
	        //-------------------------------------
            friend ostream& operator << (ostream &out, Matrix const &matrix);
            friend istream& operator >> (std::istream &input, Matrix const &matrix);


            //-------------------------------------
	        // Getters
	        //-------------------------------------
            int getRow() const {return this->row;}
            int getCol() const {return this->col;}
            vector<double> getMatrix() const {return this->matrix;}


            //-------------------------------------
	        // Input check
	        //-------------------------------------
            void checkNegative(const Matrix &mat);
            void checkSameSize(const Matrix &matrix1, const Matrix &matrix2);

    };
}
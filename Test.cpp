#include "doctest.h"
#include "Matrix.hpp"
#include <stdexcept>
#include <vector>

using namespace zich;
using namespace std;


TEST_CASE("Bad Input - Matrices not in the same shape"){
    const vector<double> vector1 = {2, 4, 0, 1, 7, 1};
    bool result;
    Matrix matrix1(vector1, 2, 3);
    Matrix matrix2(vector1, 3, 2);
    CHECK_THROWS(matrix1 + matrix2);
    CHECK_THROWS(matrix1 - matrix2);
    CHECK_THROWS(matrix1 -= matrix2);
    CHECK_THROWS(matrix1 += matrix2);
    CHECK_THROWS(matrix2 * matrix1);
    CHECK_NOTHROW(matrix1 * matrix2);
    CHECK_THROWS(result = (matrix2 == matrix1));
    CHECK_THROWS(result = (matrix2 != matrix1));
    CHECK_THROWS(result = (matrix2 > matrix1));
    CHECK_THROWS(result = (matrix2 < matrix1));
    CHECK_THROWS(result = (matrix2 >= matrix1));
    CHECK_THROWS(result = (matrix2 <= matrix1));
    }


TEST_CASE("Good Input - Same shape matrices Relational Operators"){
    const vector<double> vector1 = {1, 2, 5, 4, 8, 1, 4, 2, 3, 7, 3, 9, 3, 7, 9};
    Matrix matrix1(vector1, 5, 3);
    Matrix matrix2(vector1, 5, 3);
    bool trueAnswer = true;
    bool result;
    result = matrix1 == matrix2;
    CHECK(trueAnswer == result);
    result = matrix1 >= matrix2;
    CHECK(trueAnswer == result);
    result = matrix1 <= matrix2;
    CHECK(trueAnswer == result);
    trueAnswer = false;
    result = matrix1 != matrix2;
    result = matrix1 < matrix2;
    CHECK(trueAnswer == result);
    CHECK(trueAnswer == result);
    result = matrix1 > matrix2;
    CHECK(trueAnswer == result);

}


TEST_CASE("Good Input - Same shape matrices addition"){
    bool trueAnswer = true;
    bool result;

    const vector<double> vector0 = {2, 3, 4, 5, 6, 7};
    Matrix matrixZero(vector0, 2, 3);

    const vector<double> vector1 = {1, 1, 1, 1, 1, 1};
    Matrix matrixAdd(vector1, 2, 3);

    const vector<double> vectorAnswer = {3, 4, 5, 6, 7, 8};
    Matrix matrixAnswer(vectorAnswer, 2, 3);

    result = (matrixAnswer == matrixZero + matrixAdd); 
    CHECK(trueAnswer == result);

    result = (matrixAnswer == ++matrixZero);
    CHECK(trueAnswer == result);

    result = (matrixAnswer != ++matrixAdd);
    CHECK(trueAnswer == result);
}


TEST_CASE("Good Input - Same shape matrices subtraction"){
    bool trueAnswer = true;
    bool result;

    const vector<double> vectorSub = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const vector<double> vectorAnswer = {0, 4, 3, 1, 7, 2, 1, 3, 7, 1, 1, 4};
    const vector<double> vectorBase = {1, 5, 4, 2, 8, 3, 2, 4, 8, 2, 2, 5};

    Matrix matrixSub(vectorSub, 3, 4);
    Matrix matrixAnswer(vectorAnswer, 3, 4);
    Matrix matrixBase(vectorBase, 3, 4);

    result = (matrixAnswer == matrixBase - matrixSub);
    CHECK(trueAnswer == result);
    result = (matrixAnswer != --matrixSub);
    CHECK(trueAnswer == result);
    result = (matrixAnswer == --matrixBase);
    CHECK(trueAnswer == result);

}


TEST_CASE("Good Input - Matrices multiplication"){
    bool trueAnswer = true;
    bool result;

    const vector<double> vector1 = {1, 2, 3, 4, 5, 6};
    const vector<double> vector2 = {7, 8, 9};
    const vector<double> vectorAnswer = {50, 122};
    Matrix matrix1(vector1, 2, 3);
    Matrix matrix2(vector2, 3, 1);
    Matrix matrixAnswer(vectorAnswer, 2, 1);

    result = (matrixAnswer == matrix1 * matrix2);
    CHECK(trueAnswer == result);

    const vector<double> vectorAnswerMulti = {3, 6, 9, 12, 15, 18};
    Matrix matrixNumberAnswer(vectorAnswerMulti, 2, 3);

    result = (matrixNumberAnswer == 3 * matrix1);
    CHECK(trueAnswer == result);
}    
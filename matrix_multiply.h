//
// Created by 黄颖盈 on 2020/11/12.
//

#ifndef ASSIGNMENT_MATRIX_MULTIPLY_H
#define ASSIGNMENT_MATRIX_MULTIPLY_H
#pragma (O3)
#include <iostream>
#include <String>
using namespace std;

struct matrix{
    int row;
    int column;
    float * data;
};

float dot_product1(const float *p1, const float * p2, size_t n);
void matrix1(matrix matrixA,matrix matrixB,float * vector_1 ,float * vector_2);
void matrix2(matrix matrixA, matrix matrixB);
void matrix3(matrix matrixA, matrix matrixB);


#endif //ASSIGNMENT_MATRIX_MULTIPLY_H

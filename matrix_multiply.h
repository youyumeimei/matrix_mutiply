//
// Created by 黄颖盈 on 2020/11/12.
//

#ifndef ASSIGNMENT_MATRIX_MULTIPLY_H
#define ASSIGNMENT_MATRIX_MULTIPLY_H
//#pragma (O3)
#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>
#include <cblas.h>
using namespace std;

struct matrix{
    int row;
    int column;
    float * data;
};

float dot_product1(const float *p1, const float * p2, size_t n);
float dot_product2(const float *p1, const float * p2, size_t n);
float dot_product3(const float *p1, const float * p2, size_t n);
float dot_product4(const float *p1, const float * p2, size_t n);

void matrix_manual(matrix matrixA,matrix matrixB,matrix matrixC,int n);
void matrix1(matrix matrixA, matrix matrixB,matrix matrixC,int n);
void matrix2(matrix matrixA, matrix matrixB,matrix matrixC,int n);
void matrix3(matrix matrixA, matrix matrixB,matrix matrixC,int n);
void matrix4(matrix matrixA, matrix matrixB,matrix matrixC,int n);

bool judge(string string);
void trans(matrix matrix);
void output(matrix matrix);


#endif //ASSIGNMENT_MATRIX_MULTIPLY_H

//
// Created by 黄颖盈 on 2020/11/12.
//

#pragma (O3)
#include <iostream>
#include "matrix_multiply.h"
using namespace std;

float dot_product1(const float *p1, const float * p2, size_t n)
{
    float sum = 0.0f;
    for (size_t i = 0; i < n; i++)
        sum += (p1[i] * p2[i]);
    return sum;
}

float dot_product2(const float *p1, const float * p2, size_t n)
{
    if(n % 8 != 0)
    {
        std::cerr << "The size n must be a multiple of 8." <<std::endl;
        return 0.0f;
    }

    float sum = 0.0f;
    for (size_t i = 0; i < n; i+=8)
    {
        sum += (p1[i] * p2[i]);
        sum += (p1[i+1] * p2[i+1]);
        sum += (p1[i+2] * p2[i+2]);
        sum += (p1[i+3] * p2[i+3]);
        sum += (p1[i+4] * p2[i+4]);
        sum += (p1[i+5] * p2[i+5]);
        sum += (p1[i+6] * p2[i+6]);
        sum += (p1[i+7] * p2[i+7]);
    }
    return sum;

}

void matrix1(matrix matrixA,matrix matrixB,float * vector_1 ,float * vector_2){
    for (int i = 0; i < matrixA.row; ++i) {
        vector_1=matrixA.data+i*matrixA.column;
        for (int j = 0; j < matrixB.column; ++j) {
            vector_2=matrixB.data+j;
            dot_product1(vector_1,vector_2,matrixA.column);
        }
//        cout<<endl;
    }
//    for (int i = 0; i < matrixA.row; ++i) {
//        * vector_1=matrixA.data[i*matrixA.column+j];
//        for (int j = 0; j < matrixA.column; ++j) {
//            vector_2[l]=matrixB.data[l*matrixB.row+k];
//        }
////        for (int k = 0; k < matrixB.column; ++k) {
////            for (int l = 0; l < matrixB.row; ++l) {
////
////            }
//
//
//
//            dot_product1(vector_1,vector_2,matrixA.column);
//        }
//        cout<<endl;
//    }

    delete [] vector_1;
    delete [] vector_2;

}

void matrix2(matrix matrixA, matrix matrixB){

    float * vector_1;
    float * vector_2;
//    *(matrixA.data)=1.0f;
//    *(matrixB.data)=1.0f;
//    *(vector_1)=1.0f;
//    *(vector_2)=1.0f;
    for (int i = 0; i < matrixA.row; ++i) {
        vector_1=matrixA.data+i*matrixA.column;
        for (int j = 0; j < matrixB.column; ++j) {
            vector_2=matrixB.data+j;
            dot_product1(vector_1,vector_2,matrixA.column);
        }
    }

    delete [] vector_1;
    delete [] vector_2;

}

void matrix3(matrix matrixA, matrix matrixB){

    float * vector_1;
    float * vector_2;
    *(matrixA.data)=1.0f;
    *(matrixB.data)=1.0f;
    for (int i = 0; i < matrixA.row; ++i) {
        vector_1=matrixA.data+i*matrixA.column;
        for (int j = 0; j < matrixB.column; ++j) {
            vector_2=matrixB.data+j;
            dot_product2(vector_1,vector_2,matrixA.column);
        }
    }

    delete [] vector_1;
    delete [] vector_2;

}


bool judge(string string){

}

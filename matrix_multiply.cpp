//
// Created by 黄颖盈 on 2020/11/12.
//

#include <iostream>
#include <immintrin.h>
#include <omp.h>
#include "matrix_multiply.h"
using namespace std;

float dot_product1(const float *p1, const float * p2, size_t n)
{
    float sum = 0.0f;
    for (size_t i = 0; i < n; i++)
        sum += (p1[i] * p2[i*n]);
//    cout<<sum<<" ";
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
        sum += (p1[i+1] * p2[i+1*n]);
        sum += (p1[i+2] * p2[i+2*n]);
        sum += (p1[i+3] * p2[i+3*n]);
        sum += (p1[i+4] * p2[i+4*n]);
        sum += (p1[i+5] * p2[i+5*n]);
        sum += (p1[i+6] * p2[i+6*n]);
        sum += (p1[i+7] * p2[i+7*n]);
    }
    return sum;
}

float dot_product3(const float *p1, const float * p2, size_t n) {
    if(n % 8 != 0)
    {
        std::cerr << "The size n must be a multiple of 8." <<std::endl;
        return 0.0f;
    }

    float sum[8] = {0};
    __m256 a, b;
    __m256 c = _mm256_setzero_ps();

    float * array=new float [8];

    for (size_t i = 0; i < n; i+=8)
    {
        for (int j = 0; j < 8; ++j) {
            array[j]=*(p2+i*n+j*n);
        }

        a = _mm256_load_ps(p1 + i);
        b = _mm256_load_ps(array);
        c =  _mm256_add_ps(c, _mm256_mul_ps(a, b));
    }

    _mm256_store_ps(sum, c);
    return (sum[0]+sum[1]+sum[2]+sum[3]+sum[4]+sum[5]+sum[6]+sum[7]);
}

float dot_product4(const float *p1, const float * p2, size_t n) {
    if (n % 8 != 0) {
        std::cerr << "The size n must be a multiple of 8." << std::endl;
        return 0.0f;
    }

    float sum[8] = {0};
    __m256 a, b;
    __m256 c = _mm256_setzero_ps();

//#pragma omp parallel for
    for (size_t i = 0; i < n; i += 8) {
        a = _mm256_load_ps(p1 + i);
        b = _mm256_load_ps(p2 + i);
        c = _mm256_add_ps(c, _mm256_mul_ps(a, b));
    }
    _mm256_store_ps(sum, c);
    return (sum[0] + sum[1] + sum[2] + sum[3] + sum[4] + sum[5] + sum[6] + sum[7]);
}

void matrix_manual(matrix matrixA,matrix matrixB,matrix matrixC,int n){
    for (int i = 0; i < matrixA.row; ++i) {
        for (int j = 0; j < matrixB.column; ++j) {
            *(matrixC.data+i*n+j)=dot_product1(matrixA.data+i*n,matrixB.data+j,n);
        }
    }
//    output(matrixC);
}

void matrix1(matrix matrixA, matrix matrixB,matrix matrixC,int n){
//    *(matrixA.data)=1.0f;
//    *(matrixB.data)=1.0f;
//    *(matrixA.data+1)=2.0f;
//    *(matrixB.data+n)=2.0f;
    for (int i = 0; i < matrixA.row; ++i) {
        for (int j = 0; j < matrixB.column; ++j) {
            *(matrixC.data+i*matrixA.column+j)=
            dot_product1(matrixA.data+i*matrixA.column,matrixB.data+j,n);
        }
    }
//    output(matrixC);
}

void matrix2(matrix matrixA, matrix matrixB,matrix matrixC,int n){
    int k=0;
//    *(matrixA.data)=1.0f;
//    *(matrixB.data)=1.0f;
//    *(matrixA.data+1)=2.0f;
//    *(matrixB.data+n)=2.0f;
    for(int i=0;i<matrixA.row;i++){
        for(int j=0;j<matrixB.column;j=j+8){
            *(matrixC.data+k)=dot_product2(matrixA.data+i*n,matrixB.data+j,n);
            *(matrixC.data+k+1)=dot_product2(matrixA.data+i*n,matrixB.data+j+1,n);
            *(matrixC.data+k+2)=dot_product2(matrixA.data+i*n,matrixB.data+j+2,n);
            *(matrixC.data+k+3)=dot_product2(matrixA.data+i*n,matrixB.data+j+3,n);
            *(matrixC.data+k+4)=dot_product2(matrixA.data+i*n,matrixB.data+j+4,n);
            *(matrixC.data+k+5)=dot_product2(matrixA.data+i*n,matrixB.data+j+5,n);
            *(matrixC.data+k+6)=dot_product2(matrixA.data+i*n,matrixB.data+j+6,n);
            *(matrixC.data+k+7)=dot_product2(matrixA.data+i*n,matrixB.data+j+7,n);
            k=k+8;
        }
    }
//    output(matrixC);
}

void matrix3(matrix matrixA, matrix matrixB,matrix matrixC,int n){
//    *(matrixA.data)=1.0f;
//    *(matrixB.data)=1.0f;
//    *(matrixA.data+1)=2.0f;
//    *(matrixB.data+n)=2.0f;
    for (int i = 0; i < matrixA.row; ++i) {
        for (int j = 0; j < matrixB.column; ++j) {
            *(matrixC.data+i*matrixA.column+j)=
            dot_product3(matrixA.data+i*matrixA.column,matrixB.data+j,n);
        }
    }
//    output(matrixC);
}

void matrix4(matrix matrixA, matrix matrixB,matrix matrixC,int n){
    trans(matrixB);
//    *(matrixA.data)=1.0f;
//    *(matrixB.data)=1.0f;
//    *(matrixA.data+1)=2.0f;
//    *(matrixB.data+n)=2.0f;
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < matrixA.row; ++i) {
            for (int j = 0; j < matrixB.column; j+=8) {
                *(matrixC.data+i*n+j)=dot_product4(matrixA.data+i*n,matrixB.data+j*n, n);
                *(matrixC.data+i*n+j+1)=dot_product4(matrixA.data+i*n,matrixB.data+(j+1)*n, n);
                *(matrixC.data+i*n+j+2)=dot_product4(matrixA.data+i*n,matrixB.data+(j+2)*n, n);
                *(matrixC.data+i*n+j+3)=dot_product4(matrixA.data+i*n,matrixB.data+(j+3)*n, n);
                *(matrixC.data+i*n+j+4)=dot_product4(matrixA.data+i*n,matrixB.data+(j+4)*n, n);
                *(matrixC.data+i*n+j+5)=dot_product4(matrixA.data+i*n,matrixB.data+(j+5)*n, n);
                *(matrixC.data+i*n+j+6)=dot_product4(matrixA.data+i*n,matrixB.data+(j+6)*n, n);
                *(matrixC.data+i*n+j+7)=dot_product4(matrixA.data+i*n,matrixB.data+(j+7)*n, n);
            }
        }
//        output(matrixC);
    }
}

bool judge(string string){
    int count1=0;
    int count2=0;
    int count3=0;
    if (string[0]=='-'){
        if (isdigit(string[1])) {
            for (int i = 2; i < string.length(); ++i) {
                if (isdigit(string[i])) {
                } else if (string[i] == '.') {
                    count1++;
                } else if (string[i] == 'E') {
                    count2++;
                    if (i == string.length() - 1) {
                    } else {
                        if (string[i+1] == '-' || string[i+1] == '+'||isdigit(string[i+1])) {
                        } else {
                            return false;
                        }
                        i++;
                    }
                } else if (string[i] == 'e') {
                    count3++;
                    if (i == string.length() - 1) {
                    } else {
                        if (string[i+1] == '-' || string[i+1] == '+'||isdigit(string[i+1])) {
                        } else {
                            return false;
                        }
                        i++;
                    }
                } else {
                    return false;
                }
                if (count1 <= 1 && count2 <= 1 && count3 <= 1) {
                } else {
                    return false;
                }
            }
        } else{
            return false;
        }
    }else if (isdigit(string[0])){
        for (int i = 1; i < string.length(); ++i) {
            if (isdigit(string[i])) {

            }else if (string[i]=='.'){
                count1++;
            }else if (string[i]=='E') {
                count2++;
                if (i == string.length() - 1) {
                } else {
                    if (string[i + 1] == '-' || string[i + 1] == '+' || isdigit(string[i + 1])) {
                    } else {
                        return false;
                    }
                    i++;
                }
            }else if (string[i]=='e') {
                count3++;
                if (i == string.length() - 1) {
                } else {
                    if (string[i + 1] == '-' || string[i + 1] == '+' || isdigit(string[i + 1])) {
                    } else {
                        return false;
                    }
                    i++;
                }
            }else{
                return false;
            }
            if (count1<=1&&count2<=1&&count3<=1){
            }else{
                return false;
            }
        }
    } else{
        return false;
    }
    return true;
}

void trans(matrix matrix){
    for(int i=0;i<matrix.row;i++){
        for(int j=i+1;j<matrix.column;j++){
            float temp = *(matrix.data+i*matrix.row+j);
            *(matrix.data+i*matrix.row+j) = *(matrix.data+j*matrix.row+i);
            *(matrix.data+j*matrix.row+i) = temp;
        }
    }
}

void output(matrix matrix){
    for (int i = 0; i < matrix.row*matrix.column; ++i) {
        cout<<matrix.data[i]<<" ";
        if ((i+1)%matrix.column==0){
            cout<<endl;
        }

    }
}


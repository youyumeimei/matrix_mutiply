//
// Created by 黄颖盈 on 2020/11/12.
//

#pragma (O3)
#include <chrono>
#include "matrix_multiply.h"


int main(){
    matrix matrixA;
    matrix matrixB;
    matrix matrixC;

    int number;
    cout<<"Enter 1 for manual input,and enter 2 for random input!"<<endl;
    cout<<"please input: ";
    cin>>number;

    if (number==1) {
        cout << "Please input the number of rows and columns of one matrix : ";
        cin >> matrixA.row >> matrixA.column;

        cout << "Please input the number of rows and columns of another matrix : ";
        cin >> matrixB.row >> matrixB.column;

        if (matrixA.column == matrixB.row) {

            matrixA.data = new float[matrixA.row * matrixA.column]();
            matrixB.data = new float[matrixB.row * matrixB.column]();
            matrixC.data = new float[matrixA.row * matrixB.column]();

            float * vector_1;
//            =new float [matrixA.column]();
            float * vector_2;
//            =new float [matrixA.column]();

            for (int i = 0; i < matrixA.row * matrixA.column; ++i) {

                cin >> *(matrixA.data+i);
            }
            for (int i = 0; i < matrixB.row * matrixB.column; ++i) {
                cin >> *(matrixB.data+i);
            }

            auto start = std::chrono::steady_clock::now();
            matrix1(matrixA, matrixB,vector_1,vector_2);
            auto end = std::chrono::steady_clock::now();
            cout
                    << "Slow calculations took "
                    << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                    << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                    << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";

            delete [] vector_1;
            delete [] vector_2;
        } else {
            cout << "Your input is wrong!\nn v";
        }
    } else{
        matrixA.row=1000;
        matrixB.row=1000;
        matrixA.column=1000;
        matrixB.column=1000;

        matrixA.data=new float [1000*1000];
        matrixB.data=new float [1000*1000];
        matrix2(matrixA,matrixB);
        matrix2(matrixA,matrixB);
        auto start = std::chrono::steady_clock::now();
        matrix2(matrixA,matrixB);
        auto end = std::chrono::steady_clock::now();
        cout
                << "Slow calculations took "
                << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";

        matrix3(matrixA,matrixB);
        matrix3(matrixA,matrixB);
        start = std::chrono::steady_clock::now();
        matrix3(matrixA,matrixB);
        end = std::chrono::steady_clock::now();
        cout
                << "Slow calculations took "
                << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";


//        delete [] vector_1;
//        delete [] vector_2;
    }

    delete [] matrixA.data;
    delete [] matrixB.data;
}

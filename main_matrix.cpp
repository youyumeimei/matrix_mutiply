//
// Created by 黄颖盈 on 2020/11/12.
//

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

        matrixC.row=matrixA.row;
        matrixC.column=matrixB.column;

        if (matrixA.column == matrixB.row) {

            matrixA.data = new float[matrixA.row * matrixA.column]();
            matrixB.data = new float[matrixB.row * matrixB.column]();
            matrixC.data = new float[matrixA.row * matrixB.column]();

            cout<<"Please input items of the first matrix: ";
            for (int i = 0; i < matrixA.row * matrixA.column; ++i) {
                string string1;
                cin >> string1;
                if (judge(string1)){
                    *(matrixA.data+i)=stof(string1);
                } else{
                    cout<<"your input is wrong!"<<endl;
                    return 0;
                }
            }
            cout<<"Please input items of the second matrix: ";
            for (int i = 0; i < matrixB.row * matrixB.column; ++i) {
                string string1;
                cin >> string1;
                if (judge(string1)){
                    *(matrixB.data+i)=stof(string1);
                } else{
                    cout<<"your input is wrong!"<<endl;
                    return 0;
                }
            }

            auto start = std::chrono::steady_clock::now();
            matrix_manual(matrixA, matrixB,matrixC,matrixA.column);
            auto end = std::chrono::steady_clock::now();
            cout
                    << "Matrix manual calculations took "
                    << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                    << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                    << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";

        } else {
            cout << "Your input is wrong!\nn v";
        }
    } else{
        matrixA.row=1000;
        matrixB.row=1000;
        matrixA.column=1000;
        matrixB.column=1000;
        matrixC.row=1000;
        matrixC.column=1000;

        matrixA.data=new float [1000*1000];
        matrixB.data=new float [1000*1000];
        matrixC.data=new float [1000*1000];


        auto start = std::chrono::steady_clock::now();
        matrix1(matrixA,matrixB,matrixC,matrixA.column);
        auto end = std::chrono::steady_clock::now();
        cout
                << "Matrix 1 calculations took "
                << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";

        start = std::chrono::steady_clock::now();
        matrix2(matrixA,matrixB,matrixC,matrixA.column);
        end = std::chrono::steady_clock::now();
        cout
                << "Matrix 2 calculations took "
                << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";

        start = std::chrono::steady_clock::now();
        matrix3(matrixA,matrixB,matrixC,matrixA.column);
        end = std::chrono::steady_clock::now();
        cout
                << "Matrix 3 calculations took "
                << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";

        start = std::chrono::steady_clock::now();
        matrix4(matrixA,matrixB,matrixC,matrixA.column);
        end = std::chrono::steady_clock::now();
        cout
                << "Matrix 4 calculations took "
                << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";

        start = std::chrono::steady_clock::now();
        cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasTrans, 10000, 10000, 10000, 1.0, matrixA.data, 10000, matrixB.data, 10000, 0.0, matrixC.data, 10000);
        end = std::chrono::steady_clock::now();

        cout
                << "Openblas took "
                << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                << chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";

    }

    delete [] matrixA.data;
    delete [] matrixB.data;

}

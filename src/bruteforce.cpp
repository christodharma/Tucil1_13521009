#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//fungsi operasi 2 bilangan dengan operator tertentu
//operator diassign ke suatu nilai integer untuk mempermudah dalam looping
double operate(double a, double b, int o){
    if (o == 0) {return a + b;}
    else if (o == 1) {return a - b;}
    else if (o == 2) {return a * b;}
    else if (o == 3) {
        if (b != 0 && a/b == (int)(a/b)) {return a/b;}
        else {return 0;}
    }
}

char translate_toOperator(int o){
    if (o == 0) {return '+';}
    else if (o == 1) {return '-';}
    else if (o == 2) {return '*';}
    else if (o == 3) {return '/';}
}

//sudah ada 4 bilangan, dicari nilai 24 dengan permutasi operator
void op_permutation(int numbers[4], vector<string> &result, int &count){
    double temp;
    //X1 op1 (X2 op2 (X3 op3 X4))
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                temp = operate(numbers[0], operate(numbers[1], operate(numbers[2], numbers[3], k), j), i);
                if (temp == 24) {
                    count++;
                    result.push_back(to_string(numbers[0]) + translate_toOperator(i) + "(" + to_string(numbers[1]) + translate_toOperator(j) + "(" + to_string(numbers[2]) + translate_toOperator(k) + to_string(numbers[3]) + "))");
                }
            }
        }
    }
    //X1 op1 ((X2 op2 X3) op3 X4)
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                temp = operate(numbers[0], operate(operate(numbers[1], numbers[2], k), numbers[3], j), i);
                if (temp == 24) {
                    count++;
                    result.push_back(to_string(numbers[0]) + translate_toOperator(i) + "((" + to_string(numbers[1]) + translate_toOperator(k) + to_string(numbers[2]) + ")" + translate_toOperator(j) + to_string(numbers[3]) + ")");
                }
            }
        }
    }
    //(X1 op1 (X2 op2 X3)) op3 X4
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                temp = operate(operate(numbers[0], operate(numbers[1], numbers[2], k), j), numbers[3], i);
                if (temp == 24) {
                    count++;
                    result.push_back("(" + to_string(numbers[0]) + translate_toOperator(j) + "(" + to_string(numbers[1]) + translate_toOperator(k) + to_string(numbers[2]) + "))" + translate_toOperator(i) + to_string(numbers[3]));
                }
            }
        }
    }
    //((X1 op1 X2) op2 X3) op3 X4
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                temp = operate(operate(operate(numbers[0], numbers[1], k), numbers[2], j), numbers[3], i);
                if (temp == 24) {
                    count++;
                    result.push_back("(" + to_string(numbers[0]) + translate_toOperator(k) + to_string(numbers[1]) + ")" + translate_toOperator(j) + to_string(numbers[2]) + ")" + translate_toOperator(i) + to_string(numbers[3]));
                }
            }
        }
    }
    //(X1 op1 X2) op2 (X3 op3 X4)
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                temp = operate(operate(numbers[0], numbers[1], j), operate(numbers[2], numbers[3], k), i);
                if (temp == 24) {
                    count++;
                    result.push_back("(" + to_string(numbers[0]) + translate_toOperator(j) + to_string(numbers[1]) + ")" + translate_toOperator(i) + "(" + to_string(numbers[2]) + translate_toOperator(k) + to_string(numbers[3]) + ")");
                }
            }
        }
    }
}

//mencari semua urutan bilangan
void bruteforce(int numbers[4], vector<string> &result, int &count){
    int temp[4];
    //X1 X2 X3 X4
    op_permutation(numbers, result, count);
    //X1 X2 X4 X3
    temp[0] = numbers[0];
    temp[1] = numbers[1];
    temp[2] = numbers[3];
    temp[3] = numbers[2];
    op_permutation(temp, result, count);
    //X1 X3 X2 X4
    temp[0] = numbers[0];
    temp[1] = numbers[2];
    temp[2] = numbers[1];
    temp[3] = numbers[3];
    op_permutation(temp, result, count);
    //X1 X3 X4 X2
    temp[0] = numbers[0];
    temp[1] = numbers[2];
    temp[2] = numbers[3];
    temp[3] = numbers[1];
    op_permutation(temp, result, count);
    //X1 X4 X2 X3
    temp[0] = numbers[0];
    temp[1] = numbers[3];
    temp[2] = numbers[1];
    temp[3] = numbers[2];
    op_permutation(temp, result, count);
    //X1 X4 X3 X2
    temp[0] = numbers[0];
    temp[1] = numbers[3];
    temp[2] = numbers[2];
    temp[3] = numbers[1];
    op_permutation(temp, result, count);
    //X2 X1 X3 X4
    temp[0] = numbers[1];
    temp[1] = numbers[0];
    temp[2] = numbers[2];
    temp[3] = numbers[3];
    op_permutation(temp, result, count);
    //X2 X1 X4 X3
    temp[0] = numbers[1];
    temp[1] = numbers[0];
    temp[2] = numbers[3];
    temp[3] = numbers[2];
    op_permutation(temp, result, count);
    //X2 X3 X1 X4
    temp[0] = numbers[1];
    temp[1] = numbers[2];
    temp[2] = numbers[0];
    temp[3] = numbers[3];
    op_permutation(temp, result, count);
    //X2 X3 X4 X1
    temp[0] = numbers[1];
    temp[1] = numbers[2];
    temp[2] = numbers[3];
    temp[3] = numbers[0];
    op_permutation(temp, result, count);
    //X2 X4 X1 X3
    temp[0] = numbers[1];
    temp[1] = numbers[3];
    temp[2] = numbers[0];
    temp[3] = numbers[2];
    op_permutation(temp, result, count);
}
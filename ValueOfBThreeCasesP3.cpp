//Section CSC160 - Computer Science I: C++
//File Name: P51_1.cpp 
//Student: Jeffrey Markham
//Homework Number: Lab 5
//Description: This C++ program computes the value to the power of b (a^b) for three cases.
//Last Changed: 03/24/2021

#include <iostream>
using namespace std;


int main()
{
    int i = 0, p = 1;
    int a = 2, b = 4;

    while (i < b) //Computing 2^4
    {
        p = p * a;
        i++;
    }       
    cout << a << " to the power of" << b << " is = " << p << endl;

    i = 0;
    p = 1;
    a = 3, b = 3;

    while (i < b) //Computing 3^3
    {
        p = p * a;
        i++;
    }
    cout << a << " to the power of " << b << " is = " << p << endl;

    i = 0;
    p = 1;
    a = 5, b = 4;

    while (i < b) //Computing 5^4
    {
        p = p * a;
        i++;
    }
    cout << a << " to the power of " << b << " is = " << p << endl;

    cout << endl;
    system ("pause");
    return 0;
}
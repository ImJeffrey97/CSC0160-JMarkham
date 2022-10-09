//Section CSC160 - Computer Science I: C++
//File Name: ex51.cpp 
//Student: Jeffrey Markham
//Homework Number: Lab 5
//Description: This C++ program computes the value to the power of b (a^b) for three cases.
//Last Changed: 03/24/2021

#include <iostream>
#include <cmath>
using namespace std;


int main()
{

    int a = 2, b = 4, result;

    result = pow(a,b);
    cout << a << " to the power of " << b << " is = " << result << endl;

    a = 3, b = 3;

    result = pow(a, b);
    cout << a << " to the power of " << b << " is = " << result << endl;

    a = 5, b = 4;

    result = pow(a,b);
    cout << a << " to the power of " << b << " is = " << result << endl;

    cout << endl;
    system ("pause");
    return 0;
}
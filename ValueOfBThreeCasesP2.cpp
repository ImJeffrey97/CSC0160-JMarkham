//Section CSC160 - Computer Science I: C++
//File Name: ex52.cpp 
//Student: Jeffrey Markham
//Homework Number: Lab 5
//Description: This C++ program computes the value to the power of b (a^b) for three cases.
//Last Changed: 03/24/2021

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int i = 0;
    int a = 2, b = 4, result;

    while (i < 3)//I used the three nummbers you had in the lab (2^4, 3^3 and 5^4)
    {
        cout << "Enter two numbers with a space in-between and press <Enter>: " << endl;
        cin >> a >> b;
        result = pow(a,b);
        cout << a << " to the power of " << b << " is = " << result << endl;
        i++;
    }

    cout << endl;
    system ("pause");
    return 0;
}
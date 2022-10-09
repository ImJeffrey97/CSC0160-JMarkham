//Section CSC160 - Computer Science I: C++
//File Name: p7_3.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 7
//Description: This program illustrates throwing an exception inside a function
//Last Changed: 04/27/2021

#include <iostream>
#include <cstdlib>
using namespace std;

class DivideByZero
{};

double safe_divide(int top, int bottom) throw(DivideByZero);

int main()
{
    int numerator;
    int denominator;
    double quotient;

    cout << "Enter numerator:\n";
    cin >> numerator;
    cout << "Enter denominator:\n";
    cin >> denominator;

    try
    {
        quotient = safe_divide(numerator,denominator);
    }

    catch(DivideByZero)
    {
        cout << "Error: Division by zero!\n"
             << "Program aborting.\n";
        exit(0);
    }

    cout << numerator << "/" << denominator
         << " = " << quotient << endl;
    
    cout << "End of program.\n";

    cout << endl;
    system ("pause");
    return 0;
}

double safe_divide(int top, int bottom) throw(DivideByZero)
{
    if(bottom == 0)
    {
        throw DivideByZero();
    }
    return top/double(bottom);
}

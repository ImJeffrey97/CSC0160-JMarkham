//Section CSC160 - Computer Science I: C++
//File Name: Ex72.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 7
//Description: Program to solve quadratic equation
//Last Changed: 04/27/2021

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;// coefficient of ax^2 + bx + c = 0
    double x1, x2; // The two roots
    double temp;

    try
    {
        cout << "Enter the three coefficients \n";
        cin >> a >> b >> c;

        if(a !=0)
        {
            temp = b * b - 4 * a * c;
            if(temp >= 0)
            {
                //Two roots
                x1 = (-b + sqrt(temp)) / 2 * a;
                x2 = (-b - sqrt(temp)) / 2 * a;
                cout << "The two roots are: " << x1 << " and " << x2 << endl;
            }
            else
            {
                cout << "Square root of negative values is not defined \n";
                exit(1);
            }
        }
        else
        {
            cout << "Division by zero, not defined \n";
            exit(1);
        }
    }

    catch(int e)
    {
        cout << e <<  "The numbers you have chosen do not work with this equation";
    }
    
    cout << endl;
    system ("pause");
    return 0;
}
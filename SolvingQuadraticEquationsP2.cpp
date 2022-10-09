//Section CSC160 - Computer Science I: C++
//File Name: Ex73.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 7
//Description: Program to solve quadratic equation
//Last Changed: 04/27/2021

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void all_zero();
void roots(double a, double b, double c);

int main()
{
    double a, b, c; //coefficient of ax^2+bx+c=0
    try
    {
        cout << "Enter the three coefficients \n";
        cin >> a >> b >> c;
        roots(a, b, c);
    }
    
    catch(int e)
    {
        cout << e << " Square root of negative value is not defined.\n";
        exit(1); 
        cout << " Division by zero is not defined \n";
    }
    cout << endl;
    system ("pause");
    return 0;
}

void all_zero()
{
    exit(1);
}

void roots(double a, double b, double c)
{
    
    double x1, x2;//The two roots
    double temp;

    if(!(a==0 && b==0 && c==0))
    {
        if (a !=0)
        {
            temp = b * b - 4 * a * c;
            if(temp >= 0)
            {
                //Two roots
                x1 = (-b + sqrt(temp)) / 2 * a;
                x2 = (-b - sqrt(temp)) / 2 * a;
                cout << "The two roots are: " << x1 << " and " << x2 << endl;
            }
        }
    }
}
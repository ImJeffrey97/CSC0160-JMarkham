//Section CSC160 - Computer Science I: C++
//File Name: Ex74.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 7
//Description: 
//Last Changed: 04/21/2021 

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void all_zero();
void roots(double a, double b, double c);
 
int main()
{
    double a, b, c; //coefficient of ax^2+bx+c=0

    cout << "Enter the three coefficients.\n";
    cin >> a >> b >> c;

    roots(a,b,c);

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

    if(!(a == 0 && b == 0 && c == 0))
    {
        if (a != 0)
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
                cout << "Square root of a negative values is not defined \n";
                exit(1);
            }
        }
        else
        {
            cout << "Division by zero, not defined \n";
            exit(1);
        }
    }
    else
    {
        all_zero();
    }
    if(a < 0)
    throw a;

    if (b*b < 4*a*c)
    throw temp;
}

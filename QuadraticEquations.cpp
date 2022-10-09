//Section CSC160 - Computer Science I: C++
//File Name: PS3 
//Student: Jeffrey Markham
//Homework Number: Ps3 
//Description: creating a program to solve many sets if quadratic equations
//Last Changed:

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a;
    double b;
    double c;
    double d;
    double x1;
    double x2;

    cout << "Enter 3 values and then press <Enter> after every value" << endl;;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a == 0)
    {
        cout << "Not a quadratic equation\n";
        if (b == 0)
        {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "Bye" << endl; 
        }
        else 
        {
            x1 = -c / b;
            cout << "Answer is: " << x1 << endl;
        }
    }
    else
    {
        d = (b * b) - 4 * a * c;
    }
    if (d < 0)
    {
        cout << "No Real Answer. Failed to take the square root of Negative value." << endl;
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a); 
        x2 = (-b - sqrt(d)) / (2 * a);
        cout << "The two roots are " << x1 << " and " << x2 << endl;
    }
    
    cout << endl;
    system ("pause");
    return 0;
}
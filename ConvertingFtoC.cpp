//Section CSC160 - Computer Science I: C++
//File Name: ex5_5.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 5
//Description: converting fahrenheit to celsius
//Last Changed: 03/24/2021

#include <iostream>
using namespace std;


int main()
{
    int t_in_fah, t_in_cel;//Notice that we declared these two as integers, not the best choice

    cout << "Enter a temperature in Fahrenheit \n";
    cin >> t_in_fah;

    t_in_cel = static_cast<float>(5) / 9 * (t_in_fah - 32);
    cout << "The temperature in Celsius is: " << t_in_cel << endl;

    cout << endl;
    system ("pause");
    return 0;
}
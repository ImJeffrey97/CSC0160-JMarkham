//Section CSC160 - Computer Science I: C++
//File Name: Lab 4 P4_2
//Student: Jeffrey Markham
//Homework Number: P4_2
//Description: An array element as an argument to a function 
//Last Changed: 02/27/2021

#include <iostream>
using namespace std;

void get_grade (int& grade);
//Obtains a grade from the user and stores it in paramater, grade.

int main()
{
    int grades[5];
    int i;

    cout << "Enter 5 grades \n";

    for (i = 0; i < 5; ++i) //read, store values one-by-one
    {
        get_grade(grades[i]);
    }       

    for ( i = 0; i < 5; ++i) //Displays the array
    {
        cout << "grade[" << i << "] = " << grades[i] << endl;
    }
    cout << endl;
    system ("pause");
    return 0;
}
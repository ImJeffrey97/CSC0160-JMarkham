//Section CSC160 - Computer Science I: C++
//File Name: P4_2a
//Student: Jeffrey Markham
//Homework Number: P4_2a 
//Description: Modified version of P4_2 
//Last Changed: 03/03/2021

#include <iostream>
using namespace std;

void get_grade(int grade[]);

int main()
{
    int grades[5];
    int i;

    cout << "Enter 5 grades \n";
    get_grade(grades);//can read, modify all elements
    for (i = 0; i < 5; ++i)//Displays the array
    {
        cout << "grade[" << i << "] = " << grades[i] << endl;
    }
    cout << endl;
    system ("pause");
    return 0;
}

void get_grades(int grade[])
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "Input a grade between 0 and 100: ";
        cin >> grade;
    }
}
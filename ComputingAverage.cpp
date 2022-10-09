//Section CSC160 - Computer Science I: C++
//File Name: ex33_1 
//Student: Jeffrey Markham
//Homework Number: Exercise ex33_1
//Description: computing the average of 100 numbers
//Last Changed:

#include <iostream>
using namespace std;

int main()
{
    int x;
    int count = 0; //(1) initialize a counter to 0 to count number of grades
    double sum = 0; //initilaize the sum to 0 to make sure the sum at the beginning is 0;
    double average;
    
    //promt the user: 
    cout << "Enter 100 gardes separated by a single space then press <enter>: ";
    while (count < 100) //(2) read 100 grades and compute their sum count ensures 100 entries
    {
        //read each number and compute the sum:
        cin >> x;
        sum = sum + x;
        count++; //(3)update the count
    }
    cout << endl;
    
    average = sum / 100; //compute the average, total divided by the number of grades
    cout << "the average is " << average << endl;

    cout << endl;
    system ("pause");
    return 0;
}
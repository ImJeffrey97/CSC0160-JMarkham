//Section CSC160 - Computer Science I: C++
//File Name: Lab 4 p4_1a
//Student: Jeffrey Markham
//Homework Number: p4_1a
//Description: This program illustrates array index out of range
//Last Changed: 02/24/2021

#include <iostream>
using namespace std;

int main(void)
{
    int numlist[8], i;

    cout << " \t i \t numlist[i] \n";
    cout << " \t ===== \t ======== \n";
    for (i = 0; i <= 8; i++)
    {
        numlist[i] = i * 2;
        cout << " \t " << i << "\t " << numlist[i] << endl;
    }

    cout << endl;
    system ("pause");
    return 0;
}
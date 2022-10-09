//Section CSC160 - Computer Science I: C++
//File Name: PS1 (Post Lab 1)
//Student: Jeffrey Markham
//Homework Number: Lab 1
//Description: producing hello in a pattern
//Last Changed: 01/29/2021

#include <iostream>
using namespace std;

int main()
{

    string yourFirstName;
    string yourLastName;

    cout << "My Name is" << yourFirstName << " " << yourLastName;
    cin >> yourFirstName;
    cin >> yourLastName;

    cout << "        Hello" << endl;
    cout << "    Hello   Hello" << endl;
    cout << "Hello   Hello   Hello" << endl;
    cout << "    Hello   Hello" << endl;
    cout << "        Hello" << endl;
    cout << "Bye" << endl;

    cout << endl;
    system ("pause");
    return 0;
}
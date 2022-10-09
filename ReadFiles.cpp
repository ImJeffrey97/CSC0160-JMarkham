//Section CSC160 - Computer Science I: C++
//File Name: P61.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 6 
//Description: This program reads some integers from a file
//displays: the number, number^2, and the sum of all numbers
//up to that point
//Last Changed: 04/12/2021 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int x, count = 0;
    float sum = 0, avg;
    char input_file[15];
    ifstream in_s;
    ofstream in_o;
    
    cout << "Please input the input file name \n";
    cin >> input_file;
    in_s.open(input_file);

    cout << "Please input the output file name \n";
    cin >> input_file;
    in_o.open(input_file);

    if (in_s.fail())
    {
        cout << "Input file opening failed. \n";
        exit(1);
    }

    if (in_o.fail())
    {
        cout << "Output file opening failed. \n";
        exit(1);
    }

    in_o << "\t x \t x^2 \t\t Current Sum \n";
    in_o << "\t ==== \t\t ==== \t\t ========= \n";

    while (in_s >> x)
    {
        sum = sum + x;
        in_o << "\t" << x << "\t\t" << pow(x,2) << "\t\t" << sum << "\n";
        count++;
    }

    avg = sum/count;
    in_o << "\n \t\t The average of these" << count << "number is: " << avg << endl;
    in_s.close();
    in_o.close();
    
    cout << endl;
    system ("pause");
    return 0;
}
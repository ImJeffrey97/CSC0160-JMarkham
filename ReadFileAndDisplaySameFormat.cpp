//Section CSC160 - Computer Science I: C++
//File Name: P64.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 6
//Description: This program reads the entire contents
//of an input file and will display it with the same format.
//Last Changed: 04/16/2021

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void get_input_stream(ifstream& in_s);

int main()
{
    char c;
    ifstream in_s;

    get_input_stream(in_s);

    cout << "Here are the entire contents of the input file \n";
    while (in_s >> c)
    {
        cout << c;
    }
    cout << "\n I am done with writing the contents of the file \n";

    in_s.close();

    return 0;
}

void get_input_stream(ifstream& in_s)
{
    char input_file[15];
    cout << "Please input the file name \n";
    cin >> input_file;

    in_s.open(input_file);
    if(in_s.fail())
    {
        cout << "Input file opening failed. \n";
        exit(1);
    }
}
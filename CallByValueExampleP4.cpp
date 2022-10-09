//Section CSC160 - Computer Science I: C++
//File Name: P53_2.cpp 
//Student: Jeffrey Markham
//Homework Number: Lab 5
//Description: This program illustrates the local and global variables and call-by-value
//             This program computes the side area and the cross-section area of a cylinder
//Last Changed: 

#include <iostream>
#include <cmath>
using namespace std;

double PI = 3.14159;//This variable is defined globally, known to all functions in this program as PI
double cross_area(double r);//Function prototype for function cross_area
double side_area(double r, double h);//Function prototype for function Side_area

int main(void)
{
    double h, r;//variables local to the main function 

    cout << "Enter the radius and the height of the cylinder in Cm <Enter> ";
    cin >> r >> h;
    cout << endl;
    cout << "Before I do any computation or call any function, I want to let you know that \n";
    cout << "you have entered r = " << r << " and h = " << h << "." << endl;
    cout << "I am planning to use inch, thus in the first function, I will convert r, and " << endl;
    cout << "in the second one I will convert h \n";
    cout << "The cross section area of the cylinder is " << cross_area(r) << " inch-sqr" << endl;
    cout << "The side area of the cylinder is " << side_area(r,h) << " inch-sqr \n\n";

    cout << endl;
    system ("pause");
    return 0;
}

double cross_area(double r)
{
    //Cross section area includes the disks at the bottom and the top
    r = r * 0.3937;//Converting r to inch
    return 2 * PI * pow(r,2);
}

double side_area(double r, double h)
{
    double area;//variable local to Side_area function
    h = h * 0.3937;//Converting h to inch
    area = 2 * PI * r * h;
    return area;
}

//Section CSC160 - Computer Science I: C++
//File Name: P54_1.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 5
//Description: This program illustrates the local and global variables and call-by-value
//             This program computes the side area and the cross-section area of a cylinder
//Last Changed: 03/26/2021

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;//This variable is defined globally, known to all functions in this program as PI
const double CONVERSION = 0.3937;//This is the Cm to inch conversion factor
double area(double r);//Function prototype for function cross_area
double area(double r, double h);//Function prototype for function Side_area
double area(double r, double h);//Function prototype for function total_area
double volume(double r, double h);//Function prototype for function cylinder_volume

double area(double r);//Function prototype for function sphere_volume
double volume(double r);//Function prototype for function sphere_volume

int main(void)
{
    double h, r;//variables local to the main function 
    int a;//variable for user to input for his/her choice

    cout << "Enter 1 to find the side area, total area, and volume of a cylidner" << endl;
    cout << "Enter 2 to find the area and volume of a sphere" << endl;
    cin >> a;
    
    if (a == 1)
    {
        cout << "Enter the radius and the height of the cylinder in Cm <Enter> ";
        cin >> r >> h;
        cout << endl;
        cout << "Before I do any computation or call any function, I want to let you know that \n";
        cout << "you have entered r = " << r << " and h = " << h << "." << endl;
        cout << "I am planning to use inch, thus in the first function, I will convert r, and " << endl;
        cout << "in the second one I will convert h \n";
        cout << "The cross section area of the cylinder is " << area(r) << " inch-sqr" << endl;
        cout << "The side area of the cylinder is " << area(r,h) << " inch-sqr \n\n";
        cout << "The total area of the cylinder is " << area(r, h) << " inch-sqr \n\n";
        cout << "The volume of the cylinder is " << volume(r,h) << " inch-sqr \n\n";
    }
    else if (a == 2)
    {
        cout << "Enter the radius of the sphere in Cm <Enter>: ";
        cin >> r;
        cout << endl;
        cout << "You have entered r = " << r << endl;
        cout << "I am planning to use inch, thus I will convert r to inches \n";
        cout << "The surface area of the sphere is " << area(r) << " inch-sqr \n\n";
        cout << "The Volume of the sphere is " << volume(r) << " inch-sqr \n\n";
    }
    else if (a != 1 || 2)
    {
        cout << "invalid choice error";
    }

    cout << endl;
    system ("pause");
    return 0;
}

double area(double r)//Function for 
{
    //Cross section area includes the disks at the bottom and the top
    r = r * 0.3937;//Converting r to inch
    return 2 * PI * pow(r,2);
}

double area(double r, double h)
{
    double area;//variable local to Side_area function
    h = h * 0.3937;//Converting h to inch
    area = 2 * PI * r * h;
    return area;
}

double area(double r, double h)
{
    //calculation for total area of a cylinder
    double area;
    area = (2 * PI * pow(r,2)) + ((2 * PI * r) * h);
    return area;
}

double volume(double r, double h)
{
    double volume;
    volume = (PI * pow(r,2)) * h;
    return volume;    
}

double area(double r)
{
    double surface_area;
    surface_area = 4 * PI * r;
    return surface_area; 
}

double volume(double r)
{
    double volume;
    volume = (4.0 / 3.0) * PI * pow(r,3);
    return volume;
}

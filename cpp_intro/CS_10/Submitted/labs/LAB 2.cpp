/*
Sean Richardson
CS 10 
LAb 2.12 (part 2)

Distance Formula Calc.
*/

//Libraries
#include <iostream>
#include <string>
#include <cmath>

//Namespace
using namespace std;

int main()
{
   
    //Variables
    double x1 = 0.0;
    double x2 = 0.0;
    double y1 = 0.0;
    double y2 = 0.0;
    double pointsDistance = 0.0;
   
    cout << "Enter the the X and Y values for the first point";
    cout << endl;
    cout << "enter first value ";
    cin >> x1;
    cout << "enter second value ";
    cin >> y1;
    
    cout << "Enter the X and Y values for the second point";
    cout << "enter first value ";
    cin >> x2;
    cout << "enter second value ";
    cin >> y2;
    
    pointsDistance = sqrt(pow(((x2)-(x1)), 2.0) + (pow(((y2)-(y1)), 2.0)));
    cout << pointsDistance; 
    cout << endl;
    
return 0;
}
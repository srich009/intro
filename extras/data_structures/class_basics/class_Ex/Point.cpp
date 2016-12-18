//point class implementation

#include <iostream>

using namespace std;

#include "Point.h"

//constructor
Point::Point()
{
    xCoord = 0.0;
    yCoord = 0.0;
}


Point::Point(double x, double y)
{
    xCoord = x;
    yCoord = y;
}

//function declarations
double Point::getX() const
{   
    return xCoord;
}

double Point::getY() const
{
    return yCoord;
}

void Point::move(double dx, double dy)
{
    xCoord = xCoord + dx;
    yCoord = yCoord + dy;
    return;
}

void Point::display() const
{
    cout << "(" << xCoord << "," << yCoord << ")";  // why ?? std:: when iostream included already??
    return;
}


//Rectangle interface file
#ifndef __RECTANGLE_H__ //inclusion guards
#define __RECTANGLE_H__

#include <iostream>

using namespace std;

#include "Point.h"

class Rectangle
{
 private:
    //How do we want to store the rectangle internally?
    Point ll;
    Point ur;
    Point ul;
    Point lr;

 public:
    //Default Rectangle 
    //located at Point (0,0) with width of 0.0 and height of 0.0
    Rectangle();
    Rectangle(const Point &lowerLeft, double width, double height);
    Rectangle(const Point &lowerLeft, const Point &upperRight);

    //Output Format - LL: (x,y), W: width, H: height
    void display() const;
    
    Point lowerLeft() const;
    Point lowerRight() const;
    Point upperLeft() const;
    Point upperRight() const;
    
    //Output Format - (x,y) (x,y)
    //                (x,y) (x,y)
    void displayCorners() const;

    //Move's the entire rectangle 
    // dx units in the x direction,
    // dy units in the y direction
    void move(double dx, double dy);
    
    void changeWidth(double perc); //keeps lower left stationary
    void changeHeight(double perc); //keeps lower left stationary
    double width() const;
    double height() const;
    double area() const;
    double perimeter() const;
};

#endif
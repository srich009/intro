// Rectangle implementation file

#include <iostream>

using namespace std;

#include "Point.h"
#include "Rectangle.h"

 //   Point ll;
 //   Point ur;
 //   Point ul;
 //   Point lr;



 //public:
 //   //Default Rectangle 
 //   //located at Point (0,0) with width of 0.0 and height of 0.0

Rectangle::Rectangle()
{ }


Rectangle::Rectangle(const Point &lowerLeft, double width, double height)
    : ll(lowerLeft),
      ur(Point( lowerLeft.getX() + width, lowerLeft.getY() + height )),
      ul(Point(lowerLeft.getX(), lowerLeft.getY() + height) ),
      lr(Point( lowerLeft.getX() + width, lowerLeft.getY() ) )
{
}



Rectangle::Rectangle(const Point &lowerLeft, const Point &upperRight) 
 : ll(lowerLeft), ur(upperRight),
   ul(Point(ll.getX(), ur.getY())),
   lr(Point(ur.getX(), ll.getY()))
{ 

	
}

 //   //Output Format - LL: (x,y), W: width, H: height
 //   void display() const;
    
 //   Point lowerLeft() const;
 //   Point lowerRight() const;
 //   Point upperLeft() const;
 //   Point upperRight() const;
 
     
    //Output Format - (x,y) (x,y)
    //                (x,y) (x,y)
void Rectangle::displayCorners() const {
	ul.display(); cout << ' '; ur.display(); cout << endl;
	ll.display(); cout << ' '; lr.display();
}

//===================================================

 //   //Move's the entire rectangle 
 //   // dx units in the x direction,
 //   // dy units in the y direction
 //   void move(double dx, double dy);
 //   void changeWidth(double perc); //keeps lower left stationary
 
 
   void Rectangle::changeHeight(double perc) //keeps lower left stationary
   {
        ul = Point( ul.getX(), (ul.getY() + perc) );
        ur = Point( ur.getX(), (ul.getY() + perc) );
       
       return;
   }
 

 
    double Rectangle::height() const
    {
        double hh = ur.getY() - ll.getY();
        return hh;
    }
 
 //   double width() const; 
 //   double area() const;
 //   double perimeter() const;

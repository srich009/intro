#include <iostream>

using namespace std;

#include "Point.h"
#include "Rectangle.h"

int main()
{
    Point p1 = Point(1.0, 2.0);
    Point p2 = Point(2.0, 3.0);
    
    cout << p1.getX() << endl;
    cout << p2.getX() << endl;

    p2.display(); cout << endl;
    
return 0;
}
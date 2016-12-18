// point class (interface) header
#ifndef __POINT_H__ //inclusion guards
#define __POINT_H__


class Point
{
    private:
        double xCoord;
        double yCoord;
    
    public:
        Point(); // default constructor
        Point(double, double); // constructor
        double getX() const; // accessor prototype
        double getY() const; // accessor
        void move(double, double); // mutator has no const 
        void display() const;
};

#endif
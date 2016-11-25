#include <iostream>
#include <cmath> //??

using namespace std;

#include "Distance.h"

//Distance class uses 
// private variables: unsigned feet, double inches


//Constructors

    
    Distance::Distance()  //Default (0 feet and 0.0 inches)
    {
        feet = 0;
        inches = 0.0;
        return;  
    }


    Distance::Distance(unsigned ft, double in)  
    {
        feet = ft;
        inches = in;
        this-> init();
        return;
    }
    /* Constructs a distance of ft feet and in inches,
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
    */



    Distance::Distance(double in)
    {
        feet = 0;
        inches = in;
        this-> init();
        return;
    }
    /* Constructs a distance of 0 ft and in inches, 
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
    */

//Functions

    unsigned Distance::getFeet() const
    {
        return feet;
    }
    /* Returns just the feet portion of the Distance
    */


    double Distance::getInches() const
    {
        return inches;
    }
    /* Returns just the inches portion of the Distance
    */


    double Distance::distanceInInches() const
    {
        double un2dub = static_cast<double>(feet);
        return (un2dub * 12) + inches;
    }
    /* Returns the entire distance as the equivalent amount of inches.
        (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
    */


    double Distance::distanceInFeet() const
    {
        double un2dub = static_cast<double>(feet);
        return un2dub + (inches / 12);
    }
    /* Returns the entire distance as the equivalent amount of feet.
        (e.g., 3 feet 6 inches would be returned as 3.5 feet)
    */


    double Distance::distanceInMeters() const
    {
        double un2dub = static_cast<double>(feet); 
        double totIN = (un2dub * 12) + inches;
        return (totIN * .0254);
    }
    /* Returns the entire distance as the equivalent amount of meters.
        1 inch equals 0.0254 meters.
        (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
    */


    const Distance Distance::operator+(const Distance &rhs) const
    {
        Distance noo;
        noo.inches = inches + rhs.inches;
        noo.feet = feet + rhs.feet;
        noo.init();
        
        return noo;
    }
    /* Returns the sum of 2 Distances.
    */


    const Distance Distance::operator-(const Distance &rhs) const  //FIXME minus -
    {        
               
        return Distance(distanceInInches() - rhs.distanceInInches());

    }
    /* Returns the difference between 2 Distances.
    */


    ostream & operator<<(ostream &out, const Distance &rhs)  //Friend function
    {
        out << rhs.feet << "' " << rhs.inches << "\"";
        return out;
    }
    /* Outputs to the stream out the Distance in the format: 
        feet' inches'' (i.e. 3' 3.41'')
    */
    
    
    //private:
  
    void Distance::init()
    {
        
            //correct negative INCHES
            if(inches < 0)
            {
                inches = abs(inches);
            }
            
            //CORRECT NEGATIVE FEET
            int x = static_cast<int>(feet);
            
            if(x < 0)
            {
                feet = abs(x);
            }
        
            //correct if over 12 inches
            if(inches >= 12)
            {
                int temp = static_cast<int>(inches) / 12;
                
                inches = inches - (12 * temp);
                feet = feet + static_cast<unsigned>(temp);
                
            }
            else
            {
                feet = feet;
                inches = inches;
            }
                    
        return;
    }

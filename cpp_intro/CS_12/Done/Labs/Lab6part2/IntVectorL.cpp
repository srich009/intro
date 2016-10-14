// implementation of class

#include "IntVectorL.h" // changed header name

#include <iostream>
#include <stdexcept>

using namespace std;

// private:
//     unsigned sz; //size of elements currently used
//     unsigned cap; //capacity of elements can hold
//     int *data;  //stores the address of the dynamically-allocated array of integers  
 
    
//public: INTERFACE

//constructors
    IntVector::IntVector()
    {
        sz = 0;
        cap = 0;
        data = 0;
        
    }
    /*
    This function should set both the size and capacity of the IntVector to 0 and will not allocate any memory to store integers.
    (Make sure you do not have a dangling pointer.)
    */
    
    IntVector::IntVector(unsigned size)
    {
         sz = size;
         cap = size;
         data = new int[size];
        for(unsigned int i = 0; i < sz; i++)
        {
            data[i] = 0;
        }
        
    }
    
    IntVector::IntVector(unsigned size, int value)
    {
        sz = size;
        cap = size;
        data = new int[size];
        for(unsigned int i = 0; i < sz; i++)
        {
            data[i] = value;
        }
        
    }
    /*
    Sets both the size and capacity of the IntVector to the value of the parameter passed in 
    and dynamically allocates an array of that size as well.
    This function should initialize all elements of the array to the value of the 2nd parameter.
    */
    
//destructor
    IntVector::~IntVector()
    {
        delete[] data;
    }
    /*
    The destructor is used to clean up (delete) any remaining dynamically-allocated memory.
    For this class, that will be the array pointed to by the int pointer called data.
    */
    
//functions
    unsigned IntVector::size() const
    {
        return sz;
    }
    //This function returns the current size (not the capacity) of the IntVector object, which is the values stored in the sz data field.
    
    unsigned IntVector::capacity() const
    {
        return cap;
    }
    //This function returns the current capacity (not the size) of the IntVector object, which is the value stored in the cap data field.
    
    bool IntVector::empty() const
    {
        if(sz == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    const int & IntVector::at(unsigned index) const
    {
        if(index >= sz)
        {
            throw out_of_range("IntVector::at_range_check");
        }
        else
        {
            return data[index];
        }
        
    }
    //This function will return the value stored in the element at the passed in index position. 
    //Your function should throw an outofrange exception if an invalid index is passed in. An invalid index is an index greater than or equal to the size.
    
    const int & IntVector::front() const
    {
        return data[0];   
    }
    //
    
    const int & IntVector::back() const
    {
        return data[sz -1];
    }
    //

// definitions of class

#ifndef __INTVECTORL_H__  //changed header name
#define __INTVECTORL_H__ // changed ""

#include <stdexcept>

class IntVector
{
    private:
        unsigned sz; //size of elements currently used
        unsigned cap; //capacity of elements can hold
        int *data;  //stores the address of the dynamically-allocated array of integers     
        
    public: 
        IntVector();
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
  
};

#endif
// definitions of class

#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

#include <stdexcept>

class IntVector
{
    private:
        unsigned sz; //size of elements currently used
        unsigned cap; //capacity of elements can hold
        int *data;  //stores the address of the dynamically-allocated array of integers  
        
        //functions
        void expand();
        void expand(unsigned amount);
        
    public: 
        //constructors
        IntVector();
        IntVector(unsigned size);
        IntVector(unsigned size, int value); //value = 0??
        
        //destructor
        ~IntVector();
        
        //accessors
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
        
        //mutators
        int & at(unsigned index);
        int & front();
        int & back();
        
        void insert(unsigned index, int value);
        void erase(unsigned index);
        void assign(unsigned n, int value);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size); //???? see below???
        void resize(unsigned size, int value); //value =0??
        void reserve(unsigned n);
          
};

#endif
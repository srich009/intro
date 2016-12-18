//IntVector inplementation

#include "IntVector.h"

#include <iostream>
#include <stdexcept>

using namespace std;


/*
private:
unsigned sz;    //number if elements being used
unsigned cap;   //amouunt of elements array can hold
int* data;      //pointer to dynamicly allocated array
*/


//PRIVATE FUNCTIONS
    void IntVector::expand()
    {
        if(cap == 0) //if empty vector
        {
            cap++;
        }
        else
        {
            cap *= 2;
        }
        
        //pointer to new dynamically allocated array
        int* temp = new int[cap]; 
        
        //copy data to new array
        for(unsigned int i = 0; i < sz; i++)
        {
            temp[i] = data[i];
        }
        
        //delete old array & point data to temp
        delete[] data;
        data = temp;
        
        return;
        
    }
    //_____________________________________________
    
    void IntVector::expand(unsigned amount)
    {
        cap += amount;
        
        int* temp = new int[cap];
        
        for(unsigned int i = 0; i < sz; i++)
        {
            temp[i] = data[i];
        }
        
        delete[] data;
        data = temp;
        
        return;
    }
    //______________________________________________

//PUBLIC:
///CONSTRUCTORS && DESTRUCTOR
    IntVector::IntVector() //default constructor
        : sz(0), cap(0), data(0)
    {}
    //__________________________________________________
    
    IntVector::IntVector(unsigned size, int value) //default value = 0
        : sz(size), cap(size), data(0)
    {
        data = new int[size];
        for(unsigned int i = 0; i < size; i++)
        {
            data[i] = value;
        }
    }
    //______________________________________________________
    
    IntVector::~IntVector()  //destructor
    {
        delete[] data; // delete array
    }
//===========================================================
//===========================================================


///ACCESSORS
    unsigned IntVector::size() const // return size
    {
        return this->sz;
    }
    //_______________________________________________________
    
    unsigned IntVector::capacity() const  //return capacity
    {
        return this->cap;
    }
    //____________________________________________________________
    
    bool IntVector::empty() const // true if no elements stored
    {
        if(this->sz == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //____________________________________________________________
    
    const int& IntVector::at(unsigned index) const
    {
        if(index >= this->sz)
        {
            throw out_of_range("IntVector::at_range_check");
        }
        else
        {
            return data[index];
        }
    }
    //_______________________________________________________________
    
    const int& IntVector::front() const
    {
        return data[0];
    }
    //______________________________________________________________
    
    const int& IntVector::back() const
    {
        return data[sz - 1];
    }
    //=====================================================
    //=====================================================
    
//MUTATORS
    int& IntVector::at(unsigned index)
    {
        if(index >= this->sz)
        {
            throw out_of_range("IntVector::at_range_check");
        }
        else
        {
            return data[index];
        }
    }
    //__________________________________________________________
    
    int& IntVector::front()
    {
        return data[0];
    }
    //___________________________________________________________
    
    int& IntVector::back()
    {
        return data[sz-1];
    }
    //__________________________________________________________
    
    void IntVector::push_back(int value)
    {
        if(sz == cap)
        {
            this->expand();
        }
        
        sz += 1;
        data[sz-1] = value;
        
        return;
    }
    //_________________________________________________________
    
    void IntVector::pop_back()
    {
        if(sz != 0)
        {
            sz = sz-1;
        }
        return;
    }
    //________________________________________________________
    
    void IntVector::clear()
    {
        this->sz = 0;
        return;
    }
    //___________________________________________________________
    
    void IntVector::erase(unsigned index)
    {
        if(index >= sz)
        {
            throw out_of_range("IntVector::erase_range_check");
            return;
        }
        
        if(sz == 1) // sz == 1
        {
            sz--;
            return;
        }
        else if(index == sz - 1) // erase last element
        {
            this->pop_back();
            return;
        }
        
        for(unsigned i = index; i < sz; i++)
        {
            data[i] = data[i + 1];
        }
        
        sz--;
        
        return;
    }
    //_________________________________________________________
    
    void IntVector::reserve(unsigned n)
    {
        if(cap == 0)
        {
            cap = n;
            return;
        }
        else if(n > cap)
        {
            if((cap * 2) > (n))
            {
                expand();
            }
            else
            {
                expand(n - cap); 
            }
        }
        return;
    }
    //____________________________________________________________
    
    void IntVector::assign(unsigned n, int value)
    {
        //expand cap if not big enough
        if(this->cap < n)
        {
            if((cap * 2) > (n))
            {
                expand();
            }
            else
            {
                expand(n - cap); 
            }
        }
        
        this->clear();
        this->sz = n;
        
        for(unsigned i = 0; i < n; i++)
        {
            this->at(i) = value;
        }
        
        return;
    }
    //_______________________________________________________________
    
    void IntVector::insert(unsigned index, int value)
    {
        //catch exceptions
        if(index > sz)
        {
            throw out_of_range("IntVector::insert_range_check");
            return;
        }
        
        //increase if cap is full
        if(this->sz == this->cap )
        {
            this->expand(); 
        }
            
        //increase size by one
        this->sz++;
        
        //shift elements && then assign at index
        for(unsigned int i = sz-1; i > index; --i)
        {
            this->at(i) = this->at(i-1);
        }
        this->at(index) = value;
        
        return;
    }
    //_________________________________________________________________
    
    void IntVector::resize(unsigned size, int value) //default value = 0
    {
        if(size <= this->sz)
        {
            this->sz = size;
            return;
        }
        else if(this->cap < size)
        {
            if((cap * 2) > size)
            {
                expand();
            }
            else
            {
                expand(size-cap);
            }
        }
        
        unsigned ppp = this->sz;
        
        this->sz = size;
        
        for(unsigned i = ppp; i < size; i++ )
        {
            this->at(i) = value;
        }
        
        return;
    }

    
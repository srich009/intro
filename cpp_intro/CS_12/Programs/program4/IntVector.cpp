// implementation of class
#include "IntVector.h"

#include <iostream>
#include <stdexcept>

using namespace std;

// private:
//     unsigned sz; //size of elements currently used
//     unsigned cap; //capacity of elements can hold
//     int *data;  //stores the address of the dynamically-allocated array of integers  

    void IntVector::expand()
    {   
        if(cap == 0)
        {
            cap = 1;
            
        }
        else
        {
            cap = cap * 2;
        }
        
        int *tempPoint = 0; //null point
        
        tempPoint = new int[cap]; // now points to new array
        
        for(unsigned i = 0; i < sz; i++)
        {
            tempPoint[i] = data[i]; //new contains old data
        }
          delete[] data;  //delete old array
          data = tempPoint;
        
    }
    //This function will double the capacity of the vector.
    //This function should reallocate memory for the dynamically allocated array
    //and update the value of capacity. Be careful to properly handle the case when capacity is 0 before calling expand().
    //Make sure you don't create a memory leak here.
    
    void IntVector::expand(unsigned amount)
    {
        cap += amount;
        
        int *tempPoint = 0; //null point
        
        tempPoint = new int[cap]; // now points to new array
        
        for(unsigned i = 0; i < sz; i++)
        {
            tempPoint[i] = data[i]; //new contains old data
        }
          delete[] data;  //delete old array
          data = tempPoint;
        
    }
    //This function will expand the capacity of the vector by the amount passed in.
    //This function should reallocate memory for the dynamically allocated array 
    //and update the value of capacity.
    //Make sure you don't create a memory leak here.
 

//=============================================================================================
//==============================================================================================
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
    
//-----------------------------------------------------------------------------------------------------------------------------    
//destructor
    IntVector::~IntVector()
    {
        delete[] data;
    }
    /*
    The destructor is used to clean up (delete) any remaining dynamically-allocated memory.
    For this class, that will be the array pointed to by the int pointer called data.
    */
//---------------------------------------------------------------------------------------------------------------------------------
    
//CONST functions (accessor)
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
//------------------------------------------------------------------------------------------------------------------------

//Mutator functions

    int & IntVector::at(unsigned index) //at
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
    
    int & IntVector::front() // front
    {
        return data[0];
    }
    
    int & IntVector::back() // back
    {
        return data[sz -1]; 
    }
    

    void IntVector::insert(unsigned index, int value)
    {
        if(index > sz)
        {
            throw out_of_range("IntVector::insert_range_check");
        }
        
        if(sz == cap)
        {
            expand();
        }
        sz++;
        for(unsigned int i = sz; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        
        return;
    }
    
    void IntVector::erase(unsigned index) //XXXXX
    {
            if(index >= sz)
            {
                throw out_of_range("IntVector::erase_range_check");
            }
            else if(index == 0)
            {
                for(unsigned int i = 0; i < sz; i++)
                {
                    data[i] = data[i + 1];
                }
                sz = sz - 1;
            }
            else if(index == sz - 1)
            {
                sz = sz - 1;
            }
            else
            {
                for(unsigned int i = index; i < sz; i++)
                {
                    data[i] = data[i + 1];
                }
                sz = sz - 1;
            }
        
        
        return;
    }

    
    void IntVector::assign(unsigned n, int value)
    {
        /*Assigns new content to the vector object,
        dropping all the elements contained in the vector before the call
        and replacing them by those specified by the parameters. 
        The new value of size will be n 
        and all values stored in the vector will have the value of the 2nd parameter.
        */
        
        if(n > cap)
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
        
        sz = n;
        for(unsigned int i = 0; i < sz; i++)
        {
            data[i] = value;   
        }
        
        
        return;
    }
    
    void IntVector::push_back(int value) //XXXX
    {
        if(sz == cap)
        {
          expand();  
        }
        
        data[sz] = value;
        sz += 1;
        
        return;
    }
    
    void IntVector::pop_back() //XXXX
    {
        if(sz != 0)
        {
            sz = sz - 1;
        }
        
        return;
    }
    
    void IntVector::clear() //XXXX
    {
        sz = 0;
        
        return;
    }
    
    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
     void IntVector::resize(unsigned size) //?? not sure
     {
        unsigned int k = sz;
        
        if(sz >= size && size < cap) 
        {
            for(unsigned int i = 0; i < sz - k; i++) 
            {
    
                data[k + i] = 0;
             
            }
            sz = size;
             return;
        }
        else
        {
            if(sz == 0)
            {
                k = 0;
            }
            
            
            if((cap * 2) < (size)) //switch expands
            {
             expand(size - cap); 
                
            }
            else
            {
               expand(); 
            }
            
        }
                sz = size;
        for(unsigned int i = 0; i < sz - k; i++) 
        {

            data[k + i] = 0;
         
        }
        
        return;
     }
    
    void IntVector::resize(unsigned size, int value) 
    {
        unsigned int k = sz;
        
        if(sz >= size) 
        {
         sz = size;   
         return;
        }
        else
        {
            if(sz == 0)
            {
                k = 0;
            }
            
            
            if((cap * 2) < (size)) //switch expands
            {
             expand(size - cap); 
                
            }
            else
            {
               expand(); 
            }
            
        }
                sz = size;
        for(unsigned int i = 0; i < sz - k; i++) 
        {

            data[k + i] = value;
         
        }
        
        return;
    }
    
    void IntVector::reserve(unsigned n) //XXXXXX
    {
        if(cap == 0)
        {
            cap = n;
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
    
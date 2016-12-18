//IntVector class definition

#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

#include <iostream>
#include <stdexcept>

using namespace std;

class IntVector
{
    private:
        unsigned sz;    //number if elements being used
        unsigned cap;   //amouunt of elements array can hold
        int* data;      //pointer to dynamicly allocated array
    
        void expand();
        void expand(unsigned amount);
    
    public:
        ///CONSTRUCTORS && DESTRUCTOR
        IntVector(); //default constructor
        
        IntVector(unsigned size, int value = 0); //default value = 0
        
        ~IntVector();  //destructor
        
        ///ACCESSORS
        unsigned size() const; // return size
        
        unsigned capacity() const;  //return capacity
        
        bool empty() const; // true if no elements stored
        
        const int& at(unsigned index) const; //return value stored in index
        
        const int & front() const; //return value stored in first
        
        const int & back() const; //return value stored in last
        
        //MUTATORS
        int & at(unsigned index); //return value stored in index
        
        int & front();  //return value stored in first

        int & back();  //return value stored in last
        
        void push_back(int value); // attach element to end
        
        void pop_back(); // remove last element
        
        void clear();// set sz = 0
        
        void erase(unsigned index); // remove value at index && sz-1
        
        void reserve(unsigned n); // minimum cap = n (indicate planned increase in size)
        
        void assign(unsigned n, int value);
            /*
            Assigns new content to the vector object, dropping all the elements contained in the vector before the call and replacing them by those specified by the parameters. 
            The new value of size will be n and all values stored in the vector will have the value of the 2nd parameter.
        
            If the new value of size will be larger than capacity, then this function must first expand capacity 
            by either double (expand()) or by increasing the capacity by a specific amount (expand(n - cap)), whichever results in the largest capacity.
            */
        
        void insert(unsigned index, int value);
            /*
            This function inserts data at position index.
            all values currently at position index and greater are shifted to the right by 1 (to the element right after its current position).
            
            Size will be increased by 1. However, If size will become larger than capacity, this function needs to first double the capacity.
            In other words, if capacity and size are both 20 when this function is called, this function must first increase the capacity to 40
            and then it will be able to increase the size to 21.
            
            Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see above) to do this for you.
            
            This function should throw an out_of_range exception, passing it the string "IntVector::insert_range_check" if the index is too large.    
            */
        
        void resize(unsigned size, int value = 0); //default value = 0
            /*
            This function resizes the vector to contain size elements.
    
            If size is smaller than the current size(sz), this function just reduces the value of sz to size.
            
            If size is greater than the current size(sz), then the appropriate number of elements are inserted at the end of the vector,
            giving all of the new elements the value passed in through the 2nd parameter (value).
            
            If the new value of size will be larger than capacity, then the capacity must first be expanded by 
            either doubling (expand()) or by increasing the capacity by a specific amount (expand(size - cap)), whichever results in the largest capacity.
            Then, this function can then increase the size appropriately.
            */
            
};


#endif // __INTVECTOR_H__
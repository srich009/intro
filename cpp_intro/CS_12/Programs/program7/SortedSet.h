///SortedSet Definition file

#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

#include "IntList.h"

#include <iostream>

using namespace std;

class SortedSet : public IntList
{
    ///ALSO: inherted IntList member functions
    
    private:
       //?????? none for now...

    
    public:
        ///CONSTRUCTORS && DESTRUCTOR
        SortedSet();
        // The default constructor initializes an empty set.
        
        SortedSet(const SortedSet&);
        /*
        The copy constructor initializes the set to be a copy of the set passed in. Use the IntList copy constructor
        */
        
        SortedSet(const IntList&);
        /*
        A copy constructor that is passed an IntList instead of a SortedSet. It should initialize the set using the values in the IntList.
        Again, you can use the IntList copy constructor and then remove all of the duplicates and sort the remaining values.
        */
    
        ~SortedSet();
        /*
        deallocate all dynamically allocated memory that the IntList destructor will not already deallocate.
        You may very well find that this function does not need to do anything.
        */
    
        
        ///ACCESSORS
        // ?? const after each function non-capable of data mutation?? 
        
        bool in(int data) const;
        //This function returns true if the value in data is a member of the set, otherwise false.
                
        const SortedSet operator|( const SortedSet &rhs ) const;
        /* This function returns a SortedSet object that is the union of 2 SortedSet objects,
            the left and right operands of this binary operator.
            A union of 2 sets is a set that consists of all of the distinct elements of both sets combined.
            That is, all of the values in both sets, minus any duplicates.
            sset1 = sset2 | sset3;
        */    
    
        const SortedSet operator&( const SortedSet &rhs ) const;
        /*
            This function returns a SortedSet object that is the intersection of 2 SortedSet objects,
            the left and right operands of this binary operator.
            An intersection of 2 sets is a set of all elements that are in both sets. 
            That is, all of the values that are in both the left operand and the right operand.
            sset1 = sset2 & sset3;
            
            DO NOT call remove_duplicates inside this funtion.
        */
        
        
        
        ///MUTATORS
        void add(int data);
        /*
             This function adds the value in data to the set. 
             It needs to make sure data does not already exist in the set (no duplicates) 
             and that it is inserted in the proper position (in ascending order).
            
            This must be an O(n) operation essentially meaning only going through the list once 
            looking for the location to add the new value and then inserting it 
            only if that location does not already have the value located there. 
     
            So, this function is basically the insert_ordered function from your IntList, only you don't insert duplicates.
        */
    
        void push_front(int value);
        /*
            Override this function so that it inserts the value in data in the proper position (in ascending order) 
            only if the value does not already exist in the set (no duplicates).
            In other words, this function should do exactly what add does.
            The only reason we are overriding this function is so that the push_front from the IntList is not inherited
            . A user of the SortedSet should not be able to just push any value onto the front of the list.
            In fact, since this function should do exactly what add does, this function should just call add to do the work for it.  
        */
        
        void push_back(int value);
        /*
            Override this function so that it inserts the value in data in the proper position (in ascending order)
            only if the value does not already exist in the set (no duplicates).
            See specs for push_front above. The same rationale for overriding applies to this function.
        */
        
        void insert_ordered(int value);
        /*
            Override this function so that it does not insert duplicates.
            See specs for push_front above. The same rationale for overriding applies to this function.
        */
  
        const SortedSet& operator|=( const SortedSet &rhs );
        /* 
            This function is the union-assign operator function.
            It returns a union of the left and right operands, 
            but also sets the left operand's value to be that union as well. *****
            See operator| function specs above.
        */    
    
        const SortedSet& operator&=( const SortedSet &rhs );
        /*
            This function is the intersection-assign operator function. 
            It returns an intersection of the left and right operands, 
            but also sets the left operand's value to be that intersection as well.
            See operator& specs above.
            
            DO NOT call remove_duplicates inside this funtion.
        */      
        
    
};


#endif /// __SORTEDSET_H__


/*

UNSURE IF THE OPERATOR FUNCTIONS ARE CORRECT FOR BOTH ACCESSOR AND MUTATOR VERSIONS

*/
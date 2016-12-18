//Definitions of sorted set class derived from the intlist

#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

#include <iostream>

#include "IntList.h"

using namespace std;

class SortedSet : public IntList
{
  //no private members/functions
  
  //inheritance of all IntList public functions
  
  public:
    
    //CONSTRUCTORS && DESTRUCTOR
    
    SortedSet(); // default constructor of empty set
    
    ~SortedSet(); // destructor doesn't need to do anything???
    
    SortedSet(const IntList& cpy); // copy constructor from passed in intlist
    
    SortedSet(const SortedSet& cpy); // copy constructor for passed in sorted set
    
    
    //ACCESSORS
    
    
    //MUTATORS
    void add_val(int v);  // new modified insert ordered for sets. function overrides call this
    
    void push_front(int v); // override the IntList function and call add_val
    
    void push_back(int v); // override the IntList function and call add_val
    
    void insert_ordered(int v); // override the IntList function and call add_val
    
    //OPERATORS
    const SortedSet operator&(const SortedSet& rhs) const;
    /*
        This function returns a SortedSet object that is the intersection of 2 SortedSet objects,
        the left and right operands of this binary operator.
        An intersection of 2 sets is a set of all elements that are in both sets. 
        That is, all of the values that are in both the left operand and the right operand.
        sset1 = sset2 & sset3;
        DO NOT call remove_duplicates inside this funtion.
    */

    const SortedSet& operator&=(const SortedSet& rhs);
    /*
    This function is the intersection-assign operator function. 
    It returns an intersection of the left and right operands, 
    but also sets the left operand's value to be that intersection as well.
    See operator& specs above.
    DO NOT call remove_duplicates inside this funtion.
    */  
        
    
    const SortedSet operator|(const SortedSet& rhs) const;
    /* This function returns a SortedSet object that is the union of 2 SortedSet objects,
        the left and right operands of this binary operator.
        A union of 2 sets is a set that consists of all of the distinct elements of both sets combined.
        That is, all of the values in both sets, minus any duplicates.
        sset1 = sset2 | sset3;
    */  

    const SortedSet& operator|=(const SortedSet& rhs);
    /* 
    This function is the union-assign operator function.
    It returns a union of the left and right operands, 
    but also sets the left operand's value to be that union as well. *****
    See operator| function specs above.
    */    
    
};

#endif //__SORTEDSET_H__
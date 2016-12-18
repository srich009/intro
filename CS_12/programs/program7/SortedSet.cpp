///SortedSet implementation file

#include "IntList.h"
#include "SortedSet.h"

#include <iostream>

using namespace std;


///ALSO: inherted IntList member functions


///CONSTRUCTORS && DESTRUCTOR
SortedSet::SortedSet()
    :IntList()
{}
// The default constructor initializes an empty set.
//________________________________________________________________________________________________

SortedSet::SortedSet(const SortedSet &copy)
    :IntList(copy)
{}
/*
The copy constructor initializes the set to be a copy of the set passed in. Use the IntList copy constructor
*/
//_____________________________________________________________________________________________________

SortedSet::SortedSet(const IntList &copy)
    :IntList(copy)
{

    if( this->empty() )
    {
        return;
    }
    
    this->selection_sort();
    this->remove_duplicates();
    
    return;
}
/*
A copy constructor that is passed an IntList instead of a SortedSet. It should initialize the set using the values in the IntList.
Again, you can use the IntList copy constructor and then remove all of the duplicates and sort the remaining values.
*/
//_______________________________________________________________________________________________________________


SortedSet::~SortedSet()
{
   // ~IntList();   //??? 
}
/*
deallocate all dynamically allocated memory that the IntList destructor will not already deallocate.
You may very well find that this function does not need to do anything.
*/
//________________________________________________________________________________________________________________


///ACCESSORS
// ?? const after each function non-capable of data mutation?? 

bool SortedSet::in(int data) const
{
    int n = data; // data passed in renamed to avoid confilct with intnode's data
    
    if( this->empty() )
    {
        return false;
    }
    
    for(IntNode* temp = head; temp != 0; temp = temp->next)
    {
        if(temp->data == n) 
        {
            return true;
        }
    }
    
    return false;
}
//This function returns true if the value in data is a member of the set, otherwise false.
//_______________________________________________________________________________________________________________


const SortedSet SortedSet::operator|( const SortedSet &rhs ) const
{
        SortedSet ss = rhs;
        
        //go through implicit && add to sp
        for(IntNode* temp = head; temp != 0; temp = temp->next)
        {
            ss.add(temp->data);
        }
        
        
        return ss;

}
// /* This function returns a SortedSet object that is the union of 2 SortedSet objects,
//     the left and right operands of this binary operator.
//     A union of 2 sets is a set that consists of all of the distinct elements of both sets combined.
//     That is, all of the values in both sets, minus any duplicates.
//     sset1 = sset2 | sset3;
// */  
// //_______________________________________________________________________________________________

const SortedSet SortedSet::operator&( const SortedSet &rhs ) const
{
    SortedSet ss;
    
    for(IntNode* temp = rhs.head; temp != 0; temp = temp->next)
    {
        if( this->in(temp->data) )
        {
            ss.add(temp->data);
        }
    }
    
    return ss;
}
// /*
//     This function returns a SortedSet object that is the intersection of 2 SortedSet objects,
//     the left and right operands of this binary operator.
//     An intersection of 2 sets is a set of all elements that are in both sets. 
//     That is, all of the values that are in both the left operand and the right operand.
//     sset1 = sset2 & sset3;
    
//     DO NOT call remove_duplicates inside this funtion.
// */
// //_____________________________________________________________________________________________



///MUTATORS
void SortedSet::add(int data)
{
    int n = data;
    
    if(head == 0)
    {
        this->IntList::push_front(n);
    }
    else if(n <= head->data)
    {
        if(n == head->data) //remove @ head
        {
            return;
        }
        
        this->IntList::push_front(n);
    }
    else if(n >= tail->data)
    {
        if(n == tail->data) // remove @ tail
        {
            return;
        }
        
        this->IntList::push_back(n);
    }
    else
    {
        IntNode* prev = head;
        for( IntNode* temp = head; temp != 0; temp = temp->next)
        {            
            if(n <= (temp)->data) 
            {
                if(n == temp->data) //remove @ on the inside 
                {
                    return;
                }
                
              IntNode* q = new IntNode(n);
              prev->next = q;
              q->next = temp;
              break;  
            }
            prev = temp;
        }    
    }
    
    return;
}
/*
     This function adds the value in data to the set. 
     It needs to make sure data does not already exist in the set (no duplicates) 
     and that it is inserted in the proper position (in ascending order).
    
    This must be an O(n) operation essentially meaning only going through the list once 
    looking for the location to add the new value and then inserting it 
    only if that location does not already have the value located there. 

    So, this function is basically the insert_ordered function from your IntList, only you don't insert duplicates.
*/
//____________________________________________________________________________________________________________________

void SortedSet::push_front(int value)
{
    this->add(value);
    return;
}
/*
    Override this function so that it inserts the value in data in the proper position (in ascending order) 
    only if the value does not already exist in the set (no duplicates).
    In other words, this function should do exactly what add does.
    The only reason we are overriding this function is so that the push_front from the IntList is not inherited
    . A user of the SortedSet should not be able to just push any value onto the front of the list.
    In fact, since this function should do exactly what add does, this function should just call add to do the work for it.  
*/
//__________________________________________________________________________________________________________________________

void SortedSet::push_back(int value)
{
    this->add(value);
    return;
}
/*
    Override this function so that it inserts the value in data in the proper position (in ascending order)
    only if the value does not already exist in the set (no duplicates).
    See specs for push_front above. The same rationale for overriding applies to this function.
*/
//_____________________________________________________________________________________________________________________________

void SortedSet::insert_ordered(int value)
{
    this->add(value);
    return;
}
/*
    Override this function so that it does not insert duplicates.
    See specs for push_front above. The same rationale for overriding applies to this function.
*/
//___________________________________________________________________________________________________________



const SortedSet& SortedSet::operator|=( const SortedSet &rhs )
{

        SortedSet ss = rhs;
        
        //go through implicit && add to ss
        for(IntNode* temp = head; temp != 0; temp = temp->next)
        {
            ss.add(temp->data);
        }
        
        
       *this = ss;
       return *this;
     
}
/* 
    This function is the union-assign operator function.
    It returns a union of the left and right operands, 
    but also sets the left operand's value to be that union as well. *****
    See operator| function specs above.
*/
//______________________________________________________________________________



const SortedSet& SortedSet::operator&=( const SortedSet &rhs )
{
    SortedSet ss;
    
    for(IntNode* temp = rhs.head; temp != 0; temp = temp->next)
    {
        if( this->in(temp->data) )
        {
            ss.add(temp->data);
        }
    }
    
    *this = ss;
    return *this;
}
/*
    This function is the intersection-assign operator function. 
    It returns an intersection of the left and right operands, 
    but also sets the left operand's value to be that intersection as well.
    See operator& specs above.
    
    DO NOT call remove_duplicates inside this funtion.
*/ 
//_____________________________________________________________________________________


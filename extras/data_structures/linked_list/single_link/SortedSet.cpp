//implementation of the sorted set class

#include <iostream>

#include "IntList.h"
#include "SortedSet.h"

using namespace std;


//Inheritance of all IntList public functions

//CONSTRUCTORS && DESTRUCTOR

SortedSet::SortedSet()
    :IntList()
{}
//____________________________________

SortedSet::~SortedSet()
{}
//____________________________________

SortedSet::SortedSet(const IntList& copy)
    :IntList(copy)
{
    this->selection_sort();
    this->remove_duplicates();
}
//____________________________________________


SortedSet::SortedSet(const SortedSet& copy)
    :IntList(copy)
{}
//====================================================
//====================================================


//ACCESSORS


//MUTATORS
void SortedSet::add_val(int v)
{
    if(head == 0)
    {
        this->IntList::push_front(v);
        return;
    }
    else if(v <= head->data)
    {
        if(v == head->data)
        {
            return;
        }
        
        this->IntList::push_front(v);
        return;
    }
    else if(v >= tail->data)
    {
        if(v == tail->data)
        {
            return;
        }
        
        this->IntList::push_back(v);
        return;
    }
    
    
    //somewhere in the middle
    IntNode* prev = this->head;
    for(IntNode* index = this->head->next; index != 0; index = index->next)
    {
        if(v <= index->data)
        {
           if(v == index->data)
           {
               return;
           }
           else
           {
               IntNode* temp = new IntNode(v);
               prev->next = temp;
               temp->next = index;
               return;
           }
        }
        prev = prev->next;
    }
    
    return;
}
//_________________________________________________________

void SortedSet::push_front(int v)
{
    this->add_val(v);
    return;
}
//_________________________________________________________

void SortedSet::push_back(int v)
{
    this->add_val(v);
    return;
}
//__________________________________________________________

void SortedSet::insert_ordered(int v)
{
    this->add_val(v);
    return;
}
//===============================================================
//===============================================================


//OPERATORS
const SortedSet SortedSet::operator&(const SortedSet& rhs) const
{
    SortedSet ss;
    
    for(IntNode* index = this->head; index != 0; index = index->next)
    {
        if(rhs.in(index->data))
        {
           ss.add_val(index->data);
        }
    }
    
    return ss; 
}
//_____________________________________________________________________

const SortedSet& SortedSet::operator&=(const SortedSet& rhs)
{
    SortedSet ss;
   
  for(IntNode* index = this->head; index != 0; index = index->next)
  {
      if(rhs.in(index->data))
      {
           ss.add_val(index->data);
      }
  }
    
    *this = ss;
    
    return *this;
}
//___________________________________________________________________ 
    
const SortedSet SortedSet::operator|(const SortedSet& rhs) const
{
    SortedSet ss = (*this);
    
    for(IntNode* index = rhs.head; index != 0; index = index->next)
    {
        ss.add_val(index->data);
    }
    
    return ss;
}
//_________________________________________________________________________ 

const SortedSet& SortedSet::operator|=(const SortedSet& rhs)
{
    SortedSet ss = (*this);
    
    for(IntNode* index = rhs.head; index != 0; index = index->next)
    {
        ss.add_val(index->data);
    }
    
    *this = ss;
    return *this;
}
//_________________________________________________________________________ 
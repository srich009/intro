//IMPLEMENTATION

#include "IntList.h"
#include <iostream>

using namespace std;

/*
///IntNode used by IntList class
struct IntNode
{
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

///IntList private
    //IntNode POINTER
    IntNode * head; 
*/


///IntList Public stuff
//CONSTRUCTOR
//: Initializes an empty list.
IntList::IntList()
{
    head = 0;
}

//MEMBER FUNCTIONS
//: Inserts a data value (within a new node) at the front end of the list.
void IntList::push_front(int value)
{
    if(head == 0)
    {
        IntNode* temp = new IntNode(value);
        head = temp;
    }
    else
    {
        IntNode* temp = head; // //pointer to head
        head = new IntNode(value);
        head->next = temp;
    }
    
    return;
}



ostream & operator<<(ostream &out, const IntList &rhs) //friend function
{
    
    if(rhs.head == 0)
    {
        return out;
    }
    else if(rhs.head->next == 0)
    {
        out << rhs.head->data;
        return out;
    }
    
    out << rhs.head->data << ' ';
    
    // operator<<(out,rhs->next)
    //other overload
    out<<rhs.head->next;
    
    return out;
}
//: A global friend function that outputs to the stream all of the integer values
//within the list on a single line, each separated by a space.
//This function does NOT send to the stream a newline or space at the end.


 bool IntList::exists(int k) const
 {
         
     if(this->head == 0)
     {
        return false;
     }
     
     return exists(head, k);
 }


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//PRIVATE FUNCTIONS

bool IntList::exists(IntNode * n, int k) const
{
     if(n == 0)
     {
         return false;
     }
    
    if(n->data == k)
    {
        return true;
    }

    return exists(n->next, k);
}
  
  
  
//OTHER ??

ostream & operator<<(ostream &outs, IntNode * n)
{
    if(n == 0)
    {
         
        return outs;
    }
    else if(n->next == 0)
    {
        outs << n->data;
        return outs;
    }
    
    
    outs << n->data << ' ';
    outs << n->next;
    
    
    return outs;
}
//IMPLEMENTATION

#include "IntListL.h"

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
    //IntNode POINTERS
    IntNode * head; 
    IntNode * tail;
*/


///IntList Public stuff
    //CONSTRUCTOR
    IntList::IntList()
    {
        head = 0;
        tail = 0;
    }
    //: Initializes an empty list.
    
    //DESTRUCTOR
    IntList::~IntList()
    {
        if(head != 0)
        {
            for(IntNode* temp = head; temp != 0; temp = head )
            {
                head = head->next;
                delete temp;
            }
        }
    }
    //: Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
    
    //MEMBER FUNCTIONS
    void IntList::display() const
    {
        for(IntNode* temp = head; temp != 0; temp = temp->next)
        {
            if(temp->next == 0)
            {
                cout << temp->data;
            }
            else
            {
            cout << temp->data << " ";
            }
        
        }
        
        return;
    }
    //: Displays to a single line all of the int values stored in the list, each separated by a space. This function does NOT output a newline or space at the end.
    
    
    void IntList::push_front(int value)
    {
        if(head == 0)
        {
            IntNode* temp = new IntNode(value);
            head = temp;
            tail = temp;
        }
        else if(head == tail)
        {
            IntNode* temp = new IntNode(value);
            head = temp;
            head->next = tail;
        }
        else
        {
            IntNode* temp = head; // //pointer to head
            head = new IntNode(value);
            head->next = temp;
        }
        
        return;
    }
    //: Inserts a data value (within a new node) at the front end of the list.
    
    
     void IntList::pop_front()
    {
         if(head == 0)
         {}
         else if(head == tail)
         {
             delete head;
             head = 0;
             tail = 0;
         }
         else
         {
             IntNode* temp = head;
             head = head->next;
             delete temp;
         }
        
        return;
    }
    //: Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
    
    
    bool IntList::empty() const
    {
        if(head == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    //: Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
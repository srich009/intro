//IMPLEMENTATION

#include "IntList.h"
#include <iostream>
#include <algorithm>// fix

using namespace std;

/*
///IntNode used by IntList class
struct IntNode
{
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

///IntList protected
    //IntNode POINTERS
    IntNode * head; 
    IntNode * tail;
*/


///IntList Public stuff
//CONSTRUCTOR
//: Initializes an empty list.
IntList::IntList()
{
    head = 0;
    tail = 0;
}

//DESTRUCTOR
//: Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList()
{
    // if(head != 0)
    // {
    //     for(IntNode* temp = head; temp != 0; temp = head )
    //     {
    //         head = head->next;
    //         delete temp;
    //     }
    // }
    
    clear();
    
}

//MEMBER FUNCTIONS

//: Displays to a single line all of the int values stored in the list, each separated by a space.
//This function does NOT output a newline or space at the end.
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


//: Inserts a data value (within a new node) at the front end of the list.
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


//: Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
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

//: Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
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

//==========================================================================================================================
//============================================================================================================================

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//: the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy)
{
    head = 0;
    tail = 0;
    
    if( cpy.empty() )
    {  
        return;
    }
   
   
    for(IntNode* temp = cpy.head; temp != 0; temp = temp->next)
    {  
         push_back(temp->data);
    }
    
    return; 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//: the overloaded assignment operator. Make sure this performs deep copy.
IntList & IntList::operator=(const IntList &rhs) 
{
    if(this == &rhs)
    {
        return *this; 
    }
    else
    {
        this->clear();
        
        for(IntNode* temp = rhs.head; temp != 0; temp = temp->next)
        {  
             push_back(temp->data);
        }
    
        return *this; 
    }   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//: Inserts a data value (within a new node) at the back end of the list.
void IntList::push_back(int value)
{
    if(head == 0)
    {
        IntNode* temp = new IntNode(value);
        head = temp;
        tail = head;
        
    }
    else if(head == tail)
    {
        IntNode* temp = new IntNode(value);
        tail = temp;
        head->next = tail;
    }
   else
   {
       
        IntNode* temp = new IntNode(value); 
         tail->next = temp;
         tail = temp;    
   } 
    return;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//: Removes (deallocates) all IntNodes in the IntList. 
//Don't forget to set both head and tail to appropriate values for an empty list.
void IntList::clear()
{
    if(head != 0)
    {
        for(IntNode* temp = head; temp != 0; temp = head )
        {
             head = head->next;
            delete temp;
        }
    }
    return;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//: Sorts the integers in the list into ascending order. 
//Do NOT move the nodes, just the integers.
void IntList::selection_sort()
{
    for(IntNode* i = head; i != 0; i = i->next) // start index
    {
        //MINIMUM VAL HERE smallest index
        IntNode* min = i;
        
        for(IntNode* j = i->next; j != 0; j = j->next ) // current index
        {
            if( (j->data) < (min->data) ) // if current index smaller than min switch
            {
                min = j;
            }
        }
        
        //swap values
        swap( (i->data), (min->data) );
    }
    
    return;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//: Inserts a data value (within a new node) in an ordered list.
//Assumes the list is already sorted in ascending order 
//(i.e., Do not sort the list first, assume the list is already is sorted.) 
//This function loops through the list until if finds the correct position 
//for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
void IntList::insert_ordered(int value)
{
    if(head == 0)
    {
        this->push_front(value);
    }
    else if(value <= head->data)
    {
        this->push_front(value);
    }
    else if(value >= tail->data)
    {
        this->push_back(value);
    }
    else
    {
        IntNode* prev = head;
        for( IntNode* temp = head; temp != 0; temp = temp->next) // temp =head -> next
        {            
            if(value <= (temp)->data) 
            {
              IntNode* q = new IntNode(value);
              prev->next = q;
              q->next = temp;
              break;  
            }
            prev = temp;
        }
           
    }
    
    return;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx



//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//does not assume order
//: Removes all duplicate data values (actually removes the nodes that contain the values) within the list.
//Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.
void IntList::remove_duplicates()
{
    if(head == 0)
    {
        return;
    }
    else if(head == tail) // list size 1
    {
        return;
    }
    else
    {
        for(IntNode* i = head; i != 0; i = i->next)
        {  
                    IntNode* prev = i;
            
            for(IntNode* j = i->next; j != 0; j = prev->next)
            {
                    
                if(i->data == j->data)
                {
                    
                    if(j->next == 0)
                    {
                        //delete j;
                       tail = prev;
                    }
                    
                    j = j->next;
                    delete prev->next;                
                    prev->next = j;
                    
                }
                else
                {
                     prev = prev->next;
                }
            }
           
        } 
    }
    
    return;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx




//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
ostream & operator<<(ostream &out, const IntList &rhs) //friend function
{
    
    for(IntNode* temp = rhs.head; temp != 0; temp = temp->next)
    {
        if(temp->next == 0)
        {
            out << temp->data;
        }
        else
        {
            out << temp->data << " ";
        }
    }
    
    return out;
}
//: A global friend function that outputs to the stream all of the integer values
//within the list on a single line, each separated by a space.
//This function does NOT send to the stream a newline or space at the end.
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
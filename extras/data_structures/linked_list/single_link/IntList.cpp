/// implementation file for a singly linked list of integer nodes

#include <iostream>
#include <algorithm>

#include "IntList.h"

using namespace std;

/*
struct IntNode
    int data;
    IntNode* next;
    IntNode(int val) : data(val), next(0) {}   
//-------------------------------------------

class IntList
private:
   IntNode* head;
   IntNode* tail;  

*/


///CONSTRUCTORS && DESTRUCTOR
IntList::IntList()
    :head(0), tail(0)
{}
//__________________________________

IntList::~IntList()
{
    // if(head != 0)  // IntList::clear()
    // {
    //     // go through move head up oneeach time && delete index's node
    //     //reset the index to head each time to delete all
    //     for(IntNode* index = head; index != 0; index = head)
    //     {
    //         head = head->next;
    //         delete index;
    //     }
    // }
    
    clear();
}
//_______________________________________________

IntList::IntList(const IntList &cpy) // copy constructor
{
    head = 0;
    tail = 0;
    
    if(cpy.head == 0)
    {
        return;
    }
    
    for(IntNode* index = cpy.head; index != 0; index = index->next)
    {
        this->push_back(index->data);
    }
    return; 
}
//_________________________________________________________________________

IntList& IntList::operator=(const IntList &rhs) // assignment operator
{
    if(this == &rhs)
    {
        return *this;
    }
    
    this->clear();
    
    for(IntNode* index = rhs.head; index != 0; index = index->next)
    {
        push_back(index->data);
    }
    
    return *this;
}

//=====================================================================
//=====================================================================


//ACCESSORS
bool IntList::empty() const
{
    if(this->head == 0)
    {
       return true; 
    }
    
    return false;
}
//________________________________________________________________

bool IntList::in(int v) const
{
    for(IntNode* index = this->head; index != 0; index = index->next)
    {
        if(index->data == v)
        {
            return true;
        }
    }
    
   return false;
}
//_______________________________________________________________________

int IntList::locate(int v) const // returns -1 if not found
{
    if(head == 0)
    {
        return -1;
    }
    else if(head == tail)
    {
        if(head->data == v)
        {
            return 1;  
        }
        else
        {
            return -1;
        }
    }
    
    int count = 1;
    for(IntNode* index = this->head; index != 0; index = index->next)
    {
        if(index->data == v)
        {
           return count; 
        }
        
        count++;
    }
    
    
    return -1;
}
//_______________________________________________________________________


unsigned IntList::size() const
{
    if(head == 0)
    {
        return 0;
    }
    else if(head == tail)
    {
        return 1;
    }
    
    unsigned count = 0;
    
    for(IntNode* index = this->head; index != 0; index = index->next)
    {
        count++;
    }
    
    return count;
}
//_______________________________________________________________________

void IntList::display() const
{
    if(head == 0)
    {
        cout << "Empty List" << endl;
        return;
    }
    
    for(IntNode* index = this->head; index != 0; index = index->next)
    {
        cout << index->data << ", ";
    }
    cout << endl;
    
    return;
}
//===================================================================

int IntList::sum() const
{
    if(this->head == NULL)
    {
        return 0;
    }
    
    int h = this->head->data;
    IntList l = *this;
    l.head = l.head->next;
    
    return h + l.IntList::sum();
}

//===================================================================


//MUTATORS
void IntList::clear()
{
    if(head != 0)
    {
        // go through move head up oneeach time && delete index's node
        //reset the index to head each time to delete all
        for(IntNode* index = head; index != 0; index = head)
        {
            head = head->next;
            delete index;
        }
    }
    
    return;
}
//_______________________________________________________________

void IntList::push_front(int v)
{
    IntNode* ip = new IntNode(v);
    
    if(head == 0) //size 0
    {
        head = ip;
        tail = head;
    }
    // else if(head ==  tail) // size 1 list
    // {
    //       //ip->next = head;
    //       //head = ip;
    
    //      //head = ip;
    //      //head->next = tail;
    // }
    else
    {        
        ip->next = head;
        head = ip;
    }
      
    return;
}
//____________________________________________________________

void IntList::push_back(int v)
{
    IntNode* ip = new IntNode(v);
    
    if(head == 0) //size 0
    {
        head = ip;
        tail = head;
    }
    // else if(head == tail) // size 1 list
    // {
    //     // tail->next = ip;
    //     // tail = ip
        
    //     //tail = ip;
    //     //head->next = tail;
    // }
    else
    {        
        tail->next = ip;
        tail = ip;
    }
    
    return;
}
//___________________________________________________________

void IntList::pop_front()
{
    if(this->head == 0) // size 0
    {
        return;
    }
    else if(head == tail) // size 1
    {
        delete head;
        this->head = 0;
        this->tail = 0;
        return;
    }
    
    IntNode* temp = head;
    head = head->next;
    delete temp;

    return;
}
//__________________________________________________________

void IntList::pop_back()
{
    if(this->head == 0) // size 0
    {
        return;
    }
    else if(head == tail) // size 1
    {
        delete head;
        this->head = 0;
        this->tail = 0;
        return;
    }
    
    ///stop one behind tail
    IntNode* index = 0;
    for(index = this->head; index != 0; index = index->next)
    {
        if(index->next == tail)
        {
            break;
        }
    } 
    
    delete index->next;
    tail = index;
    index->next = 0;
    
    return;
}
//_________________________________________________________________

void IntList::remove_node(unsigned u)
{
    //check u
    if(u == 0)
    {
       cout << "cannot remove '0' index starts at node 1" << endl;
       return;
    }
    else if(this->size() < u)
    {
        cout << "remove fail: index of node greater than size of list " << endl;
        return;
    }
    
    //check size  
    if(head == 0)
    {
        cout << "remove fail: index of node greater than size of list " << endl;
        return;
    }
    else if(head == tail)
    {
        if(u == 1)
        {
            this->pop_front();
            return;
        }
        else
        {
            cout << "remove fail: index of node greater than size of list " << endl;
            return;
        }  
    }
    
    //
    unsigned count = 1;
    IntNode* prev = this->head;
    for(IntNode* index = this->head;  index != 0; index = index->next)
    {
        if(u == count)
        {
           prev->next = index->next;
           delete index;
           break; 
        }
        
        prev = index;
        count++;
    }
    
    return;   
}
//___________________________________________________________________________

void IntList::remove_duplicates()
{
    if(head == 0)
    {
        cout << "can't remove duplicates from empty list"  << endl;
        return;
    }
    else if(head == tail)
    {
        cout << "List has only 1 element, no duplicates" << endl;
        return;
    }
    
    
    //element comparison
    for(IntNode* a = head; a != 0; a = a->next)
    {
        //pointer to node one behind b
        IntNode* prev = a;
        
        for(IntNode* b = a-> next; b != 0; b = prev->next) // b gets set to prev next because of delete??
        {
            if(a->data == b->data)
            {
                if(b->next == tail)// check if next node is tail
                {
                    tail = prev;
                }
                
                b = b->next;
                delete prev->next;
                prev->next = b;
                
            } 
            else
            {
                prev = prev->next;
            }
        }
    }

    return;
}
//__________________________________________________________________

void IntList::selection_sort()
{
    if(head == 0) // size 0
    {
        cout << "you called sort on an empty list..." << endl;
        return;
    }
    else if(head == tail) // size = 1
    {
        //cout << "List Sorted" << endl;
        return;
    }
 
    for(IntNode* a = head; a != 0; a = a->next)
    {
        //minval pointer
        IntNode* min = a;
        
        for(IntNode* b = a->next; b != 0; b = b->next)
        {
            //compare here && keep track of min
            if( (b->data) < (min->data) )
            {
                min = b;
            }
        }
        
        //swap here if  min < a
        if( (min->data) < (a->data) )
        {
            swap( (min->data), (a->data) );
        }
    }
   
    //cout << "List Sorted" << endl;
    return;
}
//__________________________________________________________________________

void IntList::insert_ordered(int v)
{
    if(head == 0) // empty
    {
        this->push_front(v);
        return;
    }
    else if(v <= head->data) // put on front
    {
        this->push_front(v);
        return;
    }
    else if(v >= tail->data) // put on back
    {
        this->push_back(v);
        return;
    }
    
    //insert in middle
    IntNode* prev = head;
    for(IntNode* index = head->next; index != 0; index = index->next)
    {
        if(v <= index->data)
        {
            IntNode* temp = new IntNode(v);
            prev->next = temp;
            temp->next = index;
            break;
        }
        prev = prev->next; /// prev = index;
    }
    
    
    return;
}
//_______________________________________________________________________________

void IntList::reverseList()
{
    if(head == 0)
    {
        return;
    }
    else if(head == tail)
    {
        return;   
    }
    
    IntList* p = new IntList(*this);
    
    for(IntNode* index = this->head; index != 0; index = index->next)
    {
        swap( index->data, (p->tail)->data );
        p->pop_back();
    }
    
    return;
}
//============================================================================
//============================================================================


//OPERATORS
const IntList& IntList::operator+=(const IntList& rhs)
{
    (this->tail)->next = rhs.head;
    return *this;
}
//________________________________________________________

const IntList IntList::operator+(const IntList& rhs) const
{
    IntList* temp = new IntList(*this);
    (temp->tail)->next = rhs.head;
    return *temp;
}
//___________________________________________________________



//FRIEND OUTPUT OPERATOR
ostream& operator<<(ostream& out, const IntList& rhs)
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


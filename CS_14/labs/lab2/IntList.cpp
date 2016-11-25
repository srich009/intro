//Doubly Linked List implementation
// using dummy nodes to remove special cases

#include <iostream>

#include "IntList.h"

using namespace std;

    IntList::IntList()
    {
        // actual nodes
        dummyHead = new IntNode(0); 
        dummyTail = new IntNode(0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    //--------------------------------------
    
    IntList::~IntList()
    {
        while( !empty() )
        {
            pop_front();
        }
    }
    //-----------------------------------------

    void IntList::push_front(int value)
    {
        IntNode* temp = new IntNode(value);
        temp->prev = dummyHead;
        temp->next = dummyHead->next;
        (dummyHead->next)->prev = temp;
        dummyHead->next = temp;
        return;
    }
    //----------------------------------------------

    void IntList::pop_front()
    {
        if(!empty())
        {
            IntNode* temp = (dummyHead->next)->next; // points at one past first node
            delete dummyHead->next;                 // delete first node
            dummyHead->next = temp;
            temp->prev = dummyHead;
            return;
        }
    }
    //-------------------------------------------------

    void IntList::push_back(int value)
    {
        IntNode* temp = new IntNode(value);
        temp->next = dummyTail;
        temp->prev = dummyTail->prev;
        (dummyTail->prev)->next = temp;
        dummyTail->prev = temp;
        return;
    }
    //--------------------------------------------------

    void IntList::pop_back()
    {
        if(!empty())
        {
            IntNode* temp = (dummyTail->prev)->prev; // one before last
            delete dummyTail->prev;
            dummyTail->prev = temp;
            temp->next = dummyTail;
            return;
        }
    }
    //-----------------------------------------------------

    bool IntList::empty() const
    {
        return dummyHead->next == dummyTail;
    }
    //-------------------------------------------

    void IntList::printReverse() const // no newline or space at end
    {
        for(IntNode* index = dummyTail->prev; index != dummyHead; index = index->prev)
        {
            if(index->prev == dummyHead)
            {
                cout << index->data;
            }
            else
            {
                cout << index->data << ' ';
            }
        }
        return;
    }
    //-------------------------------------------------------
    
    ostream & operator<<(ostream &out, const IntList &rhs)// no newline os space at end
    {
        if(!rhs.empty())
        {
            IntNode* i = rhs.dummyHead->next; // points to first node
            
            for(; i->next != 0; i = i->next)
            {
                if(i->next == rhs.dummyTail)
                {
                    out << i->data;
                }
                else
                {
                    out << i->data << ' ';
                }
            }
            
            // while(i->next->next)
            // {
            //     out << i->data << ' ';
            //     i = i->next;
            // }
            // out << i->data;
        }
        return out;
    }
/// definition file for a singly linked list of integer nodes

#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <iostream>

using namespace std;

///struct used bt the IntList class
struct IntNode
{
    ///internals
        int data;
        IntNode* next;
    ///constructor
        IntNode(int val) : data(val), next(0) {}   
};
//_______________________________________________

class IntList
{
    //protected for SortedSet access
    protected:
       IntNode* head;
       IntNode* tail;   // only for convenient access to last element...
       
    public:
    
    //CONSTRUCTORS && DESTRUCTOR
        IntList(); // initialize an empty list
        
        ~IntList(); //deallocate all remaining dynamic memory
        
        IntList(const IntList &cpy); // the copy constructor. Make sure this performs deep copy.
        
        IntList& operator=(const IntList &rhs); //: the overloaded assignment operator. Make sure this performs deep copy.
        
    //ACCESSORS
        bool empty() const; // retrun true if list head == 0
    
        bool in(int v) const; // returns true if value is found in the list
        
        int locate(int v) const; // returns first node position that contains value
        
        unsigned size() const; // returns the amt of nodes in list
        
        void display() const; // displays the list separated by commas
        
        //??
        int sum() const; // recursive sum
    
    //MUTATORS
        void clear(); // clear list (deallocate all dynamic memory)
    
        void push_front(int v); // attach node to list front
        
        void push_back(int v); // attach node to list back
        
        void pop_front(); // remove node from list front && deallocate memory
        
        void pop_back(); // remove node from list back && deallocate memory

        void remove_node(unsigned u); // indexes to and then removes that specific node && deallocate
        
        void remove_duplicates();
        //Removes all duplicate data values (actually removes the nodes that contain the values) within the list.
        //Always remove just the later value within the list when a duplicate is found.
                
        void selection_sort(); // Sorts the integers in the list into ascending order. Does not move the nodes, just the integers.

        void insert_ordered(int value); 
        //: Inserts a data value (within a new node) in an ordered list.
        //Assumes the list is already sorted in ascending order  
        //This function loops through the list until if finds the correct position 
        //for the new data value and then inserts the new IntNode in that location. This function does not sort the list.
        
        void reverseList(); // reverse list order...
        
    //OPERATORS
        const IntList& operator+=(const IntList& rhs); // set implicit parameter to this+rhs
        
        const IntList operator+(const IntList& rhs) const; // return new IntList this+rhs    
        

        
    //FRIENDS
        
        friend ostream & operator<<(ostream &out, const IntList &rhs); 
        //: A global friend function that outputs to the stream all of the integer values
        //within the list on a single line, each separated by a space.
        //This function does NOT send to the stream a newline or space at the end.
};



#endif /// __INTLIST_H__
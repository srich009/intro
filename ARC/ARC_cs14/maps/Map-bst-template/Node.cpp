// #include "Node.h"

#include <iostream>
#include <string>

using namespace std;

// Node *left, *right, *parent;
// int count;
// string data;

//functions

template<class U>
Node<U>::Node()
    : left(0), right(0), parent(0), count(1), data() {}
    
template<class U>    
Node<U>::Node(U x) 
    : left(0), right(0), parent(0), count(1), data(x) {} // might need to do something with count
    
template<class U>    
Node<U>& Node<U>::operator=(const Node<U> &rhs)
{
    if(this != &rhs)
    {
        // this->left = rhs.left;
        // this->right = rhs.right;
        // this->parent = rhs.parent;
        this->count = rhs.count;
        this->data = rhs.data;
    }
    return *this;   
}
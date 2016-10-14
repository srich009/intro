#include "Node.h"

#include <iostream>
#include <string>

using namespace std;

// Node *left, *right, *parent;
// int count;
// string data;

//functions

Node::Node()
    : left(0), right(0), parent(0), count(1), data("") {}
    
    
Node::Node(string str) 
    : left(0), right(0), parent(0), count(1), data(str) {} // might need to do something with count
    
    
Node& Node::operator=(const Node& rhs)
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
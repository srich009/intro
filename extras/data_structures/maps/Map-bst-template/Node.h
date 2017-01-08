#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <string>

using namespace std;

template<class U>
// class Node
struct Node
{
    // template<typename T> //??
    // friend class BSTree; 
    
    // private:
    Node* left;
    Node* right;
    Node* parent; // ???
    int count;
    U data;
    
    // public:
    Node();
    Node(U x);
    Node& operator=(const Node<U>& rhs);
    
};

#include "Node.cpp"

#endif // __NODE_H__
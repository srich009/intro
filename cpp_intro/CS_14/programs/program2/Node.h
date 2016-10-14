#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <string>

using namespace std;

class Node
{
    friend class BSTree; //??
    
    private:
    Node* left;
    Node* right;
    Node* parent; // ???
    int count;
    string data;
    
    public:
    Node();
    Node(string str);
    Node& operator=(const Node& rhs);
    
};

#endif // __NODE_H__
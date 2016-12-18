#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node 
{
  friend class Tree;

  private:
    string small;
    string large;
  
    Node *left;
    Node *middle;
    Node *right;
    Node *parent;
  
    // Add additional functions/variables here. Remember, you may not add any
    // Node * or string variables.
    
    //Node();
    Node(const string&);
    Node* operator=(const Node&);
  
};

#endif


/* 

2 nodes will have left and right pointer && store string in small
eg:  left, small, right


3 nodes will have left, right, and middle pointer && store strings in small, large
eg: left, small, middle, large, right

*/

//leaf node has no children but can be a 2 or 3 node : depends on # of strings
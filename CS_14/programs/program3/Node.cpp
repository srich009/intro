#include "Node.h"

#include <iostream>
#include <string>

using namespace std;


// Node()::Node() 
//    : small(""), large(""), left(0), middle(0), right(0), parent(0) {}
   
   
Node::Node(const string& str) 
   :  small(str), large(), left(0), middle(0), right(0), parent(0)  {}
   
   
Node* Node::operator=(const Node& rhs)
{
   if(this != &rhs)
   {
      this->small = rhs.small;
      this->large = rhs.large;
   }
   return this;
}
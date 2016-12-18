#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"

using namespace std;

template<class T>
class BSTree 
{  
  protected:
    Node<T> *root;
    
    //private helper functions  
    void _preOrder(Node<T>*) const;
    
    void _inOrder(Node<T>*)const;
    
    void _postOrder(Node<T>*) const;
    
    Node<T>* _search(Node<T>*, const T&) const;
    
    void _remove(Node<T>*, const T&);
    
    void visualizeTree(ofstream &out, Node<T>* n); //xx
    
    Node<T>* findBig(Node<T>*); // remove help
    
    Node<T>* findSmall(Node<T>*); // remove help
    
    int Hheight(Node<T>*) const;
  
  public:
  
    void visualizeTree(const string&); //xx
  
    BSTree() : root(0) {} // constructor
    
    ~BSTree(); // destructor
  
    void insert(const T &);  
      /* Insert an item into the binary search tree. Be sure to keep the binary search tree properties. 
      When an item is first inserted into the tree the count should be set to 1. 
      When adding a duplicate string (case sensitive), rather than adding another node, the count variable should just be incremented. */

    void remove(const T &);
      /*
      RECURSIVE
      Remove a specified string from the tree. Be sure to maintain all binary search tree properties. 
      If removing a node with a count greater than 1, just decrement the count, otherwise, if the count is simply 1, remove the node.
      You MUST follow the remove algorithm shown in the slides and discussed in class or else your program will not pass the test functions.
      When removing, if removing a leaf node, simply remove the leaf. Otherwise, if the node to remove has a left child, 
      replace the node to remove with the largest string value that is smaller than the current string to remove 
      (i.e. find the largest value in the left subtree of the node to remove). If the node has no left child, replace the node to remove 
      with the smallest value larger than the current string to remove (i.e. find the smallest value in the right subtree of the node to remove).
      */
    
    bool search(const T &) const; //Search for a string in the binary search tree. It should return true if the string is in the tree, and false otherwise. RECURSIVE
  
    const T largest() const; //Find and return the largest value in the tree. Return an empty string if the tree is empty.
    
    const T smallest() const; //Find and return the smallest value in the tree. Return an empty string if the tree is empty.
    
    int height(const T &) const; 
      //Compute and return the height of a particular string in the tree. 
      //The height of a leaf node is 0 (count the number of edges on the longest path). Return -1 if the string does not exist.
    
    //Printing uses recursive helper function
    void preOrder() const { _preOrder(root); cout<<"\n"; }
    
    void inOrder() const { _inOrder(root); cout<<"\n";  }
    
    void postOrder() const { _postOrder(root); cout<<endl; }

};


#include "BSTree.cpp"

#endif // __BSTREE_H__
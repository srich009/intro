#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include "Node.h"

using namespace std;

class AVLTree 
{  

private:
    Node *root;
    
    int nodeCount;// we added this here
    
public:
  
    AVLTree() : root(0), nodeCount(0) {} // constructor  
    
    bool search(const string &) const; 
    
    void insert(const string&);
    
    void printBalanceFactors() { _printBalanceFactors(root); cout<<"\n";  } //Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.
    
    int balanceFactor(Node*); // Return the balance factor of a given node.

    void visualizeTree(const string &); // Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.

    void testBalance( );
    
    bool isBalanced(Node*);
    
private:
    //RECOMENDED private helper functions  

   Node* _search(Node*, const string&) const; //bst
    
   void visualizeTree(ofstream &out, Node* n); //xx
    
   void _printBalanceFactors(Node *); //xx
   
   void insert(const string &, Node*&, Node*); //bst
   
   int height( Node*, int ) const;
    
    
  Node* findUnbalancedNode( Node* ); //Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
   
  void rotate(Node*);// Implement four possible imbalance cases and update the parent of the given node.
   
  Node* rotateLeft(Node*, Node* ); //Rotate the subtree to left at the given node and returns the new subroot.
   
  Node* rotateRight(Node*, Node* ); // Rotate the subtree to right at the given node and returns the new subroot.



};

#endif // __AVLTREE_H__
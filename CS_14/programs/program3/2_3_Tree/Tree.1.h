#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Tree 
{
  private:
    Node *root;
    
  public:
    Tree() : root(0) {}
    ~Tree();
    
    void preOrder() { _preOrder(root); cout << endl;}
    void inOrder() { _inOrder(root); cout << endl;}
    void postOrder() { _postOrder(root); cout << endl;}
    
    bool search (const string &);
    void insert(const string &);
    void remove(const string &);
    
    //graphiz
    void visualizeTree(const string &outputFilename);
  
  private:
    // Add additional functions/variables here
    //helper functions
    bool isLeaf(Node*);
    bool is2Node(Node*);
    bool is3Node(Node*);
    
    void _preOrder( Node* );
    void _inOrder( Node* );
    void _postOrder( Node* );
    
    Node* _search(Node* n, const string &);
    //void _remove(Node* n, const string &);
    
    // insert helper
    void _splitNode(Node* n, const string&, Node* c1, Node* c2, Node* c3, Node* c4); 
    string _findMid(Node* n, const string&); 
    string _findSml(Node* n, const string&); 
    string _findLrg(Node* n, const string&); 
    
    // remove help
    Node* _inOrderSuc(Node* n, const string& str); 
    void _fix(Node*);
    Node* _sib(Node*);
    
    //graphiz
    void visualizeTree(ofstream & outFS, Node *n);
};

#endif


/*

DONE
test pages:

1,2,3,4
1b,2b
c?

*/

//destructor does not work
//in remove ther is no redistribute function...
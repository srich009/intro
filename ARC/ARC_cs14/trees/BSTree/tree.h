#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>
#include <vector>
#include <initializer_list>
#include <sstream>

struct Node {
    int val;
    Node *right;
    Node *left;
    Node() : val(0), right(0), left(0) { }
    Node(int val) : val(val), right(0), left(0) { }
    bool is_leaf() { return (!right && !left); } //Do we have children?
};

class Tree {
private:
    Node *root;
    Node *insert_(int, Node *);
    //Recursive print function. Print the tree with root being the parameter
    void print_(Node *);
    //Convert the tree with root being parameter to string
    std::string str_(Node *);
    //Recursive find function. Find a val with the root being the parameter
    Node *find_(int, Node *);
    Node *min_(Node *);
    Node *max_(Node *);
public:
    Tree() : root(0) { } //Initialize an empty tree
    Tree(std::initializer_list<int> v); //Initialize a tree using array syntax
    ~Tree() { clear(); }
    
    void clear() { while(root) remove(root); } //Remove items until none left
    Node *insert(int);
    void remove(Node *);
    Node *find(int val) { return find_(val, root); }
    void print() { print_(root); }
    std::string str() { return str_(root); }
    Node *min() { return min_(root); };
    Node *max() { return max_(root); };
};

//TODO:
// 1. Implement the print recursive function to print all of the values of the
//      tree in order
//
// 2. Implement the recursive str function to convert the tree to a string (SKIP)
//
// 3. Implement recurisve min and max functions to find the min and max value
//      in the tree whose root is the parameter
//
// 4. Implement the find recursive function to find a value in the tree and
//      return it's node pointer (returning 0 if not found)
//
// 5. Implement a to_vec function that converts the tree to a vector and returns
//      the sorted vector of tree values


#endif //__TREE_H__
#include "tree.h"

#include <sstream>

Tree::Tree(std::initializer_list<int> v) 
    :root(0)
{
    for(auto it = v.begin(); it != v.end(); it++) insert(*it);
}
//----------------------------------------------------------------

Node* Tree::insert_(int val, Node *n) {
    if(n->val == val) return n;
    if(n->val > val) {
        if(!n->left) return n->left = new Node(val);
        return insert_(val, n->left);
    } else {//(n->val < val) {
        if(!n->right) return n->right = new Node(val);
        return insert_(val, n->right);
    }
}
//--------------------------------------------------------------

Node* Tree::insert(int val) {
    if(!root) return root = new Node(val);
    return insert_(val, root);
}
//-------------------------------------------------------------

void Tree::remove(Node *n) {
    if(!n) return;
    if(n->is_leaf()) {
        if(n == root) root = 0;
        delete n;
        return;
    }
    if(!n->right) {
        n->val = n->left->val;
        Node *hold = n->left;
        if(n->left->is_leaf()) n->left = 0;
        remove(hold);
    } else { //Don't care whether or not there's a left child
        n->val = n->right->val;
        Node *hold = n->right;
        if(n->right->is_leaf()) n->right = 0;
        remove(hold);
    }
}

//=================================================================================
//=================================================================================
//=================================================================================

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


//Recursive print function. Print the tree with root being the parameter
void Tree::print_(Node* n)
{
    if(n == 0)
    {
       return; 
    }
    
    print_(n->left);
    std::cout << n->val << ' ';
    print_(n->right);

}

// //Convert the tree with root being parameter to string
// std::string Tree::str_(Node* n)
// {
//     std::ostringstream filler;
    
//     filler << str_(n->left);
//     filler << n->val << " ";
//     filler << str_(n->right);
    
//     return filler.str();
// }

//Recursive find function. Find a val with the root being the parameter
Node* Tree::find_(int key, Node* n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n->val == key)
    {
        return n;
    }
    else if(n->val > key)
    {
        return find_(key, n->left);
    }
    else
    {
        return find_(key, n->right);
    }
}

Node* Tree::min_(Node* n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n->left != 0)
    {
        return min_(n->left);
    }
    else
    {
        return n;
    }
}

Node* Tree::max_(Node* n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n->right != 0)
    {
        return max_(n->right);
    }
    else
    {
        return n;
    }
}
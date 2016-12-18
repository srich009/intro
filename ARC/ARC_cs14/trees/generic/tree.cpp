#include "tree.h"
#include <iostream>
using std::cout;

Tree::Tree(int type) {
    if(type == 0) { //http://cs-people.bu.edu/behoppe/videos/rooted%20tree.jpg
        root = new Node(3);
        Node *left = new Node(9);
        Node *right = new Node(4);
        root->children.push_back(left);
        root->children.push_back(right);
        left->children.push_back(new Node(2));
        left->children[0]->children.push_back(new Node(8));
        left->children[0]->children[0]->children.push_back(new Node(1));
        right->children.push_back(new Node(10));
        right->children.push_back(new Node(6));
        right->children.push_back(new Node(5));
        right->children[1]->children.push_back(new Node(7));
    } else if(type == 1) { //http://i.stack.imgur.com/j7A1f.jpg (Tree 1)
        root = new Node(1);
        root->children.push_back(new Node(2));
        root->children.push_back(new Node(3));
        root->children.push_back(new Node(3));
        root->children.push_back(new Node(4));
        root->children.push_back(new Node(3));
        root->children.push_back(new Node(3));
        root->children.push_back(new Node(3));
        root->children[1]->children.push_back(new Node(5));
        root->children[1]->children.push_back(new Node(6));
        root->children[2]->children.push_back(new Node(5));
        root->children[2]->children.push_back(new Node(7));
        root->children[4]->children.push_back(new Node(8));
        root->children[4]->children[0]->children.push_back(new Node(9));
        root->children[5]->children.push_back(new Node(10));
        root->children[5]->children.push_back(new Node(8));
        root->children[5]->children[1]->children.push_back(new Node(9));
        root->children[6]->children.push_back(new Node(11));
        root->children[6]->children.push_back(new Node(8));
        root->children[6]->children.push_back(new Node(10));
        root->children[6]->children[1]->children.push_back(new Node(9));
    } else if(type == 2) {
        //https://upload.wikimedia.org/wikipedia/commons/f/f7/Binary_tree.svg
        root = new Node(2);
        root->children.push_back(new Node(7));
        root->children.push_back(new Node(5));
        root->children[0]->children.push_back(new Node(2));
        root->children[0]->children.push_back(new Node(6));
        root->children[1]->children.push_back(new Node(9)); //<--Drawn as right
                            //child in the picture, but we're making it left
        root->children[0]->children[1]->children.push_back(new Node(5));
        root->children[0]->children[1]->children.push_back(new Node(11));
        root->children[1]->children[0]->children.push_back(new Node(4));
    }
}


void Tree::Postprint_(Node *n)
{
    if(n == 0)
    {
        return;
    }
    
    
    for(std::vector<Node*>::iterator it = n->children.begin() ; it != n->children.end(); it++)
    {
       Postprint_(*it);
    }
    cout << n->val << ' ';
    


}


void Tree::Inprint_(Node *n)
{
    if(n == 0)
    {
        return;
    }
    
    if(! n->children.empty() )
    {
        Inprint_(n->children.at(0));
    } 
    
    cout << n->val << ' ';
    
    for(unsigned it = 1; it < n->children.size(); it++)
    {
        Inprint_(n->children.at(it));
    }   
}
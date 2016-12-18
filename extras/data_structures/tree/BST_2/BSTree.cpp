#include "BSTree.h"

#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

// private:
// Node *root;
  
void BSTree::_preOrder(Node* n) const //XXX
{
    if(n == NULL)
    {
      return;
    }
    
    cout << n->data << "(" << n->count << "), ";
    _preOrder(n->left);
    _preOrder(n->right);
}
//--------------------------------------------------

void BSTree::_inOrder(Node* n) const //XXX
{
    if(n == NULL)
    {
      return;
    }
    
    _inOrder(n->left);
    cout << n->data << "(" << n->count << "), ";
    _inOrder(n->right);
}
//--------------------------------------------------

void BSTree::_postOrder(Node* n) const //XXX
{
    if(n == NULL)
    {
      return;
    }
    
    _postOrder(n->left);
    _postOrder(n->right);
    cout << n->data << "(" << n->count << "), ";
}
//--------------------------------------------------

Node* BSTree::_search(Node* tp, const string& str) const //XXX
{
    if(tp == NULL)
    {
      return 0;
    }
    else
    {
        if(tp->data == str)
        {
          return tp;
        }
        else if(tp->data > str)
        {
          return _search(tp->left, str);
        }
        else
        {
          return _search(tp->right, str);
        }
    }
}
//-------------------------------------------------------------------


void BSTree::_remove(Node* rm, const string& str)
{
    Node* par = rm->parent;
    
    if(rm == 0) // not found in tree
    {
        return;
    }
    else if(rm->count > 1)
    {
      rm->count -= 1; /////////////////////////
      return;
    }
    else if(!rm->left && !rm->right) // leaf
    {
        if(par == 0)
        {
          root = 0;
        }
        else if(par->left == rm) 
        {
          par->left = 0;
        }
        else
        {
          par->right = 0;
        }
        delete rm;
        rm = 0;
        return;
    }
    else if(rm->left) //  child on left
    {
        Node* tp = findBig(rm);
        rm->data = tp->data;
        rm->count = tp->count;
        
        if(rm->count > 1)
        {
          rm->count -= 1; //////////////////////////////////////////////////
        }
        
        _remove(tp, tp->data);
    }
    else //  child on right || both
    {     
        Node* tp = findSmall(rm);
        rm->data = tp->data;
        rm->count = tp->count;
        
        if(rm->count > 1)
        {
          rm->count -= 1; //////////////////////////////
        }
        
        _remove(tp, tp->data);
    }

    return;
 
    // Traverse tree and search for node to remove
    // Five possible situations
    //  Item not found
    //  Removing a leaf
    //  Removing a node with one child - Left
    //  Removing a node with one child - Right
    //  Removing a node with two children
    
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
}

Node* BSTree::findBig(Node* n) // left find large
{
    Node* suc = n->left;
    
    while (suc->right != 0)  
    {
      suc = suc->right;
    }
      return suc;
}

Node* BSTree::findSmall(Node* n) // right find smallest
{
      // Find successor (leftmost child of right subtree)
    Node* suc = n->right;
    
    while (suc->left != 0)  
    {
      suc = suc->left;
    }
      return suc;
}

//==========================================================================

 void BSTree::visualizeTree(ofstream &out, Node *n)
 {
     if (n == 0)
     {
         return;
     }
     out << '\n';
     out << n->data << " [label=\"" << n->data;
     out << "\"];";
     if (n->left != 0)
     {
        out << "\n" << n->data << " -> " << (n->left)->data << ";";
        visualizeTree(out, n->left);
     }
     if (n->right != 0)
     {
        out << "\n" << n->data << " -> " << (n->right)->data << ";";
        visualizeTree(out, n->right);
     }
 }


 void BSTree::visualizeTree(const string &outputFilename)
 {
    ofstream outFS;
    outFS.open(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

//==========================================================================  
// public:

BSTree::~BSTree()
{
    //cout << "no real destructor" << endl;
    // while(root != 0)
    // {
    //   ;
    // }

}
//--------------------------------------------------

void BSTree::insert(const string& str) 
{
    if(!root) // 1st
    {
      Node* temp = new Node(str);
      this->root = temp;
    }
    else if(search(str)) // duplicate
    {
      Node* dup = _search(root, str);
      dup->count++;    
    }
    else
    {
        // normal algorithm
        Node* np = root;
        while(np != NULL)
        {
            if(str < np->data)
            {
                if(np->left == 0)
                {
                  np->left = new Node(str);
                  np->left->parent = np; //??
                  //np->left->count++;
                  np = 0;    
                }
                else
                {
                  np = np->left;
                }
            }
            else
            {
                if (np->right == 0)
                {
                  np->right = new Node(str);
                  np->right->parent = np; // ??
                  //np->right->count++;
                  np = 0;
                }
                else
                {
                  np = np->right;
                }
            }        
        } // end while
    }
    return;
}
//--------------------------------------------------

void BSTree::remove(const string& str)
{
    if(root == 0) // catch 
    {
      return;
    }
    Node* rm = _search(root, str);
    
    if(rm == 0) return;   
    else if(rm->count > 1) // duplicates
    {
        rm->count -= 1;///xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
        return;
    } 
    
    _remove(rm, str);
}
//--------------------------------------------------

bool BSTree::search(const string& str) const //XXX
{
  Node* temp = _search(root, str); // call helper function
  return temp != 0;
}
//--------------------------------------------------

const string BSTree::largest() const //XXX
{
    Node* cur = root;
    
    if(!cur) return "";
    
    while(cur)
    {
      if(cur->right != 0)
      {
        cur = cur->right;
      }
      else
      {
        return cur->data;
      }
    }
    
    return ""; // just in case
}
//--------------------------------------------------

const string BSTree::smallest() const //XXX
{
    Node* cur = root;
    
    if(!cur) return "";
    
    while(cur)
    {
      if(cur->left != 0)
      {
        cur = cur->left;
      }
      else
      {
        return cur->data;
      }
    }
    
    return ""; // just in case
}
//--------------------------------------------------

int BSTree::height(const string& str) const //XXX
{
    Node* tp = _search(root, str);
    
    if(!tp)
    {
      return -1;
    }
    
    if(!tp->left && !tp->right)
    {
      return 0;
    }
    return Hheight(tp);
}
//--------------------------------------------------
    

int BSTree::Hheight(Node* n) const{
  
    if (n == 0)
    {
        return -1;
    }

    int l = Hheight(n->left);
    int r = Hheight(n->right); 

    if (l > r)
    {
        return 1 + l;
    }
    else
    {
        return 1 + r;
    }
  
}
// #include "BSTree.h"

#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

// private:
// Node *root;

template<class T>  
void BSTree<T>::_preOrder(Node<T>* n) const //XXX
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

template<class T>
void BSTree<T>::_inOrder(Node<T>* n) const //XXX
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

template<class T>
void BSTree<T>::_postOrder(Node<T>* n) const //XXX
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

template<class T>
Node<T>* BSTree<T>::_search(Node<T>* tp, const T& x) const //XXX
{
    if(tp == NULL)
    {
      return 0;
    }
    else
    {
        if(tp->data == x)
        {
          return tp;
        }
        else if(tp->data > x)
        {
          return _search(tp->left, x);
        }
        else
        {
          return _search(tp->right, x);
        }
    }
}
//-------------------------------------------------------------------

template<class T>
void BSTree<T>::_remove(Node<T>* rm, const T& x)
{
    Node<T>* par = rm->parent;
    
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
        Node<T>* tp = findBig(rm);
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
        Node<T>* tp = findSmall(rm);
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

template<class T>
Node<T>* BSTree<T>::findBig(Node<T>* n) // left find large
{
    Node<T>* suc = n->left;
    
    while (suc->right != 0)  
    {
      suc = suc->right;
    }
      return suc;
}

template<class T>
Node<T>* BSTree<T>::findSmall(Node<T>* n) // right find smallest
{
      // Find successor (leftmost child of right subtree)
    Node<T>* suc = n->right;
    
    while (suc->left != 0)  
    {
      suc = suc->left;
    }
      return suc;
}

//==========================================================================

template<class T>
 void BSTree<T>::visualizeTree(ofstream &out, Node<T> *n)
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

template<class T>
 void BSTree<T>::visualizeTree(const string &outputFilename)
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

template<class T>
BSTree<T>::~BSTree()
{
    //cout << "no real destructor" << endl;

}
//--------------------------------------------------

template<class T>
void BSTree<T>::insert(const T& str) 
{
    if(!root) // 1st
    {
      Node<T>* temp = new Node<T>(str);
      this->root = temp;
    }
    else if(search(str)) // duplicate
    {
      Node<T>* dup = _search(root, str);
      dup->count++;    
    }
    else
    {
        // normal algorithm
        Node<T>* np = root;
        while(np != NULL)
        {
            if(str < np->data)
            {
                if(np->left == 0)
                {
                  np->left = new Node<T>(str);
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
                  np->right = new Node<T>(str);
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

template<class T>
void BSTree<T>::remove(const T& x)
{
    if(root == 0) // catch 
    {
      return;
    }
    Node<T>* rm = _search(root, x);
    
    if(rm == 0) return;   
    else if(rm->count > 1) // duplicates
    {
        rm->count -= 1;///xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
        return;
    } 
    
    _remove(rm, x);
}
//--------------------------------------------------

template<class T>
bool BSTree<T>::search(const T& x) const //XXX
{
  Node<T>* temp = _search(root, x); // call helper function
  return temp != 0;
}
//--------------------------------------------------

template<class T>
const T BSTree<T>::largest() const //XXX
{
    Node<T>* cur = root;
    
    if(!cur) return T();
    
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
    
    return T(); // just in case
}
//--------------------------------------------------

template<class T>
const T BSTree<T>::smallest() const //XXX
{
    Node<T>* cur = root;
    
    if(!cur) return T();
    
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
    
    return T(); // just in case
}
//--------------------------------------------------

template<class T>
int BSTree<T>::height(const T& x) const //XXX
{
    Node<T>* tp = _search(root, x);
    
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
    
template<class T>
int BSTree<T>::Hheight(Node<T>* n) const{
  
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
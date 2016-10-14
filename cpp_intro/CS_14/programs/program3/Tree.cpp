#include "Tree.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

Tree::~Tree()
{
   //??? 
   _clear(root);
   root = 0;
}
//--------------------------------------------------------------

void Tree::_clear(Node* n)
{
   if(!n) return;
   if(isLeaf(n))
   {   
      delete n;
      n=0;
   }
   else if(is2Node(n))
   {
      _clear(n->left);
      _clear(n->right);
      //delete n;
   }
   else
   {
      _clear(n->left);
      _clear(n->middle);
      //delete n;
      _clear(n->right);
      //delete n;
   }
}
//---------------------------------------------------------------------

bool Tree::isLeaf(Node* n)
{
   if(!n) return false;
   if(n->left == 0 && n->middle == 0 && n->right == 0)
   {
      return true;
   }
   return false;
}
//---------------------------------------------------------------

bool Tree::is2Node(Node* n)
{
   if(!n) return false;
   if(!n->small.empty() && n->large.empty())
   {
      return true;
   }
   return false;
}
//---------------------------------------------------------------

bool Tree::is3Node(Node* n)
{
   if(!n) return false;
   if(!n->small.empty() && !n->large.empty())
   {
      return true;
   }
   return false;
}
//---------------------------------------------------------------

void Tree::_preOrder( Node* n)
{
   if(!n) return;
   if(isLeaf(n))
   {
      cout << n->small << ',' << ' ';
      
      if(n->large != "")
      {
         cout << n->large << ',' << ' ';
      }
   }
   else if(is2Node(n))
   {
      cout << n->small << ',' << ' ';   
      _preOrder(n->left);
      _preOrder(n->right);
   }
   else
   {
      cout << n->small << ',' << ' ';   
      _preOrder(n->left);
      cout << n->large << ',' << ' ';
      _preOrder(n->middle);
      _preOrder(n->right);
   }
}
//---------------------------------------------------------------

void Tree::_inOrder( Node* n)
{
   if(!n) return;
   if(isLeaf(n))
   {
      cout << n->small << ',' << ' ';
      if(n->large != "")
      {
         cout << n->large << ',' << ' ';
      }
   }
   else if(is2Node(n))
   {
      //left
      _inOrder(n->left);
      cout << n->small << ',' << ' ';    
      //right
      _inOrder(n->right);
   }
   else
   {
      //left
      _inOrder(n->left);
      cout << n->small << ',' << ' ';
      //middle
      _inOrder(n->middle);
      cout << n->large << ',' << ' ';
      //right
      _inOrder(n->right);
   }
}
//---------------------------------------------------------------

void Tree::_postOrder( Node* n)
{
   if(!n) return;
   if(isLeaf(n))
   {
      cout << n->small << ',' << ' ';
      if(n->large != "")
      {
         cout << n->large << ',' << ' ';
      }      
   }
   else if(is2Node(n))
   {
      _postOrder(n->left);
      _postOrder(n->right);
      cout << n->small << ',' << ' ';  
   }
   else
   {
      _postOrder(n->left);
      _postOrder(n->middle);
      cout << n->small << ',' << ' ';
      _postOrder(n->right);
      cout << n->large << ',' << ' ';
   }
}
//---------------------------------------------------------------

bool Tree::search (const string &str)
{
   Node* t = _search(root, str);

   if(str == t->small || str == t->large) 
   {
      return true;
   }
   return false; // catch
}
//---------------------------------------------------------------

Node* Tree::_search(Node* n, const string& str)
{
   if(!n) return 0;
   else if(isLeaf(n))
   {
      // this part is so helper search can return leaf in the insert...
      return n;
   }
   else if(is2Node(n))
   {
      if(str == n->small || str == n->large)
      {
         return n;
      }
      else if(str < n->small)
      {
          return _search(n->left, str);
      }
      else
      {
          return _search(n->right, str);
      }
   }
   else //3node
   {
      if(str == n->small || str == n->large)
      {
         return n;
      }
      else if(str < n->small)
      {
          return _search(n->left, str);
      }
      else if( (n->small < str) && (str < n->large) )
      {
          return _search(n->middle, str);
      }
      else
      {
          return _search(n->right, str);
      }
   }
   return 0; // catch
}
//---------------------------------------------------------------****************************************************************************************

void Tree::insert(const string &str)
{
   //cout << "INSERT" << endl;

   if(!root)
   {
      Node* temp = new Node(str);
      root = temp;
      return;
   }
   
   Node* n = _search(root, str);
   
   if(isLeaf(n))
   {  
      if(is2Node(n)) // can just insert
      {        
         if(n->small < str)
         {
            n->large = str;
         }
         else
         {
            string x = n->small;
            n->large = x;
            n->small = str;
         }
         return;
      }
      else
      {
         _splitNode(n, str, 0, 0, 0, 0); // helper function
      }
   }     
   return; //??
}
//---------------------------------------------------------------

void Tree::_splitNode(Node* n, const string &str, Node* c1, Node* c2, Node* c3, Node* c4) 
{
   //cout << "SPLIT" << endl;
   
   if(!n) { cout << "ERR::Split" << endl; return; }
   
   string s = _findSml(n, str);
   string m = _findMid(n, str);
   string l = _findLrg(n, str);
   
   Node* p = 0;
   Node* n1 = new Node(s); // small
   Node* n2 = new Node(l); //large

   if(n == root)
   {
      //cout << "...n == root" << endl;
      p = new Node(m); //m
   }
   else
   {   
      p = n->parent;
   }
   n1->parent = p; 
   n2->parent = p; 
      
   if(!isLeaf(n))
   {         
      //cout << "n !leaf" << endl;

      //n1 becomes the parent of n’s two leftmost children
      n1->left = c1;
      n1->right = c2;
      c1->parent = n1;
      c2->parent = n1;
      
      //n2 becomes the parent of n’s two rightmost children
      n2->left = c3;
      n2->right = c4;
      c3->parent = n2;
      c4->parent = n2;
   } 

   if(is3Node(n) && is3Node(p)) // adding mid would cause an other split of parent
   {
      //cout << "n->parent == 3node, recurse split"  << endl; 
      
      Node* child1 = 0;
      Node* child2 = 0;
      Node* child3 = 0;
      Node* child4 = 0;
      
      if(n == p->left)
      {
        // cout << 'L' << endl;
         
         child1 = n1;
         child2 = n2;
         child3 = p->left;
         child4 = p->right;
      }
      else if(n == p->middle)
      {
         //cout << 'M' << endl;
         
         child1 = p->left;
         child2 = n1;
         child3 = n2;
         child4 = p->right;
      }
      else
      {
        // cout << 'R' << endl;   
         
         child1 = p->left;
         child2 = p->middle;//right??
         child3 = n1;
         child4 = n2;
      }
      
     _splitNode(p, m, child1, child2, child3, child4);  //p,m
   }
   
   //4 node under a 2 node
   if(is2Node(p))
   {
      //cout << " 3 node under a 2 node" << endl;
      
      if(n == root)
      {
         // cout << "n == root" << endl;
         // if(p==0)
         //    cout<<"null"<<endl;
         
         p->left = n1;
         p->right = n2;
         root = p; 
      }
      else if(n == p->left)
      {
         p->left = n1;
         p->middle = n2;
         p->large = p->small;
         p->small = m;
      }
      else
      {
         p->middle = n1;
         p->right = n2;
         p->large = m;
      }
   }
      // delete n;  //probably has memory leaks
      // n = 0;
      return;
}
//-----------------------------------------------------------------

string Tree::_findMid(Node* n, const string& str) // insert helper
{
   if(!n) return string();
   
   string mid;
   
   if(str < n->small)
   {
      mid = n->small;
   }
   else if(n->large <= str)
   {
      mid = n->large;
   }
   else
   {
      mid = str;
   }
   return mid;
}
//-----------------------------------------------------------------
string Tree::_findSml(Node* n, const string& str) // insert helper
{
   if(!n) return string();
   
   string s;
   
   if( str < n->small)
   {
      s = str;
   }
   else
   {
      s = n->small;
   }
   return s;
}
//-----------------------------------------------------------------

string Tree::_findLrg(Node* n, const string& str) // insert helper
{
   if(!n) return string();
   
   string l;
   
   if(n->large > str)
   {
      l = n->large;
   }
   else
   {
      l = str;
   }
   return l;
}
//-----------------------------------------------------------------*****************************************************************************************

void Tree::remove(const string &str)
{
   //cout << "REMOVE1" << endl;
   if(!root)
   {
      return;
   }
   else
   {
      Node* rm = _search(root, str);
      Node* leafly = 0;
      
      if(rm)
      {
         if(!isLeaf(rm))
         {
            Node *suc = _inOrderSuc(rm, str);
            if(str == rm->small)
            {
               swap(rm->small, suc->small);
            }
            else
            {
               swap(rm->large, suc->small);
            }
            
            leafly = suc;
         }
         else 
         {
            leafly = rm;
         }
      }
      
      if(str == leafly->small)// delete item from leaf
      {
         leafly->small = leafly->large;
         leafly->large = string();
      }
      else
      {
         leafly->large = string();
      }
      
      if(leafly->small.empty() && leafly->large.empty()) //fix empty leaf
      {
         _fix(leafly);
      }
   }
}
//--------------------------------------------------------------


void Tree::_fix(Node* n)
{
   //cout << "in the _fix" << endl;
   
   if(n == root)
   {
      //cout << "n == root" << endl;
      if(isLeaf(n))
      {
         delete n;
         root = 0;
         return;
      }
      else
      {
         //cout << " && not leaf" << endl;

         if(!root->right)
         {
            root = root->left;
         }
         else
         {
            root = root->right;
         }
      }
      // delete n;
      // n = 0;
      return;
   }
   else
   {
      //cout << "n != root..." << endl;
      
      Node* p = n->parent;
      
      Node* sibs = _sib(n);
      //cout << sibs->small  << '~' << sibs->large << endl;
   
      if(1 == 2) // redistribute -- 3node
      {
         //cout << "WOWOWOW" << endl;
      }
      else // merge -- 2node
      {
         //cout << "808" << endl;
         if(n == p->left)
         {
            sibs->large = p->small; // p item goes down to s
            p->small = p->large;
            p->large = string();
            //p->left = 0;
            p->left = p->middle;
            p->middle = 0;
         }
         else if(n == p->middle)
         {
            sibs->large = p->small; // p item goes down to s
            p->small = p->large;
            p->large = string();
            p->middle = 0;
         }
         else
         {  
            if(is3Node(p))
            {
               sibs->large = p->large; // p item goes down to s
               p->large = string();
            }
            else
            {
               sibs->large = p->small; // p item goes down to s
               p->small = string();
            }
            
            p->right = p->middle;//0
            p->middle = 0;
         }
         
         if(sibs->small > sibs->large)
         {
            swap(sibs->small, sibs->large);
         }
                  
         if(!isLeaf(n))
         {
            cout << "Nternal" << endl; //??
         }
         
         delete n;
         n = 0;
         
         if(p->small.empty() && p->large.empty())
         {
            _fix(p);
         }
      }
      
   }//endif
}
//-------------------------------------------------------------------------------

Node* Tree::_inOrderSuc(Node* n, const string& str)
{
   //??? if not good node
      
   if(isLeaf(n))
   {  
      return n;
   }
   else if(is2Node(n))
   {      
      if(str < n->small)
      {
         return _inOrderSuc(n->left, str);
      }
      else
      {
       return _inOrderSuc(n->right, str);
      }
   }
   else // 3 node
   {
      if(str < n->small)
      {
         return  _inOrderSuc(n->left, str);
      }
      else if( (n->small < str) && (str < n->large) )
      {
         return  _inOrderSuc(n->middle, str);
      }
      else
      {
         return _inOrderSuc(n->right, str);
      }
   }

}
//----------------------------------------------------------

Node* Tree::_sib(Node* n)
{
   if(!n) return 0;
   
   Node* p = n->parent;
   
   if(is2Node(p))
   {
      if(n == p->left)
      {
         return p->right;
      }
      else
      {
         return p->left;
      }
   }
   else
   {
      if(n == p->right)
      {
         return p->middle;
      }
      else if(n == p->middle)
      {
         return p->left;
      }
      else // left so retrun middle?
      {
         return p->middle;
      }
   }
   return 0;
}

//==========================================================================================================================
//==========================================================================================================================

void Tree::visualizeTree(const string &outputFilename)
{
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open())
    {
        cout<<"Error"<<endl;
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
//---------------------------------------------------

void Tree::visualizeTree(ofstream & outFS, Node *n)
{
    if(n)
    {
        string parentData = "\"" + n->small;
        if(n->large != "")
        {
            parentData += ", " + n->large + "\"";
        }
        else
        {
            parentData += "\"";
        }
        outFS<<parentData << "[ label = "<<parentData<<"];"<<endl;
        
        if(n->left)
        {
            string childData = "\"" + n->left->small;
            if(n->left->large!="")
            {
                childData += ", " + n->left->large + "\"";
            }
            else
            {
                childData += "\"";
            }
            visualizeTree(outFS,n->left);
            outFS<<parentData<<" ->  "<<childData<<";"<<endl;
        }
        
        if(n->middle)
        {
            string childData =  "\""+n->middle->small;
            if(n->middle->large!="")
            {
                childData += ", " + n->middle->large + "\"";
            }
            else
            {
                childData += "\"";
            }
            visualizeTree(outFS,n->middle);
            outFS<<parentData<<" ->  "<<childData<<";"<<endl;
        }
        
        if(n->right)
        {
            string childData =  "\"" + n->right->small;
            if(n->right->large != "")
            {
                childData += ", " + n->right->large + "\"";
            }
            else
            {
                childData += "\"";
            }
            visualizeTree(outFS,n->right);
            outFS<<parentData<<" ->  "<<childData<<";"<<endl;
        }
    }
}
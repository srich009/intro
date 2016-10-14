#include "AVLTree.h"

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

// private:
// Node *root;
  
  
 bool AVLTree::search(const string& str) const //XXX
{
  Node* temp = _search(root, str); // call helper function
  return temp != 0;
}
//--------------------------------------------------

Node* AVLTree::_search(Node* tp, const string& str) const //XXX
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

void AVLTree::insert( const string & myString )
{
   insert( myString, root, root ); 
   nodeCount++;
   cout << "Count: " << nodeCount << endl;
   
   //rotate && balance
    Node* tp = _search(root, myString); // just in
    
    cout << "The search node: " << flush << tp->data << endl;
    
    if ( nodeCount > 2 )
    {
      Node* xp = findUnbalancedNode(tp); // off ballance fron in
      
      if ( xp != NULL )
      {
        cout << "Actual unbalanced node: " << xp->data << endl;
  
        rotate(xp);
      }
    }
    
}
//----------------------------------------------------------------------

void AVLTree::insert( const string & myData, Node *& curNode, Node * papa )
{
	if ( root == NULL )
	{
		Node* temp = new Node( myData );
		root = temp;
	}

	else if ( curNode == NULL )
	{
		Node* temp = new Node( myData );

		curNode = temp;

		if ( curNode != root )
			curNode->parent = papa;

		return;
	}

	else if ( myData < curNode->data )
		insert( myData, curNode->left, curNode );


	else if ( myData > curNode->data )
		insert( myData, curNode->right, curNode );

	else if ( myData == curNode->data )
	{
		curNode->counter = curNode->counter + 1;
	}
	
}
//--------------------------------------------------


void AVLTree::_printBalanceFactors(Node* n)  //XXX
{
    if(n == NULL)
    {
      return;
    }
    
    _printBalanceFactors(n->left);
    cout << n->data << "(" << this->balanceFactor(n) << "), ";
    _printBalanceFactors(n->right);
}
//--------------------------------------------------

int AVLTree::balanceFactor(Node* n)
{
  // cout << "balance factor" << endl;
  int lc;
  int rc;
  
  if ( n == NULL )
    return -1;
  
  
  // cout << 'l' << endl;
   
  if(n->left != NULL)
  {
    lc = height(n->left, 0 );
  }
  else 
  {
    lc = -1;
  }
  
  
  // cout << 'r' << endl;
  if(n->right)
  {
    rc = height(n->right, 0);
  }
  else
  {
    rc = -1;
  }
  
  return (lc - rc);
}
//----------------------------------------------------

int AVLTree::height( Node * curNode, int amt ) const
{
	if ( curNode == NULL )
	{
	 // cout << "null in height" << endl;
		return -1;
	}

	int amtLeft = height( curNode->left, 0 );

	int amtRight = height( curNode->right, 0 );

	if ( amtLeft > amtRight )
		return amtLeft + 1;

	return amtRight + 1;
}
//--------------------------------------------------

bool AVLTree::isBalanced(Node* n)
{
  int g = balanceFactor(n); // n is the node just inserted
  return (g != 2 && g != -2);
}
//------------------------------------------------------------

Node* AVLTree::findUnbalancedNode( Node* n) //Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
{
  if ( n == NULL )
  {
    cout << "NULL Node" << endl;
    
    return NULL;
  }
  else if ( ( balanceFactor( n ) == 2 ) || ( balanceFactor( n )  == -2 ) ) // not n
  {
    cout << "There is a node that is not balanced -> " << n->data << endl;
    return n;
  }
  
  cout << "+ ";
  
  return findUnbalancedNode( n->parent );
  
}
//-------------------------------------------------------------------------------
  
void AVLTree::rotate(Node* n) // Implement four possible imbalance cases and update the parent of the given node.
{
    cout << "Rotation"  << endl;
    
  if(!n) return;
  
  int n1 = balanceFactor(n);
  int n2 = balanceFactor(n->right);
  
  cout << "n1: " << n1 << " n2: " << n2 << endl;
  
  if(isBalanced(n) || n == 0)
  {
    return;
  }
  else if( n1 == 2 && n2 == 1 ) // 2, 1 : L,L
  {
    /*Node* temp = */rotateRight( n->left );
  }
  else if(n1 == 2 && n2 == -1) // 2, -1 : L,R
  {
  /*  Node* temp =*/ rotateLeft(n->right);
  /*  Node* temp = */rotateRight(n->left);
  }
  else if(n1 == -2 && n2 == -1) // -2, -1 : R,R
  {
   /* Node* temp = */rotateLeft( n->right);
  }
  else // -2, 1 : R,L
  {
    /*Node* temp =*/ rotateRight(n->right);
  // /* Node* temp = */rotateLeft(n->right);
  }

}
//-------------------------------------------------------------

Node* AVLTree::rotateLeft(Node* n) //Rotate the subtree to left at the given node and returns the new subroot.
{
  
    cout << "in rotate left" << endl;
    cout << n->data << endl;
    
  if ( n->parent == root )
  {
    cout << "True " << endl;
    
    if ( n->parent->right == n  )
    {
      
      n->left = n->parent;
      (n->left)->parent = n;
      (n->left)->right = 0;
      n->parent = 0;
      root = n;
      
      cout << "Root: " << root->data << " Left: " << root->left->data
        << " Right: " << root->right->data << endl;
    }
  }
    
  return n;
}
//--------------------------------------------------------------------

Node* AVLTree::rotateRight(Node* n) // Rotate the subtree to right at the given node and returns the new subroot.
{
  cout << "in rotate right" << endl;
  
  cout << '~' << flush << n->data << '~' << endl;
    
  if ( n->parent == root )
  {
    cout << "True " << endl;
    
    if ( n->parent->left == n  )
    {
      cout << "if is true" << endl;
      
      n->right = n->parent;
      (n->right)->parent = n;
      (n->right)->left = 0;
      n->parent = 0;
      root = n;
      
      cout << "Root: " << root->data << " Left: " << root->left->data
       << " Right: " << root->right->data << endl;
    }
    
    else
    {
      cout << "else is true" << endl;
      
      string temp = n->data;
      n->right = n;
      n = n->left; 
      n->left = NULL;
  
          cout << "Root: " << root->data << " Right: " << root->right->data
       << " Right-Right: " << root->right->right->data << endl;
      // swap(n->left, n->right);
      // swap(n->data, n->right->data);
      
      // n->left= n->parent;
      // n->left->parent = n;
      // n->parent = 0;
      // n->left->right = 0;
      
    }
  }
  
  return n;
}
//--------------------------------------------------------------------


//graphiz
//===========================================================
void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
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
//----------------------------------------------------------------------------

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}
//===========================================================

void AVLTree::testBalance( ) //test function
{
  Node* tp = _search(root, "c");
  Node* xp = findUnbalancedNode(tp);
  
  cout << xp->data << endl;
  
}
//-----------------------------------------------------
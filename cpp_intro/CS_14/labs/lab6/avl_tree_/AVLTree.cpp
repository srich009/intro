// Jonathan Herrera
// Shaun Richardson


#include "AVLTree.h"

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;


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
  // cout << "\t\t\tInserting " << myString << endl;

   insert( myString, root, root ); 
   nodeCount++;
   // _printBalanceFactors( root ); cout << endl;
   
   //rotate && balance
    Node* tp = _search(root, myString); // just in
    
    if ( nodeCount > 2 )
    {
      Node* xp = findUnbalancedNode(tp); // off ballance fron in
      
      if ( xp != NULL )
      {
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
    
    return NULL;
  }
  else if ( ( balanceFactor( n ) == 2 ) || ( balanceFactor( n )  == -2 ) ) // not n
  {
    return n;
  }
  
  return findUnbalancedNode( n->parent );
}
//-------------------------------------------------------------------------------
  
void AVLTree::rotate(Node* n) // Implement four possible imbalance cases and update the parent of the given node.
{
  // cout << "Rotation"  << endl;
    
  if(!n) return;
  
  int n1 = balanceFactor( n );
  int n2;

  if ( n->data <= root->data )
    n2 = balanceFactor( n->left );
  
  else
    n2 = balanceFactor( n->right );

  // cout << "n1: " << n1 << " n2: " << n2 << endl;
  
  if(isBalanced(n) || n == 0)
  {
    return;
  }

  else if( n1 == 2 && n2 == 1 ) // 2, 1 : L,L
  {
    if ( nodeCount == 3 )
    {
      root = rotateRight( n, n->left );
    }
    else
      root->right = rotateRight( n, n->left );
    // cout << "X" << endl;
  }

  else if(n1 == 2 && n2 == -1) // 2, -1 : L,R
  {
    if ( root->left->left->right != NULL )
    {
        // cout << "@" << endl; cout << "@" << endl;
        root->left->left = rotateLeft( n->left, n->left->right );
        // visualizeTree("test.txt");
        root->left = rotateRight( n, n->left );
    }
    else
    {
      // cout << "@" << endl;
      root->left = rotateLeft( n->left, n->left->right );
    

      // visualizeTree("test.txt");
      root = rotateRight( n, n->left );
    }
  }

  else if(n1 == -2 && n2 == -1) // -2, -1 : R,R
  {
    if ( nodeCount == 3 )
    {
      root = rotateLeft( n, n->right );
    }
    else
      root->left = rotateLeft( n, n->right );
  }

  else // -2, 1 : R,L
  {
    if ( root->right->right->left != NULL )
    {
      // cout << "XX" << endl;
      root->right->right = rotateRight( n->right, n->right->left );
      root->right = rotateLeft( n, n->right ); 
    }

    else
    {
       root->right = rotateRight( n->right, n->right->left );
   
       root = rotateLeft( n, n->right );
    }
   
  }

}
//-------------------------------------------------------------

Node* AVLTree::rotateLeft(Node* papa, Node* child ) //Rotate the subtree to left at the given node and returns the new subroot.
{
  // cout << "in rotate left -- " << papa->data << " " << child->data << endl;
  Node* tmp = papa->parent;
  Node* maybeEmpty = child->left;

  papa->right = maybeEmpty;

  if ( maybeEmpty != NULL )
    maybeEmpty->parent = papa;

  child->left = papa;
  papa->parent = child;
  child->parent = tmp;

  // cout << child->right->data << endl;


  // cout << bNode->data << endl;
  // cout << bNode->right->data << endl;
  // cout << bNode->right->parent->data << endl;
  // cout << bNode->parent->data << endl;

  return child;
}
//--------------------------------------------------------------------

Node* AVLTree::rotateRight(Node* papa, Node* child ) // Rotate the subtree to right at the given node and returns the new subroot.
{
  // cout << "in rotate right -- " << papa->data << " " << child->data << endl;
  Node* tmp = papa->parent;
  Node* maybeEmpty = child->right;

  papa->left = maybeEmpty;

  if ( maybeEmpty != NULL )
    maybeEmpty->parent = papa;

  child->right = papa;
  papa->parent = child;
  child->parent = tmp;
  
  // cout << bNode->left->data << endl;

  // cout << child->data << endl;

  // if 

  return child;
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

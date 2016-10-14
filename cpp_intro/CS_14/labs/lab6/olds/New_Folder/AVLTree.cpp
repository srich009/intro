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
  cout << "\t\t\tInserting " << myString << endl;

   insert( myString, root, root ); 
   nodeCount++;
   // cout << "Count: " << nodeCount << endl;
   
   //rotate && balance
    Node* tp = _search(root, myString); // just in
    
    // cout << "The search node: " << flush << tp->data << endl;

    if ( nodeCount > 2 )
    {
      Node* xp = findUnbalancedNode(tp); // off ballance fron in
      
      if ( xp != NULL )
      {
        cout << "Actual unbalanced node: " << xp->data << endl;
  
        rotate(xp);
      }
    }
    
    // rotate(root)
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
    // cout << "NULL Node" << endl;
    
    return NULL;
  }
  else if ( ( balanceFactor( n ) == 2 ) || ( balanceFactor( n )  == -2 ) ) // not n
  {
    // cout << "There is a node that is not balanced -> " << n->data << endl;
    return n;
  }
  
  // cout << "+ ";
  
  return findUnbalancedNode( n->parent );
  
}
//-------------------------------------------------------------------------------
  
void AVLTree::rotate(Node* n) // Implement four possible imbalance cases and update the parent of the given node.
{
  cout << "Rotation"  << endl;
    
  if(!n) return;
  
  int n1 = balanceFactor(n);
  int n2;

  if ( n->data <= root->data )
    n2 = balanceFactor(n->left);
  
  else
    n2 = balanceFactor(n->right);

  // cout << "n1: " << n1 << " n2: " << n2 << endl;
  
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
    n->left = rotateLeft(n->left);
    visualizeTree("one.txt");
    // cout << "n left is : " << n->data << endl;
    n->parent->left = rotateRight(n->left);
    visualizeTree("two.txt");
  }
  else if(n1 == -2 && n2 == -1) // -2, -1 : R,R
  {
   /* Node* temp = */rotateLeft( n->right);
  }
  else // -2, 1 : R,L
  {
    // visualizeTree("zero.txt");
    n->right = rotateRight(n->right);
    visualizeTree("one.txt");
    n->parent->right = rotateLeft(n->right);
    visualizeTree("two.txt");
  }

}
//-------------------------------------------------------------

Node* AVLTree::rotateLeft(Node* n) //Rotate the subtree to left at the given node and returns the new subroot.
{
  
  cout << "in rotate left -- " << n->data << endl;
    
  if ( n->parent == root )
  {
    // cout << "True " << endl;
    
    if ( n->parent->right == n  )
    {

      cout << root->data << endl;
      cout << root->right->data << endl;

      if ( root->data == "Chan" )
        cout << root->right->right->data << endl;


      cout << "if is true " << endl;   
      Node* tempNode = new Node( n->parent->data );
      cout << "??" << endl;
      n->left        = tempNode;
      cout << "??" << endl;

      root           = n;
      n->parent      = NULL;
      cout << "??" << endl;

      cout << root->data << endl;

      if ( root->data == "Chan" )
       // cout << root->right->right->data << endl;
      cout << root->right->data << endl;


       

      // cout << "\t" << n->right->data << endl;
      return root;
    }

    else
    {
      cout << "else is true" << endl;
      Node* tempNode   = new Node( n->data );
      n->data          = n->right->data;
      n->right         = NULL;
      n->left          = tempNode;
      tempNode->parent = n;
      
    }
  }
    if ( n->parent->right == n  )
    {
      cout << "if is true" << endl;
      
      Node* tempNode  = new Node( n->parent->data );
      n->parent->data = n->data;
      n->left         = tempNode;
      tempNode->parent = n;
      n->parent = n->parent->parent;

      cout << "\t 4-N -> " << n->data << " parent is " << n->parent->data << endl; 
      cout << "\t\ttemp " << tempNode->data << " parent is " << tempNode->parent->data << endl;
      // cout << "\t" << n->data << endl;
    }
    
    else
    {
      cout << "else is true" << endl;
      Node* tempNode   = new Node( n->data );
      n->data          = n->right->data;
      // cout << "TEST " << endl;
      n->right         = NULL;
      n->left          = tempNode;
      tempNode->parent = n;
      
    }
    
  return n;
}
//--------------------------------------------------------------------

Node* AVLTree::rotateRight(Node* n) // Rotate the subtree to right at the given node and returns the new subroot.
{
  cout << "in rotate right -- " << n->data <<endl;
  
  // cout << '~' << flush << n->data << '~' << endl;
    
  if ( n->parent == root )
  {
    // cout << "True " << endl;
    
    if ( n->parent->left == n  )
    {
      // cout << "if is true" << endl;
      
      Node* tempNode = new Node( n->parent->data );
      n->right       = tempNode;
      n->parent      = NULL;
      root           = n;
      // cout << "\t" << n->right->data << endl;
      return root;
      
      cout << "\t1-N -> " << n->data << " parent is " << n->parent->data << endl; 
      // cout << "Root: " << root->data << " Left: " << root->left->data
       // << " Right: " << root->right->data << endl;
    }
    
    else
    {
      // cout << "else is true" << endl;
      Node* tempNode   = new Node( n->data );
      n->data          = n->left->data;
      n->left          = NULL;
      n->right         = tempNode;
      tempNode->parent = n;
      // n->parent = n->parent->parent;

      cout << "\t2-N -> " << n->data << " parent is " << n->parent->data << endl; 
      // cout << "Root: " << root->data << " Right: " << root->right->data
       // << " Right-Right: " << root->right->right->data << endl;
      
    }
  }

  else
  {
    if ( n->parent->left == n  )
    {
      cout << "if is true" << endl;
      
      Node* tempNode  = new Node( n->parent->data );
      n->parent->data = n->data;
      n->right        = tempNode;

      cout << "\t3-N -> " << n->data << " parent is " << n->parent << endl; 
      // cout << "Root: " << root->data << " Left: " << root->left->data
      //  << " Right: " << root->right->data << endl;
    }
    
    else
    {
      cout << "else is true" << endl;
      Node* tempNode   = new Node( n->data );
      n->data          = n->left->data;
      n->left          = NULL;
      n->right         = tempNode;
      tempNode->parent = n;

      cout << "\t 4-N -> " << n->data << " parent is " << n->parent->data << endl; 
      cout << "\t\ttemp parent is " << tempNode->parent->data << endl;
      // cout << "Root: " << root->data << " Right: " << root->right->data
      //  << " Right-Right: " << root->right->right->data << endl;
      
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
  Node* tp = _search(root, "carr");
  // Node* xp = findUnbalancedNode(tp);
  
  // cout << tp->parent->data << " " /* << tp->parent->parent->data << " " <<  tp->parent->parent->parent->data*/ << endl;
  
}
//-----------------------------------------------------
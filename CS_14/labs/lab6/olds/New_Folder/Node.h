#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <string> 

// #include "BSTree.h"

using namespace std;

class Node
{
	friend class AVLTree;
	private:
		int counter;
		string data;
		// char key;
		Node* left;
		Node* right;
		Node* parent;
		Node* dummyRoot;

	public:

		Node( )
		{
			counter = 0;
			data = "";
			// key = 0;
			left = NULL;
			right = NULL;
			parent = NULL;
		}

		Node( string usrData )
		{
			counter = 1;
			data = usrData;
			// key = 0;
			left = NULL;
			right = NULL;
			parent = NULL;
		}
};



#endif
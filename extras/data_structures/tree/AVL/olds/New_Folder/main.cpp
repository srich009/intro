#include <iostream>
#include "AVLTree.h"

using namespace std;

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Print" << endl
    << "3. Quit" << endl;
  cin >> choice;

  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(256, '\n');
  return choice;
}

int main( ) {

  AVLTree tree;

  tree.insert( "Adam" );
  tree.insert( "Bui" );
  tree.insert( "Chan" );
  tree.insert( "Edie" );
  tree.insert( "Dan" );

  int choice = menu();

  string entry;

  while (choice != 3) {

    if (choice == 1) {
      cout << "Enter string to insert: ";
      getline(cin, entry);
      cout << endl;

      tree.insert(entry);

    } else if (choice == 2) {

      tree.printBalanceFactors();
    } 
    //fix buffer just in case non-numeric choice entered
    choice = menu();
  }
  
  //tree.testBalance();
  
  //tree.testBalance( );
  tree.visualizeTree("final.txt");

  return 0;
}
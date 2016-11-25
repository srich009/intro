//g++ WordLadder.cpp main.cpp -Wall -Werror -o a.out

#include "WordLadder.h"

#include <iostream>

using namespace std;

int main() {
   string dictName, wordBegin, wordEnd, outFile; // added outfile
   
   cout << "Enter the name of the dictionary file: ";
   cin >> dictName;
   cout << endl;
   cout << "Enter the first word: ";
   cin >> wordBegin;
   cout << endl;
   while (wordBegin.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the first word: ";
      cin >> wordBegin;
      cout << endl;
   }
   cout << "Enter the last word: ";
   cin >> wordEnd;
   cout << endl;
   while (wordEnd.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the last word: ";
      cin >> wordEnd;
      cout << endl;
   }
   
   cout << "enter output file name: ";
   cin >> outFile;
   
	WordLadder wl(dictName);
	
	wl.outputLadder(wordBegin, wordEnd, outFile); // correction, takes a outfile as 3rd arg
	cout << endl;
	
	return 0;
}
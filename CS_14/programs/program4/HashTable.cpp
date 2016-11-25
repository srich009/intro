#include "HashTable.h"
#include "WordEntry.h"

#include <iterator>
using namespace std;

/*////////////////////////////////////////
	list<WordEntry> *hashTable;
	int size;
*//////////////////////////////////////////

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) 
{
   hashTable = new list<WordEntry>[s];
   size = s;
}
//----------------------------------------------------------------

/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) 
{
   //key -> int value 
   //int value % size (compression map)
   
   long long hash = 0; 
   int val = 0;
   
   for(unsigned i = 0; i < s.size(); i++)
   {
      int k = static_cast<int>(s.at(i)); // k = ascii val of s.at(i)
      hash += (hash << 5) + k;           // (hash * 2^x) +k
   }

   val = hash % size; // compression map...?

   if(val > size)
   {
      //cout << "ERROR, greater than size" << endl;  
   }
   else if(val < 0)
   {
      //cout << "ERROR, negative, *(-1) to fix..." << endl; 
      val *= -1;
   }
   return val;
}

//----------------------------------------------------------------

/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) 
{
   int x = computeHash(s);               // index of entry in arr
	list<WordEntry> listy = hashTable[x]; // list contained at index x
	
   list<WordEntry>::iterator it = listy.begin();
   for( ; it != listy.end(); it++ ) 
   {
      if(it->getWord() == s)
      {
         it->addNewAppearance(score);
         hashTable[x] = listy;
         return;
      }
   }

   listy.push_back(WordEntry(s, score));
   hashTable[x] = listy;
}
//----------------------------------------------------------------

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) 
{
   int x = computeHash(s); 
   list<WordEntry> listy = hashTable[x];
   
   list<WordEntry>::iterator it = listy.begin();
   for( ; it != listy.end(); it++ )
   {
      if(it->getWord() == s)
      {      
         return it->getAverage();
      }
   }
   return 2.0; // neutral
}

//----------------------------------------------------------------

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) 
{
   int x = computeHash(s); 
   list<WordEntry> listy = hashTable[x];

   list<WordEntry>::iterator it = listy.begin();
   for( ; it != listy.end(); it++ )
   {
      if(it->getWord() == s)
      {
         return true;
      }
   }
   return false;
}


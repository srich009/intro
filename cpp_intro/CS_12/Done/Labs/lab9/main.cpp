//Lab 9 merge sort

#include "Card.h"
#include "Deck.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//Global Function Declarations

void fillHand(vector<Card> &hand, Deck &d, unsigned handSize);

ostream & operator<<(ostream &, const vector<Card> &);

void sortBySuit(vector<Card> &v);

void mergeSort(vector<Card> &v, unsigned begin, unsigned end);

void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end);


int main() 
{
   vector<Card> hand;
   Deck deck;
   int handSize;
   int seed;
   cout << "Enter seed value: ";
   cin >> seed;
   cout << endl;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(seed);
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;
   sortBySuit(hand);
   cout << hand << endl;
   return 0;
}
//===============================================================
//===============================================================


//Global Function Implementation

void fillHand(vector<Card> &hand, Deck &d, unsigned handSize)
{
   hand.resize(handSize);
   for (unsigned i = 0; i < hand.size(); ++i) 
   {
      hand.at(i) = d.dealCard();
   }
}
//-----------------------------------------------------------------

/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &out, const vector<Card> &vC)
{
    if(vC.empty())
    {
        return out;
    }
    
    unsigned i = 0;
 
    for(; i < vC.size() - 1; i++)
    {
        out << vC.at(i) << ", ";
    }
    // last card
     out << vC.at(i); 
     
    return out;
}
//------------------------------------------------------------------------



/* Sorts the contents of v into suit order,
   i.e., all clubs first (in numerically ascending order),
   then all diamonds (in ascending order),
   then all hearts (in ascending order),
   and finally all spades (in ascending order).
   Calls mergeSort recursive function to actually sort the vector.
*/
void sortBySuit(vector<Card> &v)
{
    if(v.empty())
    {
        return;
    }
    
    
    unsigned b = 0;
    unsigned e = v.size() - 1;
    
    mergeSort(v, b, e);
    
    return;
}
//---------------------------------------------------------------

/* Uses the recursive merge sort algorithm to sort the contents
   of the vector from begin to end in suit order.
   (see above SortBySuit function for definition of suit order)
   Uses merge helper function to merge the two sorted
   halves.
*/
void mergeSort(vector<Card> &v, unsigned begin, unsigned end)
{
    unsigned mid = 0;
    
    if(begin < end)
    {
        mid = (begin + end) / 2; // find mid
        
        // Recursively sort left and right partitions
        mergeSort(v, begin, mid);   //L
        mergeSort(v, mid + 1, end); //R
        
        // Merge left and right after sort
        merge(v, begin, mid, end);
    }
    
    return;
}
//----------------------------------------------------------------------

/* Assumes all values from begin to mid are in suit order,
   (see above SortBySuit function for definition of suit order)
   and all values from mid + 1 to end are in suit order.
   Merges the two halves so that all values from begin to end
   are in suit order.
*/
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end)
{
    unsigned mergeSize = end - begin + 1;
    
    vector<Card> copy(mergeSize);
    
    unsigned mergePos = 0;                 // Position to insert merged number
    unsigned leftPos = 0;                  // Position of elements in left partition
    unsigned rightPos = 0;                 // Position of elements in right partition

    leftPos = begin;
    rightPos = mid + 1;
    
    while(leftPos <= mid && rightPos <= end)
    {
        if( (v.at(leftPos)).getSuit() < (v.at(rightPos)).getSuit() ) // compare suits
        {
             copy.at(mergePos) = v.at(leftPos);
             ++leftPos;
        }
        else  if( (v.at(leftPos)).getSuit() == (v.at(rightPos)).getSuit() ) // compare suits
        {
            if( (v.at(leftPos)).getRank() < (v.at(rightPos)).getRank() ) // compare rank
            {
                copy.at(mergePos) = v.at(leftPos);
                ++leftPos;
            }
            else 
            {
                 copy.at(mergePos) = v.at(rightPos);
                 ++rightPos;
            }
        }
        else 
        {
             copy.at(mergePos) = v.at(rightPos);
             ++rightPos;
        }
        ++mergePos;
    }
    
    // If left partition is not empty
    while(leftPos <= mid)
    {
      copy.at(mergePos) = v.at(leftPos);
      ++leftPos;
      ++mergePos;
    }
    
    // If right partition is not empty
    while(rightPos <= end)
    {
      copy.at(mergePos) = v.at(rightPos);
      ++rightPos;
      ++mergePos;
    }
    
     // Copy merge back
    for(mergePos = 0; mergePos < copy.size(); ++mergePos)
    {
        v.at(begin + mergePos) = copy.at(mergePos);
    }




return;
}



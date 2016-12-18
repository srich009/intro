#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;


///CLASS HEADER FILES
#include "Card.h"
#include "Deck.h"


///GLOBAL FUNCTION PROTOTYPES
bool hasPair(const vector<Card> &);
/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/


ostream & operator<<(ostream &, const vector<Card> &);
/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/


///MAIN
int main()
{
    srand(2222);
    
    /// MAIN CODE BODY -- FINISH
    string decision;
    int numDeals = 0;
    int cardsPerHand = 0;
    ofstream outFS; // Output file stream
    int counter = 0;
    
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> decision;
    cout << endl;
    
    if(decision == "Yes")
    {
        string fileName;
        cout << "Enter name of output file: ";
        cin >> fileName;
        cout << endl;
        
                
               ///file stream????
               // Open file
               outFS.open(fileName.c_str());
               
               if (!outFS.is_open()) 
               {
                  cout << "Could not open file" << endl;
                  return 1;
               }
        
    }

    cout << "Enter number of cards per hand: "; 
    cin >> cardsPerHand;
    cout << endl;
    
    cout << "Enter number of deals (simulations): ";
    cin >> numDeals;
    cout << endl;
        
    
    vector<Card> testVector; // hand of cards played in deal
    
    Deck testDeck; // test deck size 52; K of Spades -> A of Club

    testDeck.shuffleDeck(); // shuffles deck before the deal
    
    //DEAL LOOP
    unsigned k = static_cast<unsigned>(numDeals);
    
    for(; k > 0; k--)  //number of deals
    {    
        unsigned j = static_cast<unsigned>(cardsPerHand);
        
        for(; j > 0; j--) // cards per hand
        {
            testVector.push_back(testDeck.dealCard());
        }
                 
                if(hasPair(testVector))
                {
                    counter++;
                }
                    
            if(decision == "Yes")
            {
                if(hasPair(testVector))
                {
                    counter++;
                    outFS << "Found Pair!! ";
                }
                else
                {
                    outFS << "             "; // no pair
                }
                
                //Display??
                for(unsigned i = 0; i < testVector.size() - 1; i++)
                {
                    outFS << testVector.at(i) << ", ";
                }
                outFS << testVector.at(testVector.size() - 1);
                outFS << endl;
             }
                
                testVector.clear(); // empty after deal to refill for next deal


            testDeck.shuffleDeck(); // shuffle deck after deal
    }
    
 cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " << static_cast<double>(counter) / static_cast<double>(numDeals)  * 100 << "\%" << endl;
 
    // Done with file, so close it
    if(decision == "Yes")
    {
        outFS.close();
    }
    
return 0;
}


///GLOBAL FUNCTION DEFINITIONS
bool hasPair(const vector<Card> &vC)
{
    
    if(vC.size() == 1) // if vector of 1 card
    {
        return false;
    }
    
    for(unsigned z = 0; z < vC.size(); z++)
    {
        for( unsigned w = z + 1; w < vC.size(); w++ )
        {
            if(vC.at(w).getRank() == vC.at(z).getRank())
            {
                return true;
            }
        }
    }
    
    return false;
}
/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/


ostream & operator<<(ostream &out, const vector<Card> &vC)
{
    unsigned i = 0; 
    for(; i < vC.size() - 1; i++)
    {
        out << vC.at(i) << ", ";
    }
    // last card
    out << vC.at(i + 1);
       
    return out;
}
/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
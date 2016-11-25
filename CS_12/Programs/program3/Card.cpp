
#include <iostream>
#include <vector>

using namespace std;

#include "Card.h"

//card class uses:
//private: char suit; int rank;


    Card::Card()
    {
        rank = 2;
        suit = 'c';
        return;
    }
    /* Assigns a default value of 2 of Clubs
    */

  
    Card::Card(char s, int r)
    {
        //set rank of card
        if(r > 0 && r < 14)
        {
            rank = r;
        }
        else
        {
            rank = 2;
        }
        
        suit = tolower(s);  // ?? tolower all variables??
           
        return;
    }
    /* Assigns the Card the suit and rank provided.
       suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
       If an invalid suit is provided, sets the suit to Clubs
       ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
       If an invalid rank is provided, sets the rank to 2
       Accepts lower or upper case characters for suit
    */


    char Card::getSuit() const
    {
        return tolower(suit);  // ?? to lower all variables??
    }
    /* Returns the Card's suit
    */


    int Card::getRank() const
    {
        return rank;
    }
    /* Returns the Card's rank as an integer
    */
  
    ostream & operator<<(ostream &outs, const Card &XXX)
    {
        ///RANK
        if(XXX.rank == 1)
        {
            outs << "Ace of ";
        }
        else if(XXX.rank == 11)
        {
            outs << "Jack of ";
        }
        else if(XXX.rank == 12)
        {
            outs << "Queen of ";
        }        
        else if(XXX.rank == 13)
        {
            outs << "King of ";
        } 
        else
        {
            outs << XXX.rank << " of ";
        }
        
        ///SUIT
        if(XXX.suit == 'c')
        {
            outs << "Clubs";
        }
        else if(XXX.suit == 'd')
        {
            outs << "Diamonds";
        }
        else if(XXX.suit == 'h')
        {
            outs << "Hearts";
        }
        else
        {
            outs << "Spades";
        }
        
        return outs;
    }
    /* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
    */
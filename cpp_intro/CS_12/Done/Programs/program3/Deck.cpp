#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Card.h"
#include "Deck.h"

//card class uses:
//private: char suit; int rank;

//Deck class uses:
// private: vector<Card> theDeck; vector<Card> dealtCards;


    Deck::Deck()
    {
 
        for(unsigned i = 13; i > 0; i--) //SPADES
        {
            theDeck.push_back(Card('s', i ));
        }
        for(unsigned i = 13; i > 0; i--) // HEARTS
        {
            theDeck.push_back(Card('h', i ));
        }
        for(unsigned i = 13; i > 0; i--) //DIAMONDS
        {
            theDeck.push_back(Card('d', i ));
        }
        for(unsigned i = 13; i > 0; i--) // CLUBS
        {
            theDeck.push_back(Card('c', i ));
        }
          
    }
    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
    */


    Card Deck::dealCard() 
    {
        Card temp = theDeck.at(theDeck.size() - 1);
        theDeck.pop_back();
        dealtCards.push_back(temp);
        return temp; 
    }
    /* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
    */
    

    void Deck::shuffleDeck()
    {
        if(dealtCards.size() != 0)       
        {
            //MOVE CARDS BACK IN
            for(unsigned i = 0; i < dealtCards.size(); i++)
            {
                theDeck.push_back(dealtCards.at(i));
            }
            //CLEAR VECTOR DEALT CARDS
            dealtCards.clear();
        }   
        
        //RANDOM SHUFFLE THE DECK
        random_shuffle(theDeck.begin(), theDeck.end());
        return;
    }
    /* Places all cards back into theDeck and shuffles them into random order.
    Uses random_shuffle function from algorithm standard library.
    */
    

    unsigned Deck::deckSize() const
    {
        return theDeck.size();
    }
    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
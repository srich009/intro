// program 6
// pig dice game

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int WINNING_SCORE = 100;


//Implement the printIntro function
void printIntro()
{
    cout << "Welcome to the dice game Pig!" << endl;
    cout << "The objective is to be first to score 100 points." << endl;
    cout << endl;
    
 return;   
}


//Implement the humanTurn function
int humanTurn(string userName, int enteredScore)
{
    int oldScore = enteredScore; // new function for when roll pig, to return the amt of points they had before the current turn
    int userScore = enteredScore; // was enteredScore and then add user rolls to it.
    int userRoll = 0;
    char rollAgain = 'y';
    
    while(rollAgain == 'y')
    {
    
        userRoll = rand() % 6 + 1;
       
         
         if(userRoll == 1)
         {
            cout << userName << endl;
            cout << "You rolled a 1 (PIG!)" << endl;
            cout << "Your turn is over" << endl;
            cout << "Your score: " << oldScore << endl; // userScore to oldScore
            cout << endl;
            return oldScore; // changed userSCore to oldSCore
    
         }
         
         else
         {
            userScore =  userScore + userRoll;
            
            if(userScore < 100)
            {
            cout << userName << endl;
            cout << "You rolled a " << userRoll << endl;
            cout << "Your score: " << userScore << endl;
            cout << "Do you want to roll again? (y/n): ";
            cin >> rollAgain;
            cout << endl;
                if(rollAgain != 'y')
                {
                    return userScore;
                }
            
            }
            
            //Output who won the game.
            else
            {
            cout << userName << endl;
            cout << "You rolled a " << userRoll << endl;
            cout << "Your score: " << userScore << endl;
            cout << endl;
            cout << userName << " wins!" << endl;
            
                 return userScore; //FIXME ??? move? 
            }
            
            
            
         }
         
    }
     
 return userScore;
}



int main() 
{
    srand(4444);

    // setup and initialize variables
    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name;
    string player2name;

    printIntro();

    //get names of players
    cout << "Player 1 - Enter your name: ";
    cin >> player1name;
    cout << endl;
    cout << "Player 2 - Enter your name: ";
    cin >> player2name;
    cout << endl;


    
    //play game
    while (player1score < WINNING_SCORE && player2score < WINNING_SCORE)
    {

        //player 1's turn or player 2's turn
        if (turn == PLAYER1)
        {
            player1score = humanTurn(player1name, player1score);
            turn = PLAYER2;
            
        }
        else if(turn == PLAYER2)
        {
            player2score = humanTurn(player2name, player2score);
            turn = PLAYER1;
        }
        

    }

    

    return 0;
}



/*
xxx(Step 1) Implement the printIntro function (This is Test 1)

xxx(Step 2) Get the names of the 2 players (This is Test 2)

xx (Step 3) Implement the logic to switch who's turn it is in main function.

xxx(Step 4) Implement humanTurn function to roll once (This is Test 3)

xxx(Step 5) Implement humanTurn function to keep rolling until player answers n. (This is Test 4)

xx (Step 6) Implement humanTurn function to end when player rolls a 1. (This is Test 5)

xx(Step 7) Finish main function to output who won. (Last test will test entire program)

*/
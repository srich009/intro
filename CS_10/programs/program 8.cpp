// program 8 Tic Tac Toe

#include <vector>
#include <iostream>

using namespace std;

const bool CLEAR_SCREEN = true;


/// @brief Utilizes an escape character sequence to clear the screen
// DO NOT MODIFY
void clearScreen()
{
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }

    cout << endl;

    return;
}

//======================================================================================================================
/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
// DO NOT MODIFY
void drawBoard(const vector < char >&gameBoard)
{
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;

    return;
}

//========================================================================================================================
/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v)
{
    //implement functionXXXX
    for(unsigned int i = 0; i < v.size(); i++)
    {
        v.at(i) = 'a' + i;
    }
    
    return;
}

//========================================================================================================================
/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition)
{
    //implement functionXXXX
    int q = 0;
    
    q = static_cast<int>(boardPosition);
    
    return q - 'a'; // ASCII 'a' = 97
}

//=========================================================================================================================
/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector <char> &gameBoard, int positionIndex) 
{
    // TODO: implement functionXXXX 
    
    if( (positionIndex >= 0) && (positionIndex <= 8) )
    {
        if(gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false; 
    }
    
    return false;  
}

//=========================================================================================================================
/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector <char> &gameBoard)
{

    // TODO: implement functionXXXX
    
    int positionIndex = 777;
    bool isValid = false;
    
    char boardPosition = ' ';
    
    do
    {
        cout << "Please choose a position: " << endl;
   
        cin >> boardPosition;
        
        //convert user entered char into an integer to check if valid
        positionIndex = convertPosition(boardPosition);
        
        isValid = validPlacement(gameBoard, positionIndex);
    }
    while(isValid == false);
    
    return positionIndex;
    

}

//========================================================================================================================
/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector <char> &gameBoard)
{
    // TODO: implement functionXXXX
    if(gameBoard.at(0) == gameBoard.at(1) && gameBoard.at(0) == gameBoard.at(2))
        {
            return true;
        }
    else if(gameBoard.at(3) == gameBoard.at(4) && gameBoard.at(3) == gameBoard.at(5))
        {
            return true;
        }
    else if(gameBoard.at(6) == gameBoard.at(7) && gameBoard.at(6) == gameBoard.at(8))
        {
            return true;
        }
    else if(gameBoard.at(0) == gameBoard.at(3) && gameBoard.at(0) == gameBoard.at(6))
        {
            return true;
        }
    else if(gameBoard.at(1) == gameBoard.at(4) && gameBoard.at(1) == gameBoard.at(7))
        {
            return true;
        }
    else if(gameBoard.at(2) == gameBoard.at(5) && gameBoard.at(2) == gameBoard.at(8))
        {
            return true;
        }
    else if(gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(2) == gameBoard.at(6))
        {
            return true;
        }
    else if(gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(0) == gameBoard.at(8))
        {
            return true;
        }        
    else
        {
        return false;
        }
return false;
}

//========================================================================================================================
/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector <char> &gameBoard)
{
    
    // TODO: implement functionXXXX
    int counter = 0;

    for(unsigned int i = 0; i < 9; i++)
    {
        if(gameBoard.at(i) == 'X')
        {
            counter++;
        }
        else if(gameBoard.at(i) == 'O')
        {
            counter++;
        }
        
               
    }
    
    if(counter == 9)
    {
       return true; 
    }
    else
    {
        return false;
    }
    
return false;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main()
{

    // Variables that you may find useful to utilize
    vector <char> gameBoard(9);
    int curPlay = 777;
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'
    
    
    ///Initialize board to empty stateXXXX
    initVector( gameBoard );

    ///Display empty boardXXXX
    drawBoard( gameBoard );

    /// TODO: Play until game is overXXXX
    while(gameWon(gameBoard) == false && boardFull(gameBoard) == false)
    {
        ///Get a playXXXX
        curPlay = getPlay(gameBoard);
        
        ///Set the play on the boardXXXX
        if( whosTurn ==  PLAYER1 )
        {
            gameBoard.at(curPlay) = 'X';
        }
        else
        {
            gameBoard.at(curPlay) = 'O';
        }

        /// TODO: Switch the turn to the other playerXXXX
      if(whosTurn == PLAYER1)
      {
          whosTurn = PLAYER2;
      }
      else
      {
          whosTurn = PLAYER1;
      }
    
        ///Output the updated boardXXXX
        drawBoard( gameBoard );
    }
    
    /// TODO: Determine winner and output appropriate message
    if(gameWon(gameBoard) == true)
    {
        if(whosTurn == PLAYER1)
        {
            cout << "PLAYER 2 WINS!" << endl;
        }
        else
        {
           cout << "PLAYER 1 WINS!" << endl; 
        }
    }
    else
    {
        cout << "No one wins" << endl;
    }


    return 0;
}

/*


Do not change the provided complete functions, or the function stub headers / return values. 

Currently, if the variables provided in main are commented out, the program will compile.
Complete the specifications for each function. As you develop the program, implement one function at a time, and test that function.
The provided comments provide hints as to what each function should do and when each should be called. Add variables where you see fit.

Implementation Strategies: 

The template has variables and two global constants for you to utilize.

The template has string literals for winning or tie game output in comments with provided file.

The template has comments to help you develop the necessary algorithm for 2 users playing tic-tac-toe on a computer. 
Use these comments along with the function descriptions below to help develop your program. One or more lines of your code should exist below each comment.
Remove the TODO part when you have completed that step.

DO NOT try to implement the entire game at once. 
Instead, develop and test one function at a time. Understand how to walk through your code by hand as well as executing it in unit tests.

The system will test your functions as you attempt to complete each. Use the feedback and walk through your code to fix problems.

Submit and achieve a full score on each function before implementing the main game algorithm.


*/
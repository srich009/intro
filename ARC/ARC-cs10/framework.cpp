// guess

#include <iostream>
#include <string>

using namespace std;

int main ()
{

    int userInput = 0;
    
    
    cout << "enter the excerise number for today." << endl;
    cin >> userInput;



    if (userInput == 1) // PASSWORD GUESS
    {
        string userPass;
        string gamePass = "Qwertyuiop";
        
        cout << "enter Password:" << endl;
        cin >> userPass;
        
        if (userPass == gamePass)
        {
            cout << "virus downloaded" << endl;
        }
        
        else
        {
            cout << "Error" << endl;
        }
    }

    if (userInput == 2) // CHAR DETECT
    {
        char userLetter = 'x';
        
        cout << "enter a single character" << endl;
        cin >> userLetter;
        
        if (userLetter >= 47 && userLetter <= 57)
        {
            cout << "number" << endl;
        }
        else if (userLetter < 48 || (userLetter <= 64 && userLetter >= 58) || (userLetter <= 96 && userLetter >= 91) || (userLetter <= 126 && userLetter >= 123))
        {
            cout << "other" << endl;
        }
        else if (userLetter >= 65 && userLetter <= 90)
        {
            cout << "uppercase" << endl;
        }
        else if (userLetter >= 97 && userLetter <= 122)
        {
            cout << "lowercase" << endl;
        }
    }

    if (userInput == 3) // COMPUTER FOOD
    {
        
        string compFood = "cheese";
        string userFood;
        string compDrink = "juice";
        string userDrink;
        string compSleep = "yes";
        string userSleep;
        
        cout << "hello." << endl << "what should i eat today?" << endl;
        cin >> userFood;
        
        if (userFood == compFood)
        {
            cout << "yeah thats good!" << endl;
        }
        else 
        {
            cout << "i'll starve today i guess" << endl;
        }
        
        cout << "what should i drink today?" << endl;
        cin >> userDrink;
        
        if (userDrink == compDrink)
        {
            cout << "yeah thats good!" << endl;
        }
        else 
        {
            cout << "i'll go thirsty today i guess" << endl;
        }
        
        cout << "should i sleep today?" << endl;
        cin >> userSleep;
        
        if (userSleep == compSleep)
        {
            cout << "yeah thats good!" << endl;
        }
        else 
        {
            cout << "i'll be awake" << endl;
        }
        
        
    }

    if (userInput == 4) // COOKIE MATH
    {
        
        int numKids = 0;
        int cookiesPerKid = 0;
        int numBatches = 0;
        const int COOKIES_PER_BATCH = 12;
        
        cout << "enter number of students" << endl;
        cin >> numKids;
        cout << "enter number of cookies per student" << endl;
        cin >> cookiesPerKid;
        
        numBatches = ((numKids * cookiesPerKid) / COOKIES_PER_BATCH);
        
        
        cout << "the number of batches made: ";
        cout << numBatches << endl;
    }

    if (userInput == 5)
    {
        int userBinary = 0;
        
    }





return 0;    
}

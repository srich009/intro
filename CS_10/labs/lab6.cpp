#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
   srand(3333); 
   
   // Declare all necessary variables
   int numRolls = 0;
   
   int theRoll = 0;
   
   int roll2 = 0;
   int roll3 = 0;
   int roll4 = 0;
   int roll5 = 0;
   int roll6 = 0;
   int roll7 = 0;
   int roll8 = 0;
   int roll9 = 0;
   int roll10 = 0;
   int roll11 = 0;
   int roll12 = 0;
   
   int scoreProb = 0;
   
   cout << "Enter number of times you want to roll a pair of dice: ";
   cin >> numRolls;
   cout << endl;
   
   // Calculate roll counts
   for (int i = 1; i <= numRolls; i++)
   {
    theRoll = ((rand() % 6 + 1) + (rand() % 6 + 1));
    
        if(theRoll == 2)
        {
            roll2++;
        }
        else if(theRoll == 3)
        {
            roll3++;
        }
        else if(theRoll == 4)
        {
            roll4++;
        }
        else if( theRoll == 5)
        {
            roll5++;
        }
        else if(theRoll == 6)
        {
            roll6++;
        }
        else if(theRoll == 7)
        {
            roll7++;
        }
        else if(theRoll == 8)
        {
            roll8++;
        }
        else if(theRoll == 9)
        {
            roll9++;
        }
        else if(theRoll == 10)
        {
            roll10++;
        }
        else if(theRoll == 11)
        {
            roll11++;
        }
        else
        {
            roll12++;
        }
    
   }
   
   cout << "# of times each score was rolled" << endl;
   // Output roll count table
    cout << "2: " << roll2 << endl;
    cout << "3: " << roll3 << endl;
    cout << "4: " << roll4 << endl;
    cout << "5: " << roll5 << endl;
    cout << "6: " << roll6 << endl;
    cout << "7: " << roll7 << endl;
    cout << "8: " << roll8 << endl;
    cout << "9: " << roll9 << endl;
    cout << "10: " << roll10 << endl;
    cout << "11: " << roll11 << endl;
    cout << "12: " << roll12 << endl;
    
    
   cout << endl;   
   cout << "Probability of rolling each possible score" << endl;
   // Output percentage table
    cout << "2: " << (roll2 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "3: " << (roll3 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "4: " << (roll4 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "5: " << (roll5 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "6: " << (roll6 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "7: " << (roll7 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "8: " << (roll8 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "9: " << (roll9 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "10: " << (roll10 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "11: " << (roll11 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
    cout << "12: " << (roll12 / (static_cast<double>(numRolls))) * 100 << "%" << endl;
   
   
   return 0;
}



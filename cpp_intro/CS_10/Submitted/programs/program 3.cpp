/*
Sean Richardson
cs 10 ch. 3.7
program 3 ranking values
*/

#include <iostream>
#include <string>

using namespace std;

int main ()
{
    
    string userName1;
    string userName2;
    string userName3;
    int userPoints1 =0;
    int userPoints2 =0;
    int userPoints3 =0;
    
    cout << "Enter player 1's name:" << endl;
    cin >> userName1;
    cout << "Enter player 1's yards gained:" << endl;
    cin >> userPoints1;
    
    cout << "Enter player 2's name:" << endl;
    cin >> userName2;
    cout << "Enter player 2's yards gained:" << endl;
    cin >> userPoints2;
    
    cout << "Enter player 3's name:" << endl;
    cin >> userName3;
    cout << "Enter player 3's yards gained:" << endl;
    cin >> userPoints3;
    cout << endl;
    
    cout << "Player 1 - " << userName1 << ": " << userPoints1 << endl;
    cout << "Player 2 - " << userName2 << ": " << userPoints2 << endl;
    cout << "Player 3 - " << userName3 << ": " << userPoints3 << endl;
    cout << endl;
    
        if (userPoints1 > userPoints2 && userPoints2 > userPoints3)
        {
            cout << "1. " << userName1 << ": " << userPoints1 << endl;
            cout << "2. " << userName2 << ": " << userPoints2 << endl;
            cout << "3. " << userName3 << ": " << userPoints3 << endl;
        }
        else if (userPoints1 > userPoints3 && userPoints3 > userPoints2)
        {
            cout << "1. " << userName1 << ": " << userPoints1 << endl;
            cout << "2. " << userName3 << ": " << userPoints3 << endl;
            cout << "3. " << userName2 << ": " << userPoints2 << endl;
        }
        else if (userPoints2 > userPoints1 && userPoints1 > userPoints3)
        {
            cout << "1. " << userName2 << ": " << userPoints2 << endl;
            cout << "2. " << userName1 << ": " << userPoints1 << endl;
            cout << "3. " << userName3 << ": " << userPoints3 << endl;
        }
        else if (userPoints2 > userPoints3 && userPoints3 > userPoints1)
        {
            cout << "1. " << userName2 << ": " << userPoints2 << endl;
            cout << "2. " << userName3 << ": " << userPoints3 << endl;
            cout << "3. " << userName1 << ": " << userPoints1 << endl;
        }
        else if (userPoints3 > userPoints2 && userPoints2 > userPoints1)
        {
            cout << "1. " << userName3 << ": " << userPoints3 << endl;
            cout << "2. " << userName2 << ": " << userPoints2 << endl;
            cout << "3. " << userName1 << ": " << userPoints1 << endl;
        }
        else if (userPoints3 > userPoints1 && userPoints1 > userPoints2)
        {
            cout << "1. " << userName3 << ": " << userPoints3 << endl;
            cout << "2. " << userName1 << ": " << userPoints1 << endl;
            cout << "3. " << userName2 << ": " << userPoints2 << endl; 
        }




return 0;
}
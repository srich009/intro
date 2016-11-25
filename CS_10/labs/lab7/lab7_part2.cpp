// lab 7 part 2 coin toss%

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//FIXME add return of percent heads 
double percentHeads(int val1)
{
    int headCount = 0;
    
    for(int i = 1; i <= val1; ++i)
    {
        if(rand() % 2 == 0)
        {
           headCount++; 
        }
    }
    
    return static_cast<double>(headCount)/val1*100;
}


int main()
{
    srand(4444);
        
    int timesToss = 0;
    double amtHead = 0.0;
    
    cout << "Enter the number of times you want to toss the coin: ";
    cin >> timesToss;
    cout << endl;
    
    amtHead = percentHeads(timesToss);
    cout << "Heads came up " << amtHead << "% of the time.";
    cout << endl;
    
    
    
return 0;    
}
    
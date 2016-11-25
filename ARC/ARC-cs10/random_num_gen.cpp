#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
 
 srand(time(0));
 
 int scoreVal = 0;
 int numTimes = 0;
 
 while (scoreVal <= 1000)
 {
 scoreVal= scoreVal + rand() % 4 + 5;
  
  numTimes++;
  
 }

 cout << numTimes << endl;
 
 return 0;   
}
#include "Jug.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
   
   string solution;
   Jug head(3, 5, 4, 1, 2, 3, 4, 5, 6); // ex from zybook
   //Jug head(3, 5, 4, 1, 1, 1, 1, 1, 2); // ex2
   head.solve(solution);
   cout << solution << endl;
   
   return 0;
}
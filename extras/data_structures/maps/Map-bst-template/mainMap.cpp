#include <iostream>
#include "map.h"

using namespace std;

int main()
{
   
   //keys dont change
   
   Map<char, int> mp;
   
   mp['a'] = 1;
   mp['b'] = 2;
   mp['c'] = 3;
   
   // map<char, char> b;
   // b['('] = ')';
   // b['{'] = '}';
   
   // if(b[q.front()] == curr_char)
   // {
   //    asdfasdfasdf;
   // }
   
   cout << mp['a'] << endl;
   
   cout << mp.count('c') << endl;
   cout << mp.count('d') << endl;
   
return 0;
}
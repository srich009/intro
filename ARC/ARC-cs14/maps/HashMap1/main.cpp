# include "HashMap.h"

using namespace std;

int main()
{
   HashMap woot(7);
   
   woot["test"] = 99;
   
   cout << woot["test"] << endl;
   
   string s;
   for(int i = 0; i < 5; i++)
   {
      cin >> s;
      cout << woot[s] << endl;
      int x;
      cin >> x;
      woot[s] = x;
   }
   
   
   
return 0;
}
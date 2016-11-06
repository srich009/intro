//main == test harness for prgm 7 
//g++ IntList.cpp SortedSet.cpp main.cpp -Wall -Werror -o a.out

#include "IntList.h"
#include "SortedSet.h"

#include <iostream>

using namespace std;

int main()
{
   ///TEST BLOCK 1 FOR: DEFAULT CONST, BOTH OF COPY CONSTS, && BOOL IN()
   /*
   IntList list1;
   SortedSet set1; // test default
   
   cout << "is_empty?" << endl;
   cout << "ll: " << list1.empty() << endl;
   cout << "ss: " << set1.empty() << endl;

   for(int i = 1; i <= 10; i++)
   {
      int val = 0;
      cout << "cin a val >>";
      cin >> val;
      list1.push_back(val);
   }
   
   cout << endl << "list now: " << endl;
   list1.display(); cout << endl;
   
   cout << "make new ss = ll" << endl;
   SortedSet set2 = list1;
   
   cout << "SS2: " << endl;
   set2.display(); cout << endl;
   
   cout << "make new ss = ss2" << endl;
   SortedSet set3 = set2;
   cout << "SS3: " << endl;
   set3.display(); cout << endl;
   
   int nummie;
   cout << "search for num is in set?" << endl;
   cin >> nummie;
   cout << "bool is in: " << set3.in(nummie) << endl;
   */
   
   ///TEST BLOCK FOR: ADD, AND OTHER MUTATORS THAT CALL ADD
   /*
   //estsblish test bounds for add function
   IntList ppp;
   ppp.push_front(1); // low
   ppp.push_front(5); // mid
   ppp.push_front(9); // high
   
   SortedSet test = ppp;
   int num;
   
   cin >> num;
   test.add(num);
   
   test.display(); 
   cout << endl;
   
   cin >> num;
   test.push_front(num);
   
   test.display(); 
   cout << endl;
   
      cin >> num;
   test.push_back(num);
   
   test.display(); 
   cout << endl;
   
      cin >> num;
   test.insert_ordered(num);
   
   test.display(); 
   cout << endl;
   */
   
   ///TEST BLOCK FOR OPERATORS
   
   IntList zzz;
   zzz.push_front(1); // low
   zzz.push_front(5); // mid
   zzz.push_front(9); // high
   zzz.push_front(7);
    SortedSet S1 = zzz;
   
   IntList xxx;
   xxx.push_front(0);
   xxx.push_front(3);
   xxx.push_front(5);
   xxx.push_front(7);
   SortedSet S2 = xxx;
   
   cout << "s1: ";
   S1.display();
   cout << endl;
   cout << "s2: ";
   S2.display();
   cout << endl;
   
   //here substitue signs and compare before && after
   //  use:  | , |= , & , &=
   
   SortedSet S3;
   S3 = S1 &= S2;
   
   cout << "s3: ";
  S3.display();
   cout << endl;
   
   cout << "s1: "; 
     S1.display();
   cout << endl;
   cout << "s2: ";
   S2.display();
   cout << endl;
   
   
   

return 0;
}
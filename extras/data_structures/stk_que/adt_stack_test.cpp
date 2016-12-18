#include "adt.h"

#include <iostream>

int main()
{
   
///////////////////////////////////////////////////////////////////////////////

   cout << "start"  << endl;
   
   Lstack stk;
   
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   ////////////////////////////////////////////////////////
   cout << "push 1" << endl;
   stk.push(1);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "push 2" << endl;
   stk.push(2);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "push 3" << endl;
   stk.push(3);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   ////////////////////////////////////////////////////
   cout << "pop" << endl;
   stk.pop();
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "pop" << endl;
   stk.pop();
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "pop" << endl;
   stk.pop();
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   //////////////////////////////////////////////////
   
   cout << "pop" << endl;
   stk.pop();
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "push 1" << endl;
   stk.push(1);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "push 2" << endl;
   stk.push(2);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "pop" << endl;
   stk.pop();
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }  
   cout << "push 2" << endl;
   stk.push(2);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "push 3" << endl;
   stk.push(3);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }   
   cout << "push 4" << endl;
   stk.push(4);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "push 5" << endl;
   stk.push(5);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "push 6" << endl;
   stk.push(6);
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }
   cout << "clear" << endl;
   stk.clear();
   cout << "empty: " << stk.empty() << endl;
   cout << "size : " << stk.size() << endl;
   if(stk.peek())
   {
      cout << "data : " << stk.peek()->data << endl;
   }

//////////////////////////////////////////////////////////////////////////////////  

   cout << endl << "start"  << endl;
   
   Astack stk1;
   
   cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   ////////////////////////////////////////////////////////
   cout << "push 1" << endl;
   stk1.push(1);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 2" << endl;
   stk1.push(2);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 3" << endl;
   stk1.push(3);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   ////////////////////////////////////////////////////
   cout << "pop" << endl;
   stk1.pop();
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "pop" << endl;
   stk1.pop();
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "pop" << endl;
   stk1.pop();
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   //////////////////////////////////////////////////
   
   cout << "pop" << endl;
   stk1.pop();
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 1" << endl;
   stk1.push(1);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 2" << endl;
   stk1.push(2);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "pop" << endl;
   stk1.pop();
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 2" << endl;
   stk1.push(2);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 3" << endl;
   stk1.push(3);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 4" << endl;
   stk1.push(4);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 5" << endl;
   stk1.push(5);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "push 6" << endl;
   stk1.push(6);
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }
   cout << "clear" << endl;
   stk1.clear();
      cout << "empty: " << stk1.empty() << endl;
   cout << "size : " << stk1.size() << endl;
   if(stk1.peek())
   {
      cout << "data : " << *(stk1.peek()) << endl;
   }

return 0;
}
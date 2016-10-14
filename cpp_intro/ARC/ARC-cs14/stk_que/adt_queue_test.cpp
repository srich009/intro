#include "adt.h"

#include <iostream>

int main()
{
   
///////////////////////////////////////////////////////////////////////////////

   cout << "start"  << endl;
   
   Lqueue que;
   
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   ////////////////////////////////////////////////////////
   cout << "enqueue 1" << endl;
   que.enqueue(1);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "enqueue 2" << endl;
   que.enqueue(2);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "enqueue 3" << endl;
   que.enqueue(3);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   ////////////////////////////////////////////////////
   cout << "dequeue" << endl;
   que.dequeue();
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "dequeue" << endl;
   que.dequeue();
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "dequeue" << endl;
   que.dequeue();
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   //////////////////////////////////////////////////
   
   cout << "dequeue" << endl;
   que.dequeue();
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "enqueue 1" << endl;
   que.enqueue(1);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "enqueue 2" << endl;
   que.enqueue(2);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "dequeue" << endl;
   que.dequeue();
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }  
   cout << "enqueue 2" << endl;
   que.enqueue(2);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "enqueue 3" << endl;
   que.enqueue(3);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }   
   cout << "enqueue 4" << endl;
   que.enqueue(4);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "enqueue 5" << endl;
   que.enqueue(5);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "enqueue 6" << endl;
   que.enqueue(6);
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }
   cout << "clear" << endl;
   que.clear();
   cout << "empty: " << que.empty() << endl;
   cout << "size : " << que.size() << endl;
   if(que.getFront())
   {
      cout << "data : " << que.getFront()->data << endl;
   }

//////////////////////////////////////////////////////////////////////////////////  


return 0;
}
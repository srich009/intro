#ifndef __ADT_H__
#define __ADT_H__

#include <iostream>

using namespace std;
 
//NODE BASED IMPLEMENTATION
//-----------------------------------------------
struct Node
{
   Node* next;
   int data;
   Node(int x) : next(0), data(x) {}
};

class Lstack
{
   private:
      Node* top;
      unsigned sz;
   public:
      Lstack() : top(0), sz(0) {}
      ~Lstack();
      bool empty() const;
      unsigned size() const;
      Node* peek();
      void push(int x);
      void pop();
      void clear();
};

class Lqueue
{
   private:
      Node* front;
      Node* back;
      unsigned sz;
      
   public:
      Lqueue() : front(0), back(0), sz(0) {};
      ~Lqueue();
      bool empty() const;
      unsigned size() const;
      Node* getFront();
      void enqueue(int x);
      void dequeue();
      void clear();    
};
//-----------------------------------------------


//ARRAY BASED IMPLEMENTATION
//-------------------------------------------------
class Astack 
{
   private:
      int* arr;   // array declared as sz of 100
      int* top;
      unsigned sz; 
   public:
      Astack();
      ~Astack();
      bool empty() const;
      unsigned size() const;
      int* peek();
      void push(int x);
      void pop();
      void clear();
};
//-----------------------------------------------------


#endif //__ADT_H__


/*


stack - LIFO 

queue - FIFO

all operations O(1)
   -exception clear() - O(n)

*/
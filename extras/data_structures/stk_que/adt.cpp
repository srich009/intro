#include "adt.h"

#include <iostream>

using namespace std;

//NODE BASED IMPLEMENTATION
//========================================================
//========================================================
Lstack::~Lstack()
{
   if(top)
   {
      clear();
   }
}
//----------------------------------------

bool Lstack::empty() const
{
   return top == 0;
}
//-----------------------------------------

unsigned Lstack::size() const
{
   return sz;
}
//-----------------------------------------

Node* Lstack::peek()
{
   if(top)
   {
      return top;
   }
   else
   {
      cout << "ERR: Empty stack" << endl;
      return 0;
   }
}
//-----------------------------------------

void Lstack::push(int x)
{
   Node* tp = new Node(x);
   tp->next = top;
   top = tp;
   sz++;
}

void Lstack::pop()
{
   if(!top) return;
   Node* del = top;
   top = top->next;
   delete del;
   del = 0;
   sz--;
}
//-----------------------------------------

void Lstack::clear()
{
   while(top)
   {
      this->pop();
   }
   top = 0;
   sz = 0;
}
//========================================================
//========================================================

//========================================================
//========================================================

Lqueue::~Lqueue()
{
   if(front)
   {
      clear();
   }
}
//-----------------------------

bool Lqueue::empty() const
{
   return front == 0;
}
//-----------------------------

unsigned Lqueue::size() const
{
   return sz;
}
//-----------------------------

Node* Lqueue::getFront()
{
   if(front)
   {
      return front;
   }
   else 
   {
      cout << "ERR: Empty Queue" << endl;
      return 0;
   }
}
//-----------------------------

void Lqueue::enqueue(int x)
{
   Node* tp = new Node(x);
   if(front == 0)
   {
      front = tp;
      back = tp;
   }
   else
   {
      back->next = tp;
      back = tp;
   }
   sz++;
}
//-----------------------------

void Lqueue::dequeue()
{
   if(!front) return;
   else if(front == back)
   {
      delete front;
      front = 0;
      back = 0;
      sz--;
      return;
   }
   
   Node* del = front;
   front = front->next;
   delete del;
   del = 0;
   sz--;
   return;   
   
}
//-----------------------------

void Lqueue::clear()
{
   while(front)
   {
      dequeue();
   }
   front = 0;
   sz = 0;
}
      
//========================================================
//========================================================


//ARRAY BASED IMPLEMENTATION
//========================================================
//========================================================
Astack::Astack()
{
   sz = 0;
   arr = new int[100];
   top = arr;
}
//-------------------------------

Astack::~Astack()
{
   if(sz != 0)
   {
      clear();
   }
}
//-------------------------------

bool Astack::empty() const // probably could be better
{
   return sz == 0;
}
//-------------------------------

unsigned Astack::size() const
{
   return sz;
}
//-------------------------------

int* Astack::peek() // ?? when is empty...??
{
   return top;
}
//-------------------------------

void Astack::push(int x)
{
   top += 1;
   *top = x;
   sz++;
}
//-------------------------------

void Astack::pop() // probably could do better
{
   if(sz == 0) return;
   top -= 1;
   sz--;
}
//-------------------------------

void Astack::clear()
{
   while(sz != 0)
   {
      pop();
   }
}
//========================================================
//========================================================
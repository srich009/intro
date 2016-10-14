#include "Heap.h"

#include <iostream>
#include <algorithm>

using namespace std;

/*
  PrintJob* arr[MAX_HEAP_SIZE];      // Notice this is an array of PrintJob pointers
  int numItems;  //current number of items in heap
*/


  /*Initializes an empty heap.*/
  Heap::Heap()
      : numItems(0)
  {}

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void Heap::enqueue ( PrintJob* j1)
  {
    if(numItems < MAX_HEAP_SIZE)
	 {
  		if(numItems == 0)
  		{
  			arr[numItems] = j1;
  			++numItems;
  		}
  		else
  		{
         int x = numItems;
         
         while (x > 0 && (arr[(x-1)/2]->getPriority() < j1->getPriority()) )
         {
            arr[x] = arr[(x-1)/2];
            x = (x-1)/2;
         }
         arr[x] = j1;
         ++numItems;
	  }
  }
}

  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
  void Heap::dequeue ( )
  {
     if(numItems == 0)
     {
        return;
     }
     else
     {
         swap(arr[0], arr[numItems-1]);
         
         //trickleDown( arr[numItems-1]->getPriority());
         trickleDown(0);
     }
  }

  /*Returns the node with highest priority.*/
  PrintJob* Heap::highest ( )
  {
     return arr[0];
  }

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
  void Heap::print ( )
  {
     PrintJob* pj = arr[0];
     
     cout << "Priority: " <<  pj->getPriority() << ", " << "Job Number: " << pj->getJobNumber();
      cout << ", " << "Number of Pages: " << pj->getPages() << endl;
  }

//private:
  /*This function is called by dequeue function
  to move the new root down the heap to the 
  appropriare location.*/
  void Heap::trickleDown(int i)
  {     
      PrintJob* r = arr[2*i + 2];
      PrintJob* l = arr[2*i + 1];
      PrintJob* lg;
      
      if(r == 0 && l == 0)
      {
        return;
      }
      else if(r == 0 && l != 0)
      {
        lg = l;
        
      }
      else if(r != 0 && l == 0)
      {
        lg = r;
        
      }
      else if(r->getPriority() > l->getPriority())
      {
        lg = r;
      }
      else
      {
        lg = l;
      }
    
      if(arr[i]->getPriority() < lg->getPriority())
      {
        swap(arr[i] , lg);
        
      }
      
      if(lg == l)
      {
         trickleDown(2*i + 1);
      }
      else
         trickleDown(2*i + 2);
  }
  
//    void Heap::trickleUp(int)
//  {
//  }
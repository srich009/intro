#include "Heap.h"

Heap::Heap()
{
	numItems = 0;
}

void Heap::enqueue( PrintJob* j1)
{
	if(numItems < MAX_HEAP_SIZE)
	{
		if(!numItems)
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

void Heap::dequeue ( )
{
	if(!numItems)
	{
		return;
	}
	
	if(arr[1] && arr[2] && ((arr[1]->getPriority() < arr[numItems - 1]->getPriority()) && (arr[2]->getPriority() < arr[numItems - 1]->getPriority())))
	{
		//cout << "entered second if in dequeue" << endl;
		arr[0] = arr[numItems-1];
		--numItems;
		
	}
	else
	{
		//cout << "entered else in dequeue" << endl; 
		trickleDown(0);
		--numItems;
	}
	
	
}

PrintJob* Heap::highest ( )
{
	//condition for empty?
	if(!numItems)
	{
		return 0;
	}
	return arr[0];
}


 /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
void Heap::print ( )
{
	cout << "Priority: " << arr[0]->getPriority()
	<< ", Job Number: " << arr[0]->getJobNumber() 
	<< ", Number of Pages: " << arr[0]->getPages()
	<< endl; 
}

void Heap::trickleDown(int num)
{
	 PrintJob* r = arr[2*num + 2];
      PrintJob* l = arr[2*num + 1];
      PrintJob* lg;
      
      if(!r && !l)
      {
        return;
      }
      else if(!r && l)
      {
        lg = l;
        
      }
      else if(r && l)
      {
		   if(r->getPriority() > l->getPriority())
		   {
		     lg = r;
		   }
		   else
		   {
		     lg = l;
		   }
      }
//      else if(r != 0 && l == 0)
//      {
//        lg = r;
//        
//      }
//      else if(r->getPriority() > l->getPriority())
//      {
//        lg = r;
//      }
//      else
//      {
//        lg = l;
//      }
    
      if(arr[num]->getPriority() < lg->getPriority())
      {
        //swap(arr[num] , lg);
        //arr[num] = lg;
        arr[num]->setPriority(lg->getPriority());
        arr[num]->setJobNumber(lg->getJobNumber());
        arr[num]->setPages(lg->getPages());
        
        
      }
      
      if(lg == l && r)//largest is left and right exists
      {
         trickleDown(2*num + 1);
      }
      else if(lg == r)
      {
         trickleDown(2*num + 2);
      }
  
}

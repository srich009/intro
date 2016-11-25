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
			arr[numItems ] = j1;
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
	
	if(numItems > 2 && arr[1]->getPriority() < arr[numItems - 1]->getPriority() && arr[2]->getPriority() < arr[numItems - 1]->getPriority())
	{//enters if order will be kept after first swap (no trickledown)
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
//intital attempt
//	  PrintJob* l = arr[2*num + 1];
//	  if((2*num + 1) < numItems && (2*num + 2) < numItems)
//	  {
//	     	PrintJob* r = arr[2*num + 2];
//        	//PrintJob* l = arr[2*num + 1];
//        	PrintJob* lg;
//      
//		   if(r->getPriority() > l->getPriority())
//		   {
//		     lg = r;
//			  if(arr[num]->getPriority() < lg->getPriority())
//			  {
//				  //swap(arr[num] , lg);
//				  //arr[num] = lg;
//				  arr[num]->setPriority(lg->getPriority());
//				  arr[num]->setJobNumber(lg->getJobNumber());
//				  arr[num]->setPages(lg->getPages());
//				  //lg = 0;
//				  
//				  
//			  }
//		     trickleDown(2*num + 2);
//		   }
//		   else
//		   {
//		      lg = l;
//				if(arr[num]->getPriority() < lg->getPriority())
//				{
//				  //swap(arr[num] , lg);
//				  //arr[num] = lg;
//				  arr[num]->setPriority(lg->getPriority());
//				  arr[num]->setJobNumber(lg->getJobNumber());
//				  arr[num]->setPages(lg->getPages());
//				  //lg = 0;
//				  
//				  
//				}
//				trickleDown(2*num + 2);
//				
//			}
//    
//      }
//      else if(l->getPriority() < num)
//      {

//        //PrintJob* l = arr[2*num + 1];
//        PrintJob* lg;
//        lg = l;
//        arr[num]->setPriority(lg->getPriority());
//        arr[num]->setJobNumber(lg->getJobNumber());
//        arr[num]->setPages(lg->getPages());
//      	
//      }
//	  return;
//initial attempt
    
    if (((2 * num + 1) < numItems) && ((2 * num + 2) < numItems)) 
    {// enters if both children exist (1)
        
        
        if (arr[2 * num + 1]->getPriority() > arr[2 * num + 2]->getPriority()) 
        {//enters if left child is greater than the right(2)
            arr[num] = arr[2 * num + 1];
            trickleDown(2 * num + 1);
            
        }//(2)
        else
        {//enters if right child is greater than the left (3)
            arr[num] = arr[2 * num + 2];
            trickleDown(2 * num + 2);
        }//(3)
    }//(1)
    
    else if (((2 * num + 1) < numItems)) {//enters if only left exists
        arr[num] = arr[2 * num + 1];
    }
    return;
      
  
}

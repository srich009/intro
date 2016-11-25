//PSEUDOCODE


// queue ADT operator uses FIFO
//first in first out

//limited sub set of operations
//enqueue: insert at back
//dequeue: remove from front
//peek: see front value w?o removing it
//getSize
//isEmpty:  if(size == 0 || rear == front)



//ARRAY BASED Example
//-front
//-back
//-size

void enqueue(const Object &o)
{
    if(front == (rear + 1) % size)
    {
        error-queue full;
    }
    else
        Q[rear] = o;
        rear = () % size;
}

const Object& getFront() const
{
    if(isEmpty)
    {
        error - queue empty
    }
    else
    {
        return Q[front];
    } 
}

void dequeue(Object &o)
{
    if(isEmpty())
    {
        error- queue empty
    }
    else
    {
        front = (front + 1) % size;
    }
}

//--------------------------------------

//linked list example

//head == front
//tail == rear

//enqueue == push_back()
//dequeue == pop_front()

const object& getFront() const
{
    if(!front)
    {
        error - queue empty
    }
    else
    return front->data
}

void dequeue(Object &o)
{
    if(!isEmpty())
    {
        Node* temp = front;
        front = front->next;
        
        
        if(front == 0) // going down to an empty list
        {
            rear = 0
        }
        
        delete temp;
        numItems--;
    }
    else 
    error- empty queue
}

void enqueue(const Object &o)
{
    Node* newNode = new Node(o);
    if(isEmpty())
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        ++numItems;
    }
}
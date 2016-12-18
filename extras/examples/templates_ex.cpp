//PSUEDOCODE for templatized list

template <class T>
void List<T>::pushBack(const T& input)
{
    Node<T>* ptr = new Node<T>;
    ptr->item = input;
    ptr->next = 0;
    
    if(!head)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        tail->next = ptr;
        tail = ptr;
    }
    
    return;
}
//==========================================

template<class T>
void List<T>::Remove(const T& val)  // remove first value
{
    if(!head) return;
    if(head->item == val)
    {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
        if(!head)
        {
            tail = 0;
        }
        return;
    }
    
    Node<T>* prev = head;
    Node<T>* curr == prev->next;
    
    for(; curr != 0; curr = curr->next, prev=prev->next)
    {
        if(curr->item == val)
        {
            pev->next = curr->next
            delete curr;
            if(curr == tail)
            {
                tail = prev;
            }
            return;
        }
        
    }
    
} /// needs an is equal operator or wont work
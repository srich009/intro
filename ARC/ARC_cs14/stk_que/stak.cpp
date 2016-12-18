//PSEUDOCODE

// Stack adt LIFO
// last in first out

//push == push_front
//pop == pop_front
//top == return top elemenmt w/o removing it
//get_size
//isEmpty

//array based stack psudocode examples


void pop()
{
    if(top != -1)
    {
        top--;
    }
    else
    {
        throw emptyStackException;
    }
}

objectType getTop() const
{
    if(top == -1)
    {
        throw emptyStackException;
    }
    else
    {
        return S[top];   
    }
}
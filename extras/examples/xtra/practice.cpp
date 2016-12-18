#include <iostream>
#include <string>

using namespace std;


int find(char str[], char ch)
{
    if(str[0] == 0) // if NULL
    {
        return -1;
    }
    
    if(str[0] == ch) // if == to
    {
        return 0;
    }
    
    
    return 1 + find(str + 1, ch);
    
    //dont work if ch not in str
}


/*

//helper function -- not done
int find(char arr[], char ch, unsigned sz)
{
    for(unsigned i = 0; i < sz; ++i)
    {
        if()
        {
            return i;
        }
    }
    else 
    {
        
    }
}
*/

int main()
{
    
    /*
    //tests find function for strings and char
    char str1[] = "mango";
    char ch1 = 'n';
    cout << find(str1, ch1) << endl;
    */
    
    
    int test[] = {5, 3, 4, 1, 2, 1, 7};
    int size = 7;
    
    string s;
    char cp[]= "Hello";
    s = cp;
    
    cout << s << endl;
    
    return 0;
}
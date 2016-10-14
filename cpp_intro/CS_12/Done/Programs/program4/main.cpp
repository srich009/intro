//test
#include "IntVector.h"

#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    cout << "FIXME" << endl << endl;
    
    
     //IntVector v1; //empty
    // IntVector v2(5, 7); // size, value
    // IntVector v3(1,1);
     IntVector v4(160,1);
     //IntVector v5(20,3); 
    //IntVector v6(1, 0);
    //IntVector v7(6,6);
    //IntVector v8(5, 6);
    
     cout << "Vector initial" << endl;
     cout << "SZ: " << v4.size() << endl;
     cout << "CAP: " << v4.capacity() << endl;
     if(v4.size() > 0)
     {
    for(unsigned int i = 0; i < v4.size(); i++)
    {
        cout << v4.at(i) << ", ";   
    }
    cout << endl;
     }
    v4.resize(15);
    
    cout << "Vector resized" << endl;
    cout << "SZ: " << v4.size() << endl;
    cout << "CAP: " << v4.capacity() << endl;
     for(unsigned int i = 0; i < v4.size(); i++)
    {
        cout << v4.at(i) << ", ";   
    }
    cout << endl;
     
    
    
    //Assign
    /*
    cout << "Vector initial" << endl;
    for(unsigned int i = 0; i < v7.size(); i++)
    {
        cout << v7.at(i) << ", ";   
    }
    cout << endl;
    
    v7.assign(10, 8);
    
    cout << "Vector assign(10, 8)" << endl;
    for(unsigned int i = 0; i < v7.size(); i++)
    {
        cout << v7.at(i) << ", ";   
    }
    cout << endl;
    */
    
    
    
    //insert
    /*
    for(unsigned int i = 1; i < 10; i++)
    {
        v6.push_back(i);
    }
    
    cout << "v6 before insert: " << endl;
    for(unsigned i = 0; i < v6.size(); i++)
    {
        cout << v6.at(i) << ", ";
    }
    cout << endl;
    v6.insert(2, 1);
    cout << "v6 after: "  << endl;
    for(unsigned i = 0; i < v6.size(); i++)
    {
        cout << v6.at(i) << ", ";
    }
    cout << endl;
    
    cout << "should see fail for out of range next if insert works" << endl;
    v6.insert(2222, 2323);
    */

    //reserve
    /*
    cout << "empty v5 cap: " << v5.capacity() << endl;
    v5.reserve(20);
    cout << "v5 cap: " << v5.capacity() << endl;    
    
    cout << "v4 cap: " << v4.capacity() << endl;
    for(unsigned i = 0; i < v4.size(); i++)
    {
        cout << v4.at(i) << ", ";
    }
    cout << endl;
    
    v4.reserve(30);
    cout << "v4 reserve cap to 30 check: " << v4.capacity() << endl;
    for(unsigned i = 0; i < v4.size(); i++)
    {
        cout << v4.at(i) << ", ";
    }
    cout << endl;
    */
    //--------------------------------------------------------------------
    
    
    //push back
    /*
    cout << "Empty Vector Test:" << endl;
    cout << v1.empty() << endl;
    cout << "Empty Vector pushback 1:" << endl;
    v1.push_back(1);
    cout << v1.at(0);
    cout << endl;
    cout << "Empty Vector pushback 2:" << endl;
    v1.push_back(2);
    for(unsigned i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << ", ";
    }
     cout << endl;
    */
    //----------------------------------------------------
    
    //Pop back, clear
    /*
    cout << "Vector2 (size = 5, value = 7) test:" << endl;
        for(unsigned i = 0; i < v2.size(); i++)
        {
            cout << v2.at(i) << ", ";
        }
    cout << endl;
    
    cout << "Vector2 pop_back test:" << endl;
    v2.pop_back();
        for(unsigned i = 0; i < v2.size(); i++)
        {
            cout << v2.at(i) << ", ";
        }
    cout << endl;
    
    cout << "Vector2 clear test:" << endl;
    v2.clear();

        if(v2.size() == 0)
        {
            cout << "clear function works" << endl;
        }
        else
        {
            for(unsigned i = 0; i < v2.size(); i++)
            {
                cout << v2.at(i) << ", ";
            }
        }
    cout << endl;
    */
    //-----------------------------------------------------------
    
    //erase
    /*
    cout << "Vector 3 erase test:" << endl;
    cout << "Before: ";
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    
    for(unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << ", ";
    }
    cout << endl;
    
    cout << "After erase 2nd element " << endl;
    v3.erase(1);
    
        for(unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << ", ";
    }
    cout << endl;
    
    cout << "After erase new 3rd element " << endl;
    v3.erase(2);
    
        for(unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << ", ";
    }
    cout << endl;
    
    cout << "After erase new 1st element " << endl;
    v3.erase(0);
    
        for(unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << ", ";
    }
    cout << endl;
    
    cout << "After try erase past index should fail " << endl;
    v3.erase(2);
    
    for(unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << ", ";
    }
    cout << endl;
    */
    //--------------------------------------------------------------
    
    //cout << "FIXME" << endl;
    
    
return 0;    
}
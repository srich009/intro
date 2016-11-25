// wordladder implementation

#include "WordLadder.h"

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <fstream>
#include <cstdlib>

using namespace std;

//private:
    //list<string> dict;
    
    //PRIVATE HELPER FUNCTION
    bool WordLadder::offByOne(const string& s, const string& x)
    {
        int k = 0; // increment counter if match letter
        
        for(unsigned int i = 0; i < s.size(); i++)
        {
           if(s.at(i) == x.at(i))
           {
               k++;
           }
        }
        
        return k == 4; // true iff off by one, k == 4
    }
//================================================================

//public:
    WordLadder::WordLadder(const string& fName)
    {
        ifstream InFS;
        string filler;
        
        InFS.open( fName.c_str() );
        if(!InFS.is_open())
        {
            cout << "ERROR: can not open dictionary file" << endl; // testing here (remove later)
            InFS.close();
            return;
        }
        
        //loop until EOF
        while(InFS >> filler)
        {
            if(filler.size() != 5) // check if == 5 letters befor push into list
            {   
                cout << "ERROR: encountered a word of length != 5" << endl;
                InFS.close();
                return;
            }
            else
            {
                dict.push_back(filler);
            }
        }
        
        InFS.close();
    }
    /* Passes in the name of a file that contains a dictionary of 5-letter words.
       Fills the list (dict) with the words within this file. 
       If the file does not open for any reason or if any word within the file
       does not have exactly 5 characters, this function should output an
       error message and return.
    */
    
//=================================================================================================    
    

    void WordLadder::outputLadder(const string& start, const string& end, const string& outputFile)
    {
        bool startInList = false;
        bool endInList = false;
        
        // check list for start word
        for(list<string>::iterator it = dict.begin(); it != dict.end(); it++)
        {
            if(*it == start)
            {
                startInList = true;
                break;
            }
        }
        // check list for end word
        for(list<string>::iterator it = dict.begin(); it != dict.end(); it++)
        {
            if(*it == end)
            {
               endInList = true;
               break;
            }
        }
        
        if(startInList == false || endInList == false)
        {
            cout << "ERROR: at least 1 word is not in dictionary" << endl;
            return;
        }
        else if(start == end)
        {
            ofstream OutFS;
            OutFS.open(outputFile.c_str());
            
            if(!OutFS.is_open())
            {
                cout << "ERROR: can not open output file" << endl;
                return;
            }
            else
            {
                OutFS << start;
                OutFS.close();
            }
            return;
        }
        else
        {
            // put algorithm with call to helper function offByOne()...
            stack<string> strStak;
            strStak.push(start);
            
            queue< stack<string> > queStak;
            queStak.push(strStak);
            
            dict.remove(start); // remove start word from dictionary
            
            while( !queStak.empty() )
            {
                stack<string> firstQ = queStak.front(); // first stack in queue
                            
                for(list<string>::iterator it = dict.begin(); it != dict.end(); it++) //go through list
                {
                                      
                    if( offByOne(firstQ.top(), *it) ) //find words off by one with a helper function
                    {                                                      
                        stack<string> secQ = firstQ;
                        secQ.push(*it);  
                                                
                        if(secQ.top() == end) // found word ladder
                        {
                            //output the word ladder to file
                            ofstream OutFS;
                            OutFS.open(outputFile.c_str());
                            
                            if(!OutFS.is_open())
                            {
                                cout << "ERROR: can not open output file" << endl;
                                return;
                            }
                            else
                            {                               
                                stack<string> outQ; // have to reverse stack for correct order
                                
                                while(!secQ.empty())
                                {
                                    outQ.push( secQ.top() );
                                    secQ.pop();
                                }
                                while(outQ.size() > 1)
                                {
                                    OutFS << outQ.top() << ' ';
                                    outQ.pop();
                                }
                                OutFS << outQ.top(); //last part no space
                                outQ.pop();
                                
                                OutFS.close();
                                return; 
                            }
                             
                        }
                        else
                        {          
                            it = dict.erase(it); //remove word from list && fix iter
                            it--;
                            queStak.push(secQ); // put stack into queue
                        }
                    }
    
                }//End of FOR
                
                queStak.pop(); // dequeue front stack
                
            } //end of while
            
            if( queStak.empty() ) // if no ladder found
            {
                ofstream OutFS;
                OutFS.open(outputFile.c_str());
                
                if(!OutFS.is_open())
                {
                    cout << "ERROR: can not open output file" << endl;
                    return;
                }
                else
                {
                    OutFS << "No Word Ladder Found!!";
                    OutFS.close();
                }
                return; 
            }           
        }
        
        return;
    }
    /* Passes in two 5-letter words and the name of an output file.
       Outputs to this file a word ladder that starts from the first word passed in
       and ends with the second word passed in.
       If either word passed in does not exist in the dictionary (dict),
       this function should output an error message and return.
       Otherwise, this function outputs to the file the word ladder it finds or outputs
       to the file, the message, "No Word Ladder Found!!"
    */
    

 //------------------------------------------------------------------------
 //------------------------------------------------------------------------

/*

ALGORITHM

-create a Stack containing just the first word in the ladder
-enqueue this Stack on to a Queue of Stacks
-while this Queue of Stacks is not empty
    -get the word on top of the front Stack of this Queue
    -for each word in the dictionary
        -if the word is off by just one letter from the top word
            -create a new Stack that is a copy of the front Stack and push on this off-by-one word found
            -if this off-by-one word is the end word of the ladder, this new Stack contains the entire word ladder. You are done!
            -otherwise, enqueue this new Stack and remove this word from the dictionary
    -dequeue this front stack
-if the Queue is empty and you didn't find the word ladder, a word ladder does not exist for these 2 words

*/

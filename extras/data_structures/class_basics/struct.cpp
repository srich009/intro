#include <iostream>
#include <string>
#include <vector>

using namespace std;

// struct 
struct Exam
{
    // member data fields of the object
    int score;
    string uname;
    
    
}; // always end w/semicolon


//prototype
void display(const vector<Exam> &v);
double mean(const vector<Exam> &v);

int main()
{
   
    vector<Exam> midterm;
    Exam entry;
    double avg = 0.0;
    
    cout << "enter exam scores [Username Score]" << endl;
    cout << "Enter Quit when done" << endl;
    
    cin >> entry.uname;
    while(entry.uname != "Quit")
    {
        cin >> entry.score;
        midterm.push_back(entry);
        cin >> entry.uname;
    }
    cout << endl;
    
    avg = mean(midterm);
    cout << "mean: " << avg << endl;
    
    cout << "check if need help:" << endl;
    
    for(unsigned i = 0; i < midterm.size(); ++i)
    {
        if(midterm.at(i).score < avg)
        {
            cout << midterm.at(i).uname << endl;
        }
    }
    
    
    cout << "Scores:" << endl;
    display(midterm);
 

    
    
    
 
return 0;   
}
//=====================================================================

void display(const vector<Exam> &v)
{
    for(unsigned i = 0; i < v.size(); ++i)
    {
        cout << v.at(i).uname << ":" << v.at(i).score << endl;
    }
 
    
}
//------------------------------------------------------------------
double mean(const vector<Exam> &v)
{
    double m = 0.0;
    int count = v.size();
    int k = 0;
    
    
    for(unsigned i = 0; i < v.size(); ++i)
    {   
        k += v.at(i).score;
    }
 
    m = static_cast<double>(k) / count;
 
return m;
}
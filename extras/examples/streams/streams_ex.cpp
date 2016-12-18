// test
//working with files 

#include<iostream> 
#include<fstream> 
#include<sstream>
#include<cstdlib>

using namespace std;

//function
int str2int(string s) // use string stream
{
    istringstream ssin(s);
    int n;
    ssin >> n;
return n;   
}

//function
string int2str(int n)
{
    ostringstream ssout;
    ssout << n;
    return ssout.str();
}


int main()
{
    string input_file;
    cout << "Enter File name:" << endl;
    cin >> input_file;
    
    ifstream inFile;
    inFile.open(input_file.c_str()); // using c_str() to convert name into a cstring
    //also could type: ifstream inFile(input_file.c_str());
    
    if(!inFile.is_open()) //also could if(!inFile)
    {
        cout << "Error opening file" << endl;
        return 1;
    }
    
    int n;
    while( inFile >> n )
    {  
        cout << n << ", ";
    }
    cout << endl;
    
    /*
    
    string s;
    while(getline(inFile, s))
    {
        cout << s << "," << endl;
    }
    
    */
    
    /*
    
    char ch;
    while(inFile >> ch)
    {
        cout << ch << ',';
    }
    
    //alternate
    // get only works with single characters
    
    while( inFile.get(ch) )
    {
        cout << ch << ',';
    }
    
    */
    
    
    inFile.close();
    
    
return 0;   
}



/*
    
    //output
    
    ofstream outFile;
    outFile.open('myOut.dat");
    if(!outFile.is_open())
    {
        cout << "error couldnt find file" << endl;
        return 1;
    }
    


*/


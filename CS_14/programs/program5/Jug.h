//Adjacency List using STL containers

#ifndef __JUG_H__
#define __JUG_H__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <climits>

using namespace std;


struct Vertex // like lab 9/10
{
  list<pair<int, int> > neighbors;  // list by (index, cost)
  pair<int,int> state;              // jug A, jug B ; current amt of water in each
  int distance;
  string color;
  Vertex* prev;
  
  Vertex():state(0,0),distance(INT_MAX),color("WHITE"),prev(0){}
  ~Vertex(){}
};


class Jug 
{
    public:
        Jug(int,int,int,int,int,int,int,int,int);
        //~Jug();

        //solve is used to check input and find the solution if one exists
        //returns -1 invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.
        int solve(string &solution);
        
    private:
        //anything else you need
        
        int capA;          //Ca
        int capB;          //Cb
        int goal;          //N
        int costFillA;     //cfA
        int costFillB;     //cfB
        int costEmptyA;    //ceA
        int costEmptyB;    //ceB
        int costPourAtoB;  //cpAB
        int costPourBtoA;  //cpBA
        
        vector< Vertex > adj; // adjacency list
        pair<int, int> final; // goal   
        
        void initGraph(vector< Vertex >&);  // builds the graph
        void fillA(Vertex&);                //helper
        void fillB(Vertex&);                //helper
        void emptyA(Vertex&);               //helper
        void emptyB(Vertex&);               //helper
        void pourAB(Vertex&);               //helper
        void pourBA(Vertex&);               //helper
        bool search(Vertex&);               //helper
        int _search(Vertex&);               //helper

        string dijkstra(vector< Vertex >&, pair<int,int>); // takes the graph and the pair the final vertex should contain?  

};

#endif // __JUG_H__
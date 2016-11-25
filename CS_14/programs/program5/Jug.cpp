#include "Jug.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;

//vertex
/*
  list<pair<int, int> > neighbors;
  pair<int,int> state; // jug A, jug B
  int distance;
  string color;
  Vertex* prev;
*/

Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA)
   : capA(Ca), capB(Cb), goal(N), costFillA(cfA), costFillB(cfB), 
      costEmptyA(ceA), costEmptyB(ceB), costPourAtoB(cpAB), costPourBtoA(cpBA), /*adj(Ca*Cb),*/ final(0,N)
{
   //graph build here??
  initGraph(adj);
}
//---------------------------------------------------------------------------------------------------------


int Jug::solve(string &solution)
{
   solution = string(); // set empty str
   
   //You will want to verify the costs are positive and 0 < Ca ≤ Cb and N ≤ Cb ≤ 1000
   bool isBad = false;
   if(costEmptyA < 0 || costEmptyB < 0 || costFillA < 0 || costFillB < 0 || costPourAtoB < 0 || costPourBtoA < 0)
   {
      isBad = true; // cost < 0
   }
   if(capA > capB || capA <= 0 || capB <= 0 ) 
   {
      isBad = true; // 0 < Ca ≤ Cb
   }
   if(goal > capB || goal > 1000 || capB > 1000)
   {
      isBad = true; // N ≤ Cb ≤ 1000
   }
   if(isBad)
   {
      return -1; // catch if bad values were passed in
   }

   //???????
   //do dijkstras here ???
   solution = dijkstra(adj, final);
   
   if(solution.empty())
   {
      return 0;
   }
   else
   {
      return 1;
   }

   return 0; // catch;
}
//----------------------------------------------------------------------------------------------


void Jug::initGraph(vector< Vertex > &v)
{
   if(costEmptyA < 0 || costEmptyB < 0 || costFillA < 0 || costFillB < 0 || costPourAtoB < 0 || costPourBtoA < 0)
   {
      return; // cost < 0
   }
   if(capA > capB || capA <= 0 || capB <= 0 ) 
   {
      return; // 0 < Ca ≤ Cb
   }
   if(goal > capB || goal > 1000 || capB > 1000)
   {
      return; // N ≤ Cb ≤ 1000
   }
   ////////*****/////  if bad dont build, have dijkstra check if empty?? same tests as solve()
   
   
   v.reserve((capA + 1)*(capB + 1)); //?? size of all possible nodes
   v.push_back(Vertex()); // (0,0) to start

   for(unsigned int j = 0; j < v.size(); j++)
   {
      Vertex start = v.at(j);
      Vertex n1= start;
      Vertex n2= start;
      Vertex n3= start;
      Vertex n4= start;
      Vertex n5= start;
      Vertex n6= start;
      
      fillA(n1);
      fillB(n2);
      emptyA(n3);
      emptyB(n4);
      pourAB(n5);
      pourBA(n6);
      
      cout << "i: "  << j << endl;
      cout << "n1: " << n1.state.first << ',' << n1.state.second << endl;
      cout << "n2: " << n2.state.first << ',' << n2.state.second << endl;
      cout << "n3: " << n3.state.first << ',' << n3.state.second << endl; 
      cout << "n4: " << n4.state.first << ',' << n4.state.second << endl;
      cout << "n5: " << n5.state.first << ',' << n5.state.second << endl;
      cout << "n6: " << n6.state.first << ',' << n6.state.second << endl << endl;
      
/*      // //fill adjacency lists w/ acutal values of jug states ??
      // start.neighbors.push_back(n1.state);
      // start.neighbors.push_back(n2.state);
      // start.neighbors.push_back(n3.state);
      // start.neighbors.push_back(n4.state);
      // start.neighbors.push_back(n5.state);
      // start.neighbors.push_back(n6.state);*/
      
      
      //create vector of verticies
      if(!search(n1))
      {
         adj.push_back(n1);
      }
      
      if(!search(n2))
      {
         adj.push_back(n2);
      }
      
      if(!search(n3))
      {
         adj.push_back(n3);
      }
      
      if(!search(n4))
      {
         adj.push_back(n4);
      }
      
      if(!search(n5))
      {
         adj.push_back(n5);
      }
      
      if(!search(n6))
      {
         adj.push_back(n6);
      }
      
      
      start.neighbors.push_back(pair<int,int>(_search(n1),costFillA));    //fillA
      start.neighbors.push_back(pair<int,int>(_search(n2),costFillB));    //fillB
      start.neighbors.push_back(pair<int,int>(_search(n3),costEmptyA));   //emptyA
      start.neighbors.push_back(pair<int,int>(_search(n4),costEmptyB));   //emptyB
      start.neighbors.push_back(pair<int,int>(_search(n5),costPourAtoB)); //pourAB
      start.neighbors.push_back(pair<int,int>(_search(n6),costPourBtoA)); //pourBA
    
       v.at(j) = start; //??  
   }

   for(unsigned int i = 0; i < adj.size(); i++)
   {
      cout << adj.at(i).state.first << ',' <<  adj.at(i).state.second << endl;
   }
   cout  << "sz: " << adj.size() << endl << endl;

   for(unsigned int i = 0; i < adj.size(); i++)
   {
      cout << adj.at(i).state.first << ',' <<  adj.at(i).state.second;
      for( list<pair<int, int> >::iterator it = adj.at(i).neighbors.begin(); it != adj.at(i).neighbors.end(); it++)
      {
         cout << " -> " << it->first << ',' <<  it->second;
      }
      cout << endl;
   }
}
//---------------------------------------------------------------------------------------------------------------

void Jug::fillA(Vertex& v)
{
   v.state.first = capA;
}
//----------------------------------------------------------

void Jug::fillB(Vertex& v)
{
   v.state.second = capB;
}
//----------------------------------------------------------

void Jug::emptyA(Vertex& v)
{
   v.state.first = 0;
}
//----------------------------------------------------------

void Jug::emptyB(Vertex& v)
{
   v.state.second = 0;
}
//----------------------------------------------------------

void Jug::pourAB(Vertex& v)
{
   while( v.state.first != 0 && v.state.second != capB)
   {
      v.state.first--;
      v.state.second++;
   }
}
//----------------------------------------------------------
 
void Jug::pourBA(Vertex& v)
{
   while(v.state.second != 0 && v.state.first != capA)
   {
      v.state.second--;
      v.state.first++;
   }
}
//----------------------------------------------------------

bool Jug::search(Vertex &v)
{
   for(unsigned int i = 0; i < adj.size(); i++)
   {
      if(adj.at(i).state.first == v.state.first && adj.at(i).state.second == v.state.second)
      {
         return true;
      }
   }
   return false;
}
//---------------------------------------------------------------------------------------

int Jug::_search(Vertex &v)
{
   for(unsigned int i = 0; i < adj.size(); i++)
   {
      if(adj.at(i).state.first == v.state.first && adj.at(i).state.second == v.state.second)
      {
         return i;
      }
   }
   return -1;// have a check...
}
//---------------------------------------------------------------------------------------

string Jug::dijkstra(vector< Vertex >& v, pair<int,int> fin) // takes the graph and the pair the final vertex should contain?
{
   cout << endl << "DIJKSTRA'S" << endl;
   
   if(v.empty()) return string();      // catch an empty
   
   string soln;                        // construct along the way?
   vector<pair<int,int> > visited;     // contains nodes already visited
   priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > PQ;  // min heap of pairs? TOP
   v.at(0).distance = 0;               // initialize single source distance to self
  
   for(unsigned i = 0; i < v.size(); i++) // fill PQ with all the verticies
   {
      PQ.push(v.at(i).state);
      for( list<pair<int, int> >::iterator it = v.at(i).neighbors.begin(); it != v.at(i).neighbors.end(); it++)
      {
         PQ.push(*it);
      }
   }
    
   while(!PQ.empty())
   {
      Vertex verp = v.at(PQ.top().first); // extract min
      PQ.pop(); // ??
      visited.push_back(verp.state);      // put vertex in visited
      
      cout << "hey" << endl;
      cout << "PQ.sz: " << PQ.size()  << ' ' << "(" << PQ.top().first << ','<< PQ.top().second << ')' << endl;
      cout << "(" << verp.state.first << ','<< verp.state.second <<')' << endl;
      cout << "U[dist]: " << verp.distance << endl;
      
      list<pair<int, int> >::iterator it = verp.neighbors.begin(); 
      it++;                                     //advance it to the first neighbor
      for(; it != verp.neighbors.end(); it++ )  // all verp neighbors [1,n-1] 
      {
         if (verp.distance == INT_MAX) verp.distance = 0; //fix overflow errors...
         int calc = verp.distance + it->second;           // distance so far + cost to get to this specific vertex
         
         cout << "(" << it->first << ','<< it->second <<')' << endl;
         cout << "(" << v.at(it->first).state.first << ','<< v.at(it->first).state.second <<')' << endl;
         cout << "calc: " << calc << endl; 
         cout << "v[dist]: " << v.at(it->first).distance << endl;
         
         
         if(calc < v.at(it->first).distance)
         {   
            v.at(it->first).distance = calc;
            v.at(it->first).prev = &verp;
            //PQ.pop();
         }
         
         cout << "v[dist]: " << v.at(it->first).distance << endl;
         
      }
   
   }
   
   //cout << visited.size() << endl;
   for(unsigned i = 0; i < visited.size(); i++)
   {
      cout << v.at(visited.at(i).first).state.first << ',' << v.at(visited.at(i).first).state.second << endl;
   }
   
   return soln;
   
   /*
   dijkstra's algorithm will give you the shortest path. You then traverse that path backwards starting from the vertex that stores the goal [0, goal]
   back to the starting vertex [0, 0]. At this point you can build the string, 
   or instead you can store this path in something so that you can then traverse the path in order, [0, 0] to [0, goal], building the string as you go.
   One way, you are building the string from the end of the string to the beginning of the string, the other way you are building it from the beginning to the end. 
   It can be done either way, but in both cases, you build this after dijkstra's algorithm has been performed.
   */
}
//--------------------------------------------------------------------------------------------------------------- 
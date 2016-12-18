#include "Graph.h"
#include <climits>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

/*
struct Edge
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) { }

class Graph
    std::vector<std::list<Edge>> g;
*/



Graph::Graph(int preset) {
    switch(preset) {
        //Note: I'm treating undirected graphs as directed graphs
        //with edges going in both directions
        case 1: //http://i.stack.imgur.com/90Qwu.png (A is 0, F is 5...)
            g = std::vector<std::list<Edge>>(6);
            
            g[0].push_back(Edge(1, 3));
            g[0].push_back(Edge(2, 5));
            g[0].push_back(Edge(3, 9));
            
            g[1].push_back(Edge(0, 3));
            g[1].push_back(Edge(2, 3));
            g[1].push_back(Edge(3, 4));
            g[1].push_back(Edge(4, 7));
            
            g[2].push_back(Edge(0, 5));
            g[2].push_back(Edge(1, 3));
            g[2].push_back(Edge(3, 2));
            g[2].push_back(Edge(4, 6));
            g[2].push_back(Edge(5, 8));
            
            g[3].push_back(Edge(0, 9));
            g[3].push_back(Edge(1, 4));
            g[3].push_back(Edge(2, 2));
            g[3].push_back(Edge(4, 2));
            g[3].push_back(Edge(5, 2));
            
            g[4].push_back(Edge(1, 7));
            g[4].push_back(Edge(2, 6));
            g[4].push_back(Edge(3, 2));
            g[4].push_back(Edge(5, 5));
            
            g[5].push_back(Edge(2, 8));
            g[5].push_back(Edge(3, 2));
            g[5].push_back(Edge(4, 5));
            break;
        case 2: //https://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/Dijkstra.gif
            g = std::vector<std::list<Edge>>(7);
            
            g[0].push_back(Edge(1, 14));
            g[0].push_back(Edge(3, 22));
            g[0].push_back(Edge(4, 4));
            
            g[1].push_back(Edge(6, 3));
            
            g[2].push_back(Edge(1, 16));
            g[2].push_back(Edge(3, 12));
            
            //D has no outgoing edges...
            
            g[4].push_back(Edge(3, 12));
            g[4].push_back(Edge(5, 10));
            
            //F has no outgoing edges...
            
            g[6].push_back(Edge(5, 1));
            break;
        case 3: //http://d2vlcm61l7u1fs.cloudfront.net/media/7dc/7dcc48aa-8b7f-4492-bb95-df7c141f26b8/phpaNFvua.png
            
            g = std::vector<std::list<Edge>>(8);
            
            g[0].push_back(Edge(1, 1));
            g[0].push_back(Edge(4, 4));
            g[0].push_back(Edge(5, 8));
            
            g[1].push_back(Edge(2, 2));
            g[1].push_back(Edge(5, 6));
            g[1].push_back(Edge(6, 6));
            
            g[2].push_back(Edge(3, 1));
            g[2].push_back(Edge(6, 2));
            
            g[3].push_back(Edge(6, 1));
            g[3].push_back(Edge(7, 4));
            
            g[4].push_back(Edge(5, 5));
            
            //F has no outgoing edges...
            
            g[6].push_back(Edge(5, 1));
            g[6].push_back(Edge(7, 1));
            
            //H has no outgoing edges...
            break;
    }
}

void Graph::dijkstra(int start) const
{
    //here
    
}
//--------------------------------------------------------------------

void Graph::BFS(int start) const
{
    std::vector<int> visited;
    std::queue<int> Q;
    
    Q.push(start);
    visited.push_back(start);
    
    while(!Q.empty())
    {    
        int u = Q.front();
        Q.pop();
        
        std::list<Edge> cur = g.at(u);
        std::list<Edge>::iterator it = cur.begin();
        
        
        //cout << "Visiting: " << (char)('A' + u) << "\tand placing ";
        
        for(; it != cur.end(); it++) // go through list
        {
            int h = it->to;
            if(!isIn(visited, h))
            {
                //cout << (char)('A' + h) << ' ';
                Q.push(h);
                visited.push_back(h);
            }
        }
        //cout << "into the queue" << endl;
    }
    
    for(unsigned i = 0; i < visited.size(); i++)
    {
        std::cout << static_cast<char>('A' + visited.at(i)) << ' ';
    }
    std::cout << std::endl;
}
//-----------------------------------------------------------------------------

void Graph::DFS(int start) const // arbitrary choice picks highest val each time
{
    vector<int> discovered;
    stack<int> S;
    
    S.push(start);
    
    while(!S.empty())
    {
        int v = S.top();
        S.pop();
        
        std::list<Edge> cur = g.at(v);
        std::list<Edge>::iterator it = cur.begin();
        
        if(!isIn(discovered, v))
        {
            //cout << "Visiting: " << (char)('A' + v) << "\tand placing ";
            discovered.push_back(v);
            for(; it != cur.end(); it++) // go through list
            {
                int k = it->to;
                
                //cout << (char)('A' + k) << ' ';
                
                S.push(k);
            }
            //cout << "into the stack" << endl;
        }
    }
    
    for(unsigned i = 0; i < discovered.size(); i++)
    {
        std::cout << static_cast<char>('A' + discovered.at(i)) << ' ';
    }
    std::cout << std::endl; 
}
//-----------------------------------------------------------------------------------------------

bool Graph::isIn(std::vector<int> v, int w) const
{
    bool yes = false;
    for(unsigned int i = 0; i < v.size(); i++)
    {
        if(w == v.at(i))
        {
            yes = true;
            break;
        }
    }
    return yes;    
}
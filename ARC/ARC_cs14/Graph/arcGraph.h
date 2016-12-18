//c++11

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <list>

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) { }
};

class Graph {
private:
    std::vector<std::list<Edge>> g;
    
public:
    Graph(int); //Instantiates a preset graph
    void dijkstra(int start) const; //TODO
    void BFS(int start) const; //TODO
    void DFS(int start) const; //TODO
    bool isIn(std::vector<int>, int) const;
};

#endif //__GRAPH_H__

//TODO:
//
//1. Implement Dijkstra's Algorithm to start at the passed in node and print
//a report for the graph, so if 0 (A) was pass in for my made up graph,
//The report should show the distance and how you got there like:
//
// A: 0 A
// B: 5 A->C->B
// C: 2 A->C
// D: 9 A->E->F->D
// ...
//
// 2. Implement algorithms to print the nodes in BFS order and DFS order.
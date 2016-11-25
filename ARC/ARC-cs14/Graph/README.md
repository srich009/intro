Graphs!
=======

How we're implementing
----------------------
While your assignment will use an adjacency matrix based implementation of a graph, I've given you the code for an adjacency list implementation!

The whole graph is a vector of lists, where every list represents a single node's outgoing edges. To make undirected graphs simpler, I've pretended thate they're directed graphs with edges pointing both ways.

Your tasks
----------

###Understanding Dijkstra's Algorithm

Pull out that piece of paper and draw out Dijkstra's algorithm (performed on node A) for each of the following graphs (notice that these are the graphs that you're programming for, so you can use this practice run of Dijkstra's as a test bench):

![](http://i.stack.imgur.com/90Qwu.png "I'm a graph!")
![](https://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/Dijkstra.gif "And I'm a graph!")
![](http://d2vlcm61l7u1fs.cloudfront.net/media/7dc/7dcc48aa-8b7f-4492-bb95-df7c141f26b8/phpaNFvua.png "Me too guys!!")

###Programming Dijkstra's Algorithm

Implement Dijkstra's Algorithm to start at the passed in node and print
a report for the graph, so if 0 (A) was pass in for my made up graph,
The report should show the distance and how you got there like:

```
A: 0 
B: 5 A->C->B
C: 2 A->C
D: Unreachable
E: 9 A->G->F->D
...
```

*Tip: when you're storing your theoretical distances, use `INT_MAX` after you've included [climits](http://www.cplusplus.com/reference/climits/) to represent infinity*

###BFS And DFS

Implement algorithms to print the nodes in BFS order and DFS order.

// // LS-62
// GRAPH is a combination of vertices and edges
//              1       0
//                              4
//              2       3

// vertices/nodes= {0,1,2,3,4}; --> these are vertices
// edge is a connection between two vertices or nodes;
// edges={(1,0),(1,3),(1,2),(2,3),(0,4),(0,3),(3,4)}

// trees is also a graph
// But graph cannot be a tree

// neighbour means-->directly connected to adjacent node
// example:     1={0,2};
//              3={2,0};
//              0={1,3,4};

// subgraph is a part of graph
// example: 1 is a part of graph . same as 2,0,3,4;

// DEGREE--> count of directly connected nodes
// example: degree of 0 is 3,  degree of 2 is 2;

// DEGREE ARE OF TWO TYPES:
// 1-->indegree : no. of nodes coming towards a node;
// 2-->outdegree: no. of nodes going outwards from a node;

// total degree=indegree+outdegree;

// CONNECTED GRAPH: from a node, if we reach to all nodes then graph is connected.

// when we traverse on a graph ,gives us a tree
// every node is having only left childs is called left skew tree
// every node is having only right childs is called right skew tree
// basically traversal of graph gives skew tree
// collection of multiple tree is called FOREST.

// UNWEIGHTED GRAPHS: in which distance is not mentioned
// example: A    B   -->here we can move from A to B and B to A both but we don't kw about distance

// WEIGHTED GRAPH: in which distance is mentioned
// example :A--->B jane ka distance 1000   and B---->A jane ka distance 900 , so here we mention distance*

// DIRECTED --> we can only move in one direction either A-->B or A<--B.
// DIRECTED GRAPH HAVE CYCLE: ONLY WHEN ON SAME PATH A NODE IS VISITED AGAIN IS CALLED A CYCLE
// UNDIRECTED OR BIDIRECTIONAL--> in which we don't show any direction so it can traverse in both direction or not in any
// direction like  A------B;

// WEIGHTED UNDIRECTED GRAPH
// WEIGHTED DIRECTED GRAPH
// UNWEIGHTED UNDIRECTED GRAPH
// UNWEIGHTED DIRECTED GRAPH

// COMPLETE GRAPH: every vertices is connected to all other vertices
// total edges: nC2 (n-->no. of nodes )
// nC2=(n*(n-1))/2= (n^2/2-n/2)~(n^2/2)~(n^2);

// IMPLEMENTATION OF GRAPGH:
// METHODS:-
// 1. Edge list
// 2. Adjacency matrix
// 3. Adjacency list(best method)

// sbse acha graph ka implementation vo hota h jisme neighbours ko access kr skte ho

// TOTAL DEGREE OF A GRAPH=2* TOTAL NO. OF EDGES   -->(undirected graph)
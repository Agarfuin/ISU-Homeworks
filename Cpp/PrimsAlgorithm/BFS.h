#ifndef BFS_H
#define BFS_H

// ****************************************************// Header file BFS.h // A breadth-first search of the Graph class.  // ****************************************************#include <queue>#include "Graph.h"using namespace std;class BFS{ protected:   const Graph &g;
   int comp;   int count;            // used to mark vertices as visited   vector<int> mark;     // marked vertices   vector<int> parents;  // parents of each vertex   void search(Edge e);   // Searches the adjacency list of each vertex breadth first.   // Precondition:  The edge exists in the graph.   // Postcondition: Performs a breadth first search of   // the adjacency list of vertex w in Edge e. public:
   BFS(const Graph &g);   // Constructor   // Precondition: The graph exists.     // Postcondition: Initializes arguments and starts the   // breadth-first search.		   void startSearch();   // Searches each unvisited vertex    // Precondition:  The edge exists in the graph.   // Postcondition: Starts a breadth first search with each   // unvisited vertex.

   int findNumComponents();};// End of header file

#endif
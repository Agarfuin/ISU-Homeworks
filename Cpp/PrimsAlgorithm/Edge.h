#ifndef EDGE_H
#define EDGE_H

// **************************************************// Header file Edge.h // An Edge class for graph implementations.  // **************************************************class Edge{public:   int v, w, weight;   Edge(int firstVertex, int secondVertex, int edgeWeight)   {      v = firstVertex;      w = secondVertex;      weight = edgeWeight;    }  // end constructor};// End of header file

#endif
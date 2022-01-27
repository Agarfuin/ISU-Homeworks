// ****************************************************

#include "BFS.h"
#include <iostream>
using namespace std;

BFS::BFS(const Graph &g) : g(g), mark(g.getNumVertices(), -1),

int BFS::findNumComponents(){
	comp = 0;
    for (int v = 0; v < g.getNumVertices(); v++){
        if (mark[v] == -1){
			comp++;
        	search(Edge(v,v, 0));
		}
	}
	return comp;
}
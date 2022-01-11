#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "Edge.h"
#include <ctime>
#include <cstdlib>

#define MAX 999999

using namespace std;

Graph create_graph(int n, float p);
int get_num_components(BFS b, int n, float p);
void primsAlgo(Graph g);
int minKey(Graph g, int key[], bool visited[]);


int main(){
    int n = 10;                       // for the graph that has 10.000 vertices
	float p = 0.5;                     // 0.001 < p < 0.0015 makes the graph connected.
	srand(time(NULL));                  // 0.0012 works fine but not perfect
    Graph g = create_graph(n, p);
	BFS b(g);
    cout << "Total number of vertices = " << g.getNumVertices() << endl;
    cout << "Total number of edges = " << g.getNumEdges() << endl;
	cout << "Number of components in the graph = " << get_num_components(b,n,p) << endl;
    primsAlgo(g);
    
    return 0;
}


Graph create_graph(int n, float p){
	Graph g(n);
	if(p==0)
		return g;
	else{
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				if(p==1){
                    int rand_weight;
                    rand_weight = (rand()%10)+1
;
					Edge e(i,j,rand_weight);
					g.add(e);
				}
				else{
                    float rand_float = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					if(rand_float < p){
                        int rand_weight;
                        rand_weight = (rand()%10)+1;
						Edge e(i,j,rand_weight);
						g.add(e);
					}
				}
			}
		}
		return g;
	}
}


int get_num_components(BFS b, int n, float p){
	if(p == 0)
		return n;
	else if(p == 1)
		return 1;
	else
		return b.findNumComponents();
}


int minKey(Graph g, int key[], bool visited[]){
    int num_of_vertices = g.getNumVertices();
    int min = MAX;
    int min_index;

    for(int i = 0; i<num_of_vertices; i++){
        if(visited[i] == false && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}


void primsAlgo(Graph g){
    int num_of_vertices = g.getNumVertices();
    int graph[num_of_vertices][num_of_vertices];
    map<int, int> vertex;
    map<int, int>::iterator iter;
    for(int i=0;i<num_of_vertices;i++){
        vertex = g.adjList[i];
        for(iter = vertex.begin(); iter != vertex.end(); iter++){
            if(iter->first == 0 && i!= 0)
                graph[i][iter->first] = graph[0][i];
            else{
                if(iter->first > i && i!=0)
                    graph[i][iter->first] = iter->second;
                else
                    graph[i][iter->first] = iter->second;
            }
        }
    }
    
    for(int i = 0;i<num_of_vertices;i++){
        for(int j = 0;j<num_of_vertices;j++){
            if(i==j)
                graph[i][j] = 0;
            else if(1>graph[i][j] || 10<graph[i][j])
                graph[i][j] = graph[j][i] = 0;
        }
    }
    
    int parent[num_of_vertices];
    int key[num_of_vertices];
    bool visited[num_of_vertices];
    
    for(int i = 0;i<num_of_vertices;i++){
        key[i] = MAX;
        visited[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for(int i = 0;i<num_of_vertices-1;i++){
        int u = minKey(g, key, visited);
        visited[u] = true;
        for(int v = 0; v < num_of_vertices; v++){
            if(graph[u][v] && visited[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    int weight=0;
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < num_of_vertices; i++){
        cout << parent[i] << " - " << i <<" \t" << graph[i][parent[i]] << endl;
        weight += graph[i][parent[i]];
    }
    
    cout << "Total weight of spanning tree = " << weight << endl;
}










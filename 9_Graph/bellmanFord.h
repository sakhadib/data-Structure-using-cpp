#include "weighetedGraph.h"
using namespace std;

const int inf = 1e9;

int dist[1000];

int bellmanFord(weightedGraph g, int source, int destination){
    init(dist, g.n, inf);
    dist[source] = 0;

    for(int i=0; i<g.n-1; i++){
        for(int u=0; u<g.n; u++){
            for(int j=0; j<g.adj[u].size(); j++){
                int v = g.adj[u][j].first;
                int w = g.adj[u][j].second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }


    return dist[destination];
}



#include "weighetedGraph.h"
using namespace std;

const int inf = 1e9;
int dist[1000];

int PathRelaxation(weightedGraph g, int source, int destination){
    queue <int> q;
    init(dist, g.n, inf);
    q.push(source);
    dist[source] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<g.adj[u].size(); i++){
            int v = g.adj[u][i].first;
            int w = g.adj[u][i].second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }

    return dist[destination];
}
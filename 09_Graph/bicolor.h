#include "GraphList.h"
using namespace std;

bool isBicolorable(graph g, int source){
    int color[100];
    init(color, 100, -1);
    queue<int> q;

    q.push(source);
    color[source] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<g.adj[u].size(); i++){
            int v = g.adj[u][i];
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }

    return true;

}

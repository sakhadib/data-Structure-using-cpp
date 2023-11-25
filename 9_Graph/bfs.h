#include "GraphList.h"
using namespace std;

int previous[100];
bool is_travarsed = false;

void bfs_level(graph g, int source, int destination){
    is_travarsed = true;
    queue<int> q;
    int level[100];

    init(level, 100, -1);

    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i < g.adj[u].size(); i++){
            int v = g.adj[u][i];
            if(level[v] == -1){
                level[v] = level[u] + 1;
                previous[v] = u; // v is discovered from u
                q.push(v);
            }
        }
    }

    cout << level[destination] << endl;
}



void printPath(graph g, int source, int destination){
    
    if(is_travarsed == false){
        bfs_level(g, source, destination);
    }
    
    if(source == destination){
        cout << source;
    }
    else{
        printPath(g, source, previous[destination]);
        cout << " -> " << destination;
    }
}
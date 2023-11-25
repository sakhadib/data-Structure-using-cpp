#include "GraphList.h"
using namespace std;

int parent[100];

void dfs(graph g, int source, int destination){
    int visited[100];
    init(visited, 100, 0);
    stack<int> s;

    s.push(source);
    visited[source] = 1;

    while(!s.empty()){
        int u = s.top();
        s.pop();

        for(int i=0; i<g.adj[u].size(); i++){
            int v = g.adj[u][i];
            if(visited[v] == 0){
                visited[v] = 1;
                s.push(v);
                parent[v] = u;
            }
        }
    }

    if(visited[destination] == 1){
        cout << "Path exists" << endl;
    }
    else{
        cout << "Path does not exist" << endl;
    }

}


// Code to find a cycle in a graph
bool findCycle(graph g, int source){
    int visited[100];
    init(visited, 100, 0);
    init(parent, 100, -1);
    stack<int> s;

    s.push(source);
    visited[source] = 1;

    while(!s.empty()){
        int u = s.top();
        s.pop();
        for(int i=0; i<g.adj[u].size(); i++){
            int v = g.adj[u][i];
            if(visited[v] == 0){
                visited[v] = 1;
                s.push(v);
                parent[v] = u;
            }
            else if(visited[v] == 1 && parent[u] != v){
                return true;
            }
        }
    }

    return false;
}


// Code to find a cycle in a directed graph
bool findCycleInDirectedGraph(graph g, int source) {
    int visited[100];
    int parent[100];
    init(visited, 100, 0);
    init(parent, 100, -1);

    stack<int> s;
    s.push(source);

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        visited[u] = 1;  // Mark the node as visited when adding it to the stack.

        for (int i = 0; i < g.adj[u].size(); i++) {
            int v = g.adj[u][i];
            if (visited[v] == 0) {
                s.push(v);
                parent[v] = u;
            } else if (visited[v] == 1) {
                return true;  // A back edge indicates a cycle.
            }
        }

        visited[u] = 2; // Mark the node as fully processed.
    }

    return false;
}



// Print path using DFS
void printPath(int source, int destination){
    if(source == destination){
        cout << source;
    }
    else{
        printPath(source, parent[destination]);
        cout << " -> " << destination;
    }
}


//Bicolorable graph detection using DFS
bool bicolorableDFS(graph g, int source){
    int color[100];
    init(color, 100, -1);
    stack<int> s;

    s.push(source);
    color[source] = 1;

    while(!s.empty()){
        int u = s.top();
        s.pop();

        for(int i=0; i<g.adj[u].size(); i++){
            int v = g.adj[u][i];
            if(color[v] == -1){
                color[v] = 1 - color[u];
                s.push(v);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }

    return true;
}
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class graph{
    public:
    int v;
    vector<int> *adj;
    graph(int v){
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u); //for undirected graph
    }

    void printGraph(){
        for(int i=0; i<v; i++){
            cout << i << " -> ";
            for(int j=0; j<adj[i].size(); j++){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

void init(int arr[], int size, int value){
    for(int i=0; i<size; i++){
        arr[i] = value;
    }
}

void readGraph(graph &g, bool isDirected){
    int u, v;
    while(cin >> u >> v){
        g.adj[u].push_back(v);
        if(!isDirected){
            g.adj[v].push_back(u);
        }
    }
}
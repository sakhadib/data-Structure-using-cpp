#include<bits/stdc++.h>
using namespace std;

class weightedGraph{
    public:
    int n;
    vector<pair<int, int> > *adj;
    weightedGraph(int n){
        this->n = n;
        adj = new vector<pair<int, int> >[n];
    }
    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
};

void readGraph(weightedGraph &g, bool isDirected){
    int u, v, w;
    while(cin >> u >> v >> w){
        g.adj[u].push_back(make_pair(v, w));
        if(!isDirected){
            g.adj[v].push_back(make_pair(u, w));
        }
    }
}

void init(int arr[], int size, int value){
    for(int i=0; i<size; i++){
        arr[i] = value;
    }
}
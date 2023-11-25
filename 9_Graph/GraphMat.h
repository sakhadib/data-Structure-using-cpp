#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class GraphMat{
    public:
        int V;
        bool isDirected;
        int **adj;
        GraphMat(int V, bool dir){
            this->V = V;
            isDirected = dir;
            adj = new int*[V];
            for(int i=0;i<V;i++){
                adj[i] = new int[V];
                for(int j=0;j<V;j++){
                    adj[i][j] = INF;
                }
            }

            for(int i=0;i<V;i++){
                adj[i][i] = 0;
            }
        }

        void addEdge(int u, int v, int cost){
            adj[u][v] = cost;
            if(!isDirected){
                adj[v][u] = cost;
            }
        }

        void printMatrix(){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    cout<<adj[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    
};

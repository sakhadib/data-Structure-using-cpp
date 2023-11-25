#include "GraphMat.h"
using namespace std;

const int MAX = 100;

void init(int x[MAX][MAX]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            x[i][j] = j; // Initialize Mnext[i][j] to j
        }
    }
}

int Mnext[MAX][MAX];

void floydWarshall(GraphMat g){

    init(Mnext);
    for(int i=0; i<g.V; i++){
        for(int j=0; j<g.V; j++){
            for(int k=0; k<g.V; k++){
                if(g.adj[j][i] + g.adj[i][k] < g.adj[j][k]){
                    g.adj[j][k] = g.adj[j][i] + g.adj[i][k];
                    Mnext[j][k] = i;
                }
            }
        }
    }
}


void findPath(int i, int j, GraphMat g){
    cout << i << " ";
    while(i != j){
        i = Mnext[i][j];
        cout << i << " ";
    }
}
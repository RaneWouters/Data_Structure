#include <cstdio>
#include <iostream>
using namespace std;

constexpr int MAXSIZE = 100;
constexpr int INFINITY = 65535;

using VertexType = char;
using EdgeType = int;

typedef struct{
    VertexType Vertex[MAXSIZE] = {0};
    EdgeType Edge[MAXSIZE][MAXSIZE];
    int numVertex, numEdge;
}MGraph;

void Init_Graph(MGraph &Graph){
    cout<<"enter the number of Vertex and the number of Edge."<<endl;
    cin>>Graph.numVertex>>Graph.numEdge;
    for(int q=0; q<Graph.numVertex; q++){
        cout<<"enter the name of each Vertex."<<endl;
        cin>>Graph.Vertex[q];
    }
    for(int q=0; q<Graph.numVertex; q++){
        for(int i=0; i<Graph.numVertex; i++){
            Graph.Edge[q][i] = INFINITY;
        }
    }
    for(int q=0; q<Graph.numVertex; q++)
        Graph.Edge[q][q] = 0;
    for(int q=0; q<Graph.numEdge; q++){
        int i, j, weight;
        cout<<"enter the tail and head and the weight."<<endl;
        cin>>i>>j>>weight;
        Graph.Edge[i][j] = weight;
        Graph.Edge[j][i] = weight;
    }
}

void PrintPath(MGraph &Graph, int &u, int &v, int (&path)[MAXSIZE][MAXSIZE]){
    if(path[u][v] == -1){
        printf("(%c, %c)\n", Graph.Vertex[u], Graph.Vertex[v]);
        return;
    }else{
        int mid = path[u][v];
        PrintPath(Graph, u, mid, path);
        PrintPath(Graph, mid, v, path);
    }
}

void Floyd(MGraph &Graph){
    int distance[MAXSIZE][MAXSIZE];
    int path[MAXSIZE][MAXSIZE];
    for(int q=0; q<Graph.numVertex; q++){
        for(int i=0; i<Graph.numVertex; i++){
            distance[q][i] = Graph.Edge[q][i];
            path[q][i] = -1;
        }
    }

    for(int q=0; q<Graph.numVertex; q++){
        for(int i=0; i<Graph.numVertex; i++){
            for(int v=0; v<Graph.numVertex; v++){
                if(distance[i][v] > distance[i][q] + distance[q][v]){
                    distance[i][v] = distance[i][q] + distance[q][v];
                    path[i][v] = q;
                }
            }
        }
    }

    int u, v;
    cout<<"enter two vertex that you want to find."<<endl;
    cin>>u>>v;
    PrintPath(Graph, u, v, path);
}

int main(){
    MGraph Graph;
    Init_Graph(Graph);
    Floyd(Graph);
    return 0;
}

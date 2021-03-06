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
    bool visited[MAXSIZE];
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
    for(int q=0; q<Graph.numEdge; q++){
        int i, j, weight;
        cout<<"enter the tail and head and the weight."<<endl;
        cin>>i>>j>>weight;
        Graph.Edge[i][j] = weight;
        Graph.Edge[j][i] = weight;
    }
}

void DFS(MGraph &Graph, int q);
void DFSTraverse(MGraph &Graph);

int main(){
    MGraph Graph;
    Init_Graph(Graph);
    DFSTraverse(Graph);
    cout<<endl;
    return 0;
}

void DFS(MGraph &Graph, int q){
    Graph.visited[q] = true;
    cout<<Graph.Vertex[q]<<' ';
    for(int i=0; i<Graph.numVertex; i++){
        if(Graph.Edge[q][i] != INFINITY && !Graph.visited[i])
            DFS(Graph, i);
    }
}

void DFSTraverse(MGraph &Graph){
    for(int q=0; q<Graph.numVertex; q++)
        Graph.visited[q] = false;
    for(int q=0; q<Graph.numVertex; q++){
        if(!Graph.visited[q]){
            DFS(Graph, q);
        }
    }
}

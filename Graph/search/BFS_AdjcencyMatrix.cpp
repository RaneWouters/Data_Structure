#include <iostream>
#include <queue>
using namespace std;

constexpr int MAXSIZE = 100;
constexpr int INFINITY = 65535;

using VertexType = char;
using EdgeType = int;

typedef struct{
    bool visited[MAXSIZE];
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
    for(int q=0; q<Graph.numEdge; q++){
        int i, j, weight;
        cout<<"enter the tail and head and the weight."<<endl;
        cin>>i>>j>>weight;
        Graph.Edge[i][j] = weight;
        Graph.Edge[j][i] = weight;
    }
}

void BFSTraverse(MGraph &Graph){
    queue<int> Vertex;
    for(int q=0; q<Graph.numVertex; q++)
        Graph.visited[q] = false;
    for(int q=0; q<Graph.numVertex; q++){
        if(!Graph.visited[q]){
            Graph.visited[q] = true;
            cout<<Graph.Vertex[q]<<' ';
            Vertex.push(q);
            while(!Vertex.empty()){
                int e = Vertex.front();
                Vertex.pop();
                for(int i=0; i<Graph.numVertex; i++){
                    if(Graph.Edge[e][i] && !Graph.visited[i]){
                        Graph.visited[i] = true;
                        cout<<Graph.Vertex[i]<<' ';
                        Vertex.push(i);
                    }
                }
            }
        }
    }
}

int main(){
    MGraph Graph;
    Init_Graph(Graph);
    BFSTraverse(Graph);
    cout<<endl;
    return 0;
}
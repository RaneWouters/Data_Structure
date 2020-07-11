#include <cstdlib>
#include <iostream>
using namespace std;

constexpr int MAXSIZE = 100;
constexpr int INFINITY = 65535;

using VertexType = string;
using EdgeType = int;

struct EdgeNode{
    int adjvex;
    EdgeType weight;
    EdgeNode* next;
};

typedef struct{
    VertexType data;
    EdgeNode* firstedge;
}VertexNode;

typedef struct{
    bool visited[MAXSIZE];
    VertexNode Vertex[MAXSIZE];
    int numEdge, numVertex;
}MGraphAdjList;

void Init_Graph(MGraphAdjList &Graph){
    cout<<"enter the number of Vertex and the number of Edge."<<endl;
    cin>>Graph.numVertex>>Graph.numEdge;
    cout<<"enter the name of each Vertex."<<endl;
    for(int q=0; q<Graph.numVertex; q++){
        cin>>Graph.Vertex[q].data;
        Graph.Vertex[q].firstedge = nullptr;
    }
    for(int q=0; q<Graph.numEdge; q++){
        int i, j, weight;
        cout<<"enter the tail and the head and the weight."<<endl;
        cin>>i>>j>>weight;

        EdgeNode* e;
        e = (EdgeNode*)malloc(sizeof(EdgeNode));

        e->next = Graph.Vertex[i].firstedge;
        e->adjvex = j;
        e->weight = weight;
        Graph.Vertex[i].firstedge = e;

        e = (EdgeNode*)malloc(sizeof(EdgeNode));

        e->next = Graph.Vertex[j].firstedge;
        e->adjvex = i;
        e->weight = weight;
        Graph.Vertex[j].firstedge = e;
    }
}

void DFS(MGraphAdjList &Graph, int q);
void DFSTraverse(MGraphAdjList &Graph);

int main(){
    MGraphAdjList Graph;
    Init_Graph(Graph);
    DFSTraverse(Graph);
    cout<<endl;
    return 0;
}

void DFS(MGraphAdjList &Graph, int q){
    if(Graph.visited[q])    return;

    Graph.visited[q] = true;
    cout<<Graph.Vertex[q].data<<' ';

    EdgeNode* e = Graph.Vertex[q].firstedge;

    while(e){
        DFS(Graph, e->adjvex);
        e = e->next;
    }
}
void DFSTraverse(MGraphAdjList &Graph){
    for(int q=0; q<Graph.numVertex; q++)
        Graph.visited[q] = false;
    for(int q=0; q<Graph.numVertex; q++){
        if(!Graph.visited[q]){
            DFS(Graph, q);
        }
    }
}

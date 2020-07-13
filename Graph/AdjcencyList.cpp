#include <cstdlib>
#include <iostream>
using namespace std;

constexpr int MAXSIZE = 100;
constexpr int INFINITY = 65535;

using VertexType = char;
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
    VertexNode Vertex[MAXSIZE];
    int numEdge, numVertex;
}MGraphAdjList;

int main(){
    MGraphAdjList Graph;
    cin>>Graph.numVertex>>Graph.numEdge;
    for(int q=0; q<Graph.numVertex; q++){
        cin>>Graph.Vertex[q].data;
        Graph.Vertex[q].firstedge = nullptr;
    }
    for(int q=0; q<Graph.numEdge; q++){
        int i, j, weight;
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

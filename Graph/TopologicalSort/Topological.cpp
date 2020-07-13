#include <cstdlib>
#include <stack>
#include <iostream>
using namespace std;

constexpr int MAXSIZE = 100;
constexpr int INFINITY = 65535;

using VertexType = char;
using EdgeType = int;

struct EdgeNode{
    int adjvex;
    EdgeNode* next;
};

typedef struct{
    int in = 0;
    VertexType data;
    EdgeNode* firstedge;
}VertexNode;

typedef struct{
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
        int i, j;
        cout<<"enter the tail and the head of each Edge."<<endl;
        cin>>i>>j;

        Graph.Vertex[j].in++;

        EdgeNode* e;
        e = (EdgeNode*)malloc(sizeof(EdgeNode));

        e->next = Graph.Vertex[i].firstedge;
        e->adjvex = j;
        Graph.Vertex[i].firstedge = e;
    }
}

void Topological(MGraphAdjList &Graph){
    stack<VertexNode> V;
    bool visited[MAXSIZE] = {0};
    int count = 0;
    while(count != Graph.numVertex){
        for(int q=0; q<Graph.numVertex; q++){
            if(!Graph.Vertex[q].in && !visited[q]){
                visited[q] = true;
                V.push(Graph.Vertex[q]);
            }
        }
        while(!V.empty()){
            cout<<V.top().data<<' ';
            EdgeNode* next = V.top().firstedge;
            while(next != nullptr){
                --Graph.Vertex[next->adjvex].in;
                next = next->next;
            }
            V.pop();
            ++count;
        }
        cout<<endl;
    }
}

int main(){
    MGraphAdjList Graph;
    Init_Graph(Graph);
    Topological(Graph);
    return 0;
}

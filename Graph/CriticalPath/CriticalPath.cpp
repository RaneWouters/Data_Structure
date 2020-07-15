#include <cstdlib>
#include <stack>
#include <iostream>
using namespace std;

constexpr int MAXSIZE = 100;
constexpr int INFINITY = 65535;

using VertexType = char;
using EdgeType = int;

int etv[MAXSIZE] = {0};     //earlist time on vertex.
int ltv[MAXSIZE] = {0};     //latest time on vertex.
int ete[MAXSIZE] = {0};     //earlist time on edge.
int lte[MAXSIZE] = {0};     //latest time on edge.

struct EdgeNode{
    int adjvex;
    int weight;
    EdgeNode* next;
};

typedef struct{
    int in = 0;
    int subscript;
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
        Graph.Vertex[q].subscript = q;
        Graph.Vertex[q].firstedge = nullptr;
    }
    for(int q=0; q<Graph.numEdge; q++){
        int i, j, weight;
        cout<<"enter the tail and the head of each Edge."<<endl;
        cin>>i>>j>>weight;

        Graph.Vertex[j].in++;

        EdgeNode* e;
        e = (EdgeNode*)malloc(sizeof(EdgeNode));

        e->next = Graph.Vertex[i].firstedge;
        e->weight = weight;
        e->adjvex = j;
        Graph.Vertex[i].firstedge = e;
    }
}

void Topological(MGraphAdjList &Graph, stack<int> &Topo){
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
            EdgeNode* k = V.top().firstedge;
            while(k != nullptr){
                --Graph.Vertex[k->adjvex].in;
                if((etv[V.top().subscript] + k->weight) > etv[k->adjvex]){
                    etv[k->adjvex] = etv[V.top().subscript] + k->weight;
                }
                k = k->next;
            }
            Topo.push(V.top().subscript);
            V.pop();
            ++count;
        }
        cout<<endl;
    }
}

void CriticalPath(MGraphAdjList &Graph){
    stack<int> Topo;
    Topological(Graph, Topo);
    for(int q=0; q<Graph.numVertex; q++){
        ltv[q] = etv[Graph.numVertex - 1];
    }
    while(!Topo.empty()){
        EdgeNode* k = Graph.Vertex[Topo.top()].firstedge;
        while(k != nullptr){
            if(ltv[Topo.top()] > (ltv[k->adjvex] - k->weight)){
                ltv[Topo.top()] = ltv[k->adjvex] - k->weight;
            }
            k = k->next;
        }
        Topo.pop();
    }
    for(int q=0; q<Graph.numVertex; q++){
        EdgeNode* k = Graph.Vertex[q].firstedge;
        while(k != nullptr){
            int ete = etv[q];
            int lte = ltv[k->adjvex] - k->weight;
            if(ete == lte){
                printf("(%c, %c) %d\n", Graph.Vertex[q].data,
                        Graph.Vertex[k->adjvex].data, lte);     //print the latest start time of each activity.
            }
            k = k->next;
        }
    }
}

int main(){
    MGraphAdjList Graph;
    Init_Graph(Graph);
    CriticalPath(Graph);
    return 0;
}

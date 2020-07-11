#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXSIZE = 100;
constexpr int MAXEDGE = 100;
constexpr int INFINITY = 65535;

using VertexType = char;
using EdgeType = int;

typedef struct{
    VertexType Vertex[MAXSIZE] = {0};
    EdgeType Edge[MAXSIZE][MAXSIZE];
    int numVertex, numEdge;
}MGraph;

typedef struct{
    int begin;
    int end;
    int weight;
}Edge;

void Init_Graph(MGraph &Graph){
    cout<<"enter the number of Vertex and the number of Edge."<<endl;
    cin>>Graph.numVertex>>Graph.numEdge;
    cout<<"enter the name of each Vertex."<<endl;
    for(int q=0; q<Graph.numVertex; q++){
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

bool compare(const Edge &A, const Edge &B){
    return A.weight <B.weight;
}

int Find(int (&parent)[MAXSIZE], int q){
    while(parent[q])
        q = parent[q];
    return q;
}

void Kruskal(MGraph &Graph){
    Edge e[MAXEDGE];
    int parent[MAXSIZE] = {0};
    int count = 0;
    for(int q=0; q<Graph.numVertex; q++){
        for(int i=q+1; i<Graph.numVertex; i++){
            if(Graph.Edge[q][i] && Graph.Edge[q][i] < INFINITY){
                e[count].begin = q;
                e[count].end = i;
                e[count].weight = Graph.Edge[q][i];
                count++;
            }
        }
    }
    sort(e, e+count, compare);

    for(int q=0; q<count; q++){
        int m = Find(parent, e[q].begin);
        int n = Find(parent, e[q].end);
        if(n != m){
            parent[m] = n;
            printf("(%c, %c) %d\n", Graph.Vertex[e[q].begin],
                    Graph.Vertex[e[q].end], e[q].weight);
        }
    }
}

int main(){
    MGraph Graph;
    Init_Graph(Graph);
    Kruskal(Graph);
    return 0;
}

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

void Prim(MGraph &Graph){
    int weight[MAXSIZE] = {0};
    int adjvex[MAXSIZE] = {0};
    for(int q=1; q<Graph.numVertex; q++){
        weight[q] = Graph.Edge[0][q];
    }

    for(int q=1; q<Graph.numVertex; q++){
        int MIN_weight = INFINITY;
        int j = 1, k = 0;       //j is the subscript of vertex
                                //the k is the subscript of the
                                //minimium weight vertex
        while(j < Graph.numVertex){
            if(weight[j] && weight[j] < MIN_weight){
                MIN_weight = weight[j];
                k = j;
            }
            j++;
        }
        printf("(%c, %c)", Graph.Vertex[adjvex[k]], Graph.Vertex[k]);
        weight[k] = 0;

        for(j=1; j<Graph.numVertex; j++){
            if(weight[j] && weight[j] > Graph.Edge[k][j]){
                weight[j] = Graph.Edge[k][j];
                adjvex[j] = k;
            }
        }
    }
}

int main(){
    MGraph Graph;
    Init_Graph(Graph);
    Prim(Graph);
    cout<<endl;
    return 0;
}

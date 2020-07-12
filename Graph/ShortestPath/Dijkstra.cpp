#include <iostream>
#include <queue>
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

void Dijkstra(MGraph &Graph){
    bool visited[MAXSIZE] = {0};
    int parent[MAXSIZE] = {0};
    int distance[MAXSIZE];
    for(int q=0; q<Graph.numVertex; q++){
        distance[q] = Graph.Edge[0][q];
    }
    visited[0] = true;

    for(int q=1; q<Graph.numVertex; q++){
        int MIN_distance = INFINITY;
        int j = 1, k = 0;   //j is the subscript of vertex
                            //the k is the subscript of the
                            //minimium weight vertex
        while(j < Graph.numVertex){
            if(!visited[j] && distance[j] < MIN_distance){
                MIN_distance = distance[j];
                k = j;
            }
            j++;
        }
        visited[k] = true;
        printf("%c %d\n", Graph.Vertex[k], distance[k]);
        for(j=1; j<Graph.numVertex; j++){
            if((distance[j] > (MIN_distance+Graph.Edge[k][j]))
                    && !visited[j]){
                distance[j] = Graph.Edge[k][j] + MIN_distance;
                parent[j] = k;
            }
        }
    }
}

int main(){
    MGraph Graph;
    Init_Graph(Graph);
    Dijkstra(Graph);
    return 0;
}

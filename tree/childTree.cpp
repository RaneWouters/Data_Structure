#include<iostream>
using namespace std;

typedef int Elemtype;

const int MAX_TREE_SIZE = 100;

typedef struct Node{
    struct Node *next;
    Elemtype data;
}*NodePtr;
typedef struct{
    Elemtype data;
    int parent_location;
    NodePtr firstchild;
}Title;
typedef struct{
    Title nodes[MAX_TREE_SIZE];
    int root_location;
    int nodes_number;
}ChildTree;

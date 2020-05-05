#include <cstddef>
#include <cstdlib>
#include <ctime>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;
typedef int Status;
void Init_LinkList_Head(LinkList *L, int n){     //头插法
    LinkList p;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(struct Node));
    (*L)->next = NULL;
    for(int i=0; i<n; ++i){
        p = (LinkList)malloc(sizeof(struct Node));
        p->next = (*L)->next;
        p->data = rand()%100+1;
        (*L)->next = p;
    }
}
void Init_LinkList_Tail(LinkList *L, int n){    //尾插法
    LinkList p, r;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(struct Node));
    r = *L;
    for(int i=0; i<=n; ++i){
        p = (LinkList)malloc(sizeof(struct Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
Status Clear_LinkList(LinkList *L){     //清除链表
    LinkList p, q;
    p = (*L)->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return 1;
}
Status Get_elem(LinkList *L, int i, ElemType *e){       //获取某位置的data
    int j=1;
    LinkList p;
    p = (*L)->next;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p || j!=i){
        return 0;
    }
    *e = p->data;
    return 1;
}
Status Insert_LinkList(LinkList *L, int i, ElemType e){
    int j=1;
    LinkList p,s;
    p = *L;
    while(p && j<i){
        ++j;
        p = p->next;
    }
    if(!p || j!=i){
        return 0;
    }
    s = (LinkList)malloc(sizeof(struct Node));
    s->data = e;

    p->next = s;
    return 1;
}
Status Delete_LinkList(LinkList *L, int i, ElemType *e){
    LinkList p, r;
    int j=1;
    p = *L;
    while(p && j<i){
        ++j;
        p = p->next;
    }
    if(!p || j!=i){
        return 0;
    }
    r = p->next;
    p->next = r->next;
    *e = r->data;
    free(r);
    return 1;
}
int main(){

    return 0;
}

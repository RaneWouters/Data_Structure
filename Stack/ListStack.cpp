#include <cstdlib>
#include<iostream>
#include <type_traits>
using namespace std;
typedef int Status;
typedef int ElemType;

constexpr int ERROR = 0;
constexpr int OK = 1;

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;
typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;
Status Empty(LinkStack *S){
    if(S->count == 0)
        return OK;
    return ERROR;
}
Status Push(LinkStack *S, ElemType e){
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;

    S->top = s;
    S->count++;
    return OK;
}
Status Pop(LinkStack *S, ElemType *e){
    if(Empty(S))
        return ERROR;
    *e = S->top->data;
    LinkStackPtr p;
    p = S->top;
    S->top = p->next;
    S->count--;
    free(p);
    return OK;
}

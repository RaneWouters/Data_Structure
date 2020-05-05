#include<iostream>
using namespace std;
typedef int Status;
typedef int ElemType;

constexpr int ERROR = 0;
constexpr int OK = 1;
constexpr int MAXSIZE = 100;

typedef struct SqDoubleStack{
    ElemType data[MAXSIZE];
    int top1 = 0;
    int top2 = MAXSIZE-1;
}SqDoubleStack;
Status Push(SqDoubleStack *S, ElemType e, int StackNumber){
    if(S->top1+1 == S->top2)
        return ERROR;
    switch(StackNumber){
        case 1:
            S->data[++S->top1] = e;
            break;
        case 2:
            S->data[--S->top2] = e;
            break;
        default:
            return ERROR;
    }
    return OK;
}
Status Pop(SqDoubleStack *S, ElemType *e, int StackNumber){
    switch(StackNumber){
        case 1:
            if(S->top1 == -1)
                return ERROR;
            *e = S->data[S->top1--];
            break;
        case 2:
            if(S->top2 == MAXSIZE)
                return ERROR;
            *e = S->data[S->top2++];
            break;
        default:
            return ERROR;
    }
    return OK;
}

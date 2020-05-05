#include<iostream>
using namespace std;
typedef int ElemType;
typedef int Status;
constexpr int MAXSIZE = 100;
constexpr int ERROR = 0;
constexpr int OK = 1;
typedef struct SqStack{
    int top=0;
    ElemType data[MAXSIZE];
}SqStack;
Status Push(SqStack *S, ElemType e){
    if(S->top == MAXSIZE-1)
        return ERROR;
    S->top++;
    S->data[S->top] = e;
    return OK;
}
Status Pop(SqStack *S, ElemType *e){
    if(S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}
int main(){
    return 0;
}

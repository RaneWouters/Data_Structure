#include <cstddef>
#include <cstdlib>
#include<iostream>
#include <type_traits>
using namespace std;
typedef int Status;
typedef char ElemType;

constexpr int ERROR = 0;
constexpr int OK = 1;

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;
typedef struct LinkStack{
    LinkStackPtr top;
    int count = 0;
}LinkStack;
Status Empty(LinkStack S){
    if(S.count == 0)
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
    if(Empty(*S))
        return ERROR;
    *e = S->top->data;
    LinkStackPtr p;
    p = S->top;
    S->top = S->top->next;
    S->count--;
    free(p);
    return OK;
}
void ReversePolish(LinkStack *S, char equation[]){
    int location = 0;
    char temp = 0;
    while(equation[location] != '\0'){
        int flag = 0;
        while(equation[location]>='0' && equation[location]<='9'){
            cout<<equation[location++];
            flag = 1;
        }
        if(flag == 1)    cout<<' ';
        if(equation[location]=='+' || equation[location]=='-'){
            if(Empty(*S))
                Push(S, equation[location++]);
            else{
                do{
                    Pop(S, &temp);
                    if(temp == '(')
                        Push(S, temp);
                    else
                        cout<<temp<<' ';
                }while(!Empty(*S) && temp!='(');
                Push(S, equation[location++]);
            }
        }
        else if(equation[location]=='*' || equation[location]=='/' || equation[location]=='('){
            Push(S, equation[location++]);
        }
        else if(equation[location]==')'){
            location++;
            Pop(S, &temp);
            while(temp != '(' && !Empty(*S)){
                cout<<temp<<' ';
                Pop(S, &temp);
            }
        }
    }
    while(!Empty(*S)){
        Pop(S, &temp);
        cout<<temp<<' ';
    }
}
int main(){
    char equation[100] = {0};
    cin>>equation;
    LinkStack S;
    ReversePolish(&S, equation);
    cout<<endl;
    return 0;
}

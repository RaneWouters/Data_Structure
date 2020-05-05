#include<iostream>
using namespace std;
typedef int ElemType;
typedef int Status;

constexpr int MAXSIZE = 100;
constexpr int OK = 1;
constexpr int ERROR = 0;
typedef struct SqQueue{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;
Status InitQueue(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
Status QueueLength(SqQueue *Q){
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}
Status QueueFull(SqQueue *Q){
    if((Q->rear+1)%MAXSIZE == Q->front)
        return OK;
    return ERROR;
}
Status QueueEmpty(SqQueue *Q){
    if(Q->front == Q->rear)
        return OK;
    return ERROR;
}
Status EnterQueue(SqQueue *Q, ElemType e){      //add the ElemType data to Queue
    if(QueueFull(Q)){
        cout<<"ERROR command!";
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return OK;
}
Status PopQueue(SqQueue *Q, ElemType *e){       //delete the ElemType data from the Queue
    if(QueueEmpty(Q)){
        cout<<"ERROR command!";
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return OK;
}
int main(){
    SqQueue Q;
    InitQueue(&Q);
    for(int q=1; q<=9; q++){
        EnterQueue(&Q, q);
    }
    for(int q=1; q<=9; q++){
        int temp;
        PopQueue(&Q, &temp);
        cout<<temp<<' ';
    }
    cout<<endl;
    return 0;
}

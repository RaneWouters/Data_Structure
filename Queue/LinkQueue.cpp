#include<iostream>
using namespace std;
typedef int ElemType;
typedef int Status;

constexpr int OK = 1;
constexpr int ERROR = 0;

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QNodePtr;
typedef struct LinkQueue{
    QNodePtr front, rear;
}LinkQueue;
Status InitQueue(LinkQueue *Q){
    if(!Q)
        return ERROR;
    QNodePtr node = (QNodePtr)malloc(sizeof(QNode));
    node->next = NULL;
    Q->front = Q->rear = node;
    return OK;
}
Status EnterQueue(LinkQueue *Q, ElemType e){
    if(!Q)
        return ERROR;
    QNodePtr s = (QNodePtr)malloc(sizeof(QNode));
    if(!s)
        return ERROR;
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return OK;
}
Status PopQueue(LinkQueue *Q, ElemType *e){
    if(!Q || Q->front == Q->rear)
        return ERROR;
    QNodePtr temp = Q->front->next;
    Q->front->next = temp->next;
    *e = temp->data;
    if(temp == Q->rear)
        Q->rear = Q->front;
//出队元素位置和队尾重合时，意味着队列内元素全部清除
//于是令队尾位置等于队首位置
//由于temp和rear位置相同，而temp的内存要被释放
//所以不可以令 front = rear
    free(temp);
    return OK;
}
Status QueueEmpty(LinkQueue *Q){
    if(!Q)
        return ERROR;
    if(Q->front == Q->rear)
        return OK;
    return ERROR;
}
Status QueueLength(LinkQueue *Q){
    if(!Q)
        return ERROR;
    if(Q->front == Q->rear)
        return 0;
    QNodePtr node = Q->front->next;
    int count = 0;
    while(node){
        count++;
        node = node->next;
    }
    return count;
}
int main(){
    LinkQueue Q;
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

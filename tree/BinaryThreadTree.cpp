#include<cstdlib>
#include<iostream>
using namespace std;

typedef char Elemtype;

typedef enum{link, thread} PointerTag;

typedef struct Node{
    Elemtype data;
    PointerTag ltag;
    PointerTag rtag;
    struct Node *lchild=nullptr;
    struct Node *rchild=nullptr;
}BinaryTreeNode, *BinaryTreeNodePtr;

//前序插入构造二叉树
// "#" means nullptr;
void CreateBinaryTree_PreOrder(BinaryTreeNode *&T){
    Elemtype temp;
    cin>>temp;
    if(temp == '#'){
        T = nullptr;
        return ;
    }else{
        T = (BinaryTreeNodePtr)malloc(sizeof(BinaryTreeNode));
        T->data = temp;
        T->ltag = link;
        T->rtag = link;
    }
    CreateBinaryTree_PreOrder(T->lchild);
    CreateBinaryTree_PreOrder(T->rchild);
}
//中序线索化
//含有头结点
BinaryTreeNodePtr pre = nullptr;
void InOrderThreading(BinaryTreeNode *T){
    if(T == nullptr)
        return ;
    InOrderThreading(T->lchild);
    if(T->lchild == nullptr){
        T->ltag = thread;
        T->lchild = pre;
    }
    if(pre!=nullptr){
        if(pre->rchild == nullptr){
            pre->rtag = thread;
            pre->rchild = T;
        }
    }
    pre = T;
    InOrderThreading(T->rchild);
}
void InOrderThreading_Head(BinaryTreeNodePtr &head, BinaryTreeNode *T){
    head = (BinaryTreeNodePtr)malloc(sizeof(BinaryTreeNode));
    head->lchild = T;
    pre = head;
    InOrderThreading(T);
    head->rchild = pre;
    pre->rchild = head;
    head->ltag = thread;
    head->rtag = thread;
}
//中序遍历线索树
//相当于链表的遍历
void InOrderTraverse_Thread(BinaryTreeNode *T){
    BinaryTreeNodePtr p;
    p = T->lchild;
    while(p != T){
        while(p->ltag == link){
            p = p->lchild;
        }
        cout<<p->data<<' ';
        while(p->rtag==thread && p->rchild!=T){
            p = p->rchild;
            cout<<p->data<<' ';
        }
        p = p->rchild;
    }
}
int main(){
    BinaryTreeNode *T = (BinaryTreeNodePtr)malloc(sizeof(BinaryTreeNode));
    CreateBinaryTree_PreOrder(T);
    BinaryTreeNodePtr head;
    InOrderThreading_Head(head, T);
    InOrderTraverse_Thread(head);   //head成为线索树新的顶端
    cout<<endl;
    return 0;
}

#include<cstdlib>
#include<iostream>
using namespace std;

typedef char Elemtype;
typedef enum {link, thread} PointerTag;

typedef struct Node{
    Elemtype data;
    PointerTag ltag;
    PointerTag rtag;
    struct Node *lchild=nullptr;
    struct Node *rchild=nullptr;
}BinaryTreeNode, *BinaryTreeNodePtr;

//前序插入构造二叉树
// "#" means NULL;
void CreateBinaryTree_PreOrder(BinaryTreeNode *&T){
    Elemtype temp;
    cin>>temp;
    if(temp == '#'){
        T = nullptr;
        return ;
    }else{
        T = (BinaryTreeNodePtr)malloc(sizeof(BinaryTreeNode));
        T->data = temp;
    }
    CreateBinaryTree_PreOrder(T->lchild);
    CreateBinaryTree_PreOrder(T->rchild);
}
//中序线索化
//含有头结点
BinaryTreeNodePtr pre = nullptr;
void InOrderTraverse_Thread(BinaryTreeNode *T){
    if(T == NULL)
        return ;
    InOrderTraverse_Thread(T->lchild);
    if(T->lchild == NULL){
        T->ltag = thread;
        T->lchild = pre;
    }
    if(pre!=NULL){
        if(pre->rchild == NULL){
            pre->rtag = thread;
            pre->rchild = T;
        }
    }
    pre = T;
    InOrderTraverse_Thread(T->rchild);
}
void InOrderTraverse_Thread_Head(BinaryTreeNodePtr &head, BinaryTreeNode *T){
    head = (BinaryTreeNodePtr)malloc(sizeof(BinaryTreeNode));
    head->lchild = T;
    pre = head;
    InOrderTraverse_Thread(T);
    head->rchild = pre;
    pre->rchild = head;
}
int main(){
    BinaryTreeNode *T = (BinaryTreeNodePtr)malloc(sizeof(BinaryTreeNode));
    CreateBinaryTree_PreOrder(T);
    BinaryTreeNodePtr head;
    InOrderTraverse_Thread_Head(head, T);
    cout<<endl;
    return 0;
}

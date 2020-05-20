#include<cstdlib>
#include<queue>
#include<iostream>
#include<stack>
using namespace std;

typedef char Elemtype;

typedef struct Node{
    Elemtype data;
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
    }
    CreateBinaryTree_PreOrder(T->lchild);
    CreateBinaryTree_PreOrder(T->rchild);
}

//前序遍历
void PreOrderTraverse(BinaryTreeNode *T){
    if(T == nullptr)
        return ;
    cout<<T->data<<' ';
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
//中序遍历
void InOrderTraverse(BinaryTreeNode *T){
    if(T == nullptr)
        return ;
    InOrderTraverse(T->lchild);
    cout<<T->data<<' ';
    InOrderTraverse(T->rchild);
}
//后序遍历
void PostOrderTraverse(BinaryTreeNode *T){
    if(T == nullptr)
        return ;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout<<T->data<<' ';
}
//中序非递归遍历
void InOrderTraverse_NoRecursion(BinaryTreeNode *T){
    stack<BinaryTreeNode>node_stack;
    BinaryTreeNodePtr p = T;
    while(p || !node_stack.empty()){
        if(p){
            node_stack.push(*p);
            p = (*p).lchild;
        }else{
            BinaryTreeNode temp;
            temp = node_stack.top();
            node_stack.pop();
            cout<<temp.data<<' ';
            p = temp.rchild;
        }
    }
}
//层序遍历
void LevelOrderTraverse(BinaryTreeNode *T){
    queue <BinaryTreeNode>node_queue;
    node_queue.push(*T);
    while(!node_queue.empty()){
        BinaryTreeNode temp;
        temp = node_queue.front();
        node_queue.pop();
        cout<<temp.data<<' ';
        if(temp.lchild) node_queue.push(*temp.lchild);
        if(temp.rchild) node_queue.push(*temp.rchild);
    }
}
int main(){
    BinaryTreeNode *T = (BinaryTreeNodePtr)malloc(sizeof(BinaryTreeNode));
    CreateBinaryTree_PreOrder(T);

    cout<<endl;
    return 0;
}

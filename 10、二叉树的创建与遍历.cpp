#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef char ElemType;


typedef struct BiNode {
    ElemType data;
    struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

//先序创建二叉树
void CreateBiTree(BiTree &T) {
    ElemType ch;
    cin >> ch;
    if(ch == '#')
        T = NULL;
    else {
        T = new BiNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

//先序遍历二叉树
void PreOrderTraverse(BiTree T) {
    if(T) {
        cout << T->data << ' ';
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//中序遍历二叉树
void InOrderTraverse(BiTree T) {
    if(T) {
        InOrderTraverse(T->lchild);
        cout << T->data << ' ';
        InOrderTraverse(T->rchild);
    }
}

//后序遍历二叉树
void PostOrderTraverse(BiTree T) {
    if(T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << ' ';
    }
}

//层次遍历二叉树
void LevelOrderTraverse(BiTree T) {
    BiTree q[100];
    int front=0, rear=0;
    if(T) {
        q[rear++] = T;
        while(front != rear) {
            BiTree now = q[front++];
            cout << now->data << ' ';
            if(now->lchild)
                q[rear++] = now->lchild;
            if(now->rchild)
                q[rear++] = now->rchild;
        }
    }
}

//销毁二叉树
void DestroyBiTree(BiTree &T) {
    if(T) {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
    }
}

int main()
{
    BiTree T;
    CreateBiTree(T);
    cout << "先序遍历：";
    PreOrderTraverse(T);
    cout << "\n中序遍历：";
    InOrderTraverse(T);
    cout << "\n后序遍历：";
    PostOrderTraverse(T);
    cout << "\n层次遍历：";
    LevelOrderTraverse(T);
    DestroyBiTree(T);
    return 0;
}

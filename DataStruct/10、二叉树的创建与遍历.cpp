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

//计算二叉树深度
int Depth(BiTree T) {
    int m, n;
    if(T == NULL)
        return 0;
    else {
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        return (m>n)?(m+1):(n+1);
    }
}

//计算二叉树的结点总数
int NodeCount(BiTree T) {
    if(T == NULL)
        return 0;
    else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
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
    //测试样例
    //a#b#cdef#####
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
    cout << "\n二叉树的深度为：" << Depth(T);
    cout << "\n二叉树的结点总数为：" << NodeCount(T);
    DestroyBiTree(T);
    return 0;
}

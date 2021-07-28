#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int ElemType;

typedef struct BSTNode {
    ElemType data;
    BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

//建立二叉排序树
void InsertBST(BSTree &T, ElemType e) {
    if(!T) {
        T = new BSTNode;
        T->data = e;
        T->lchild = T->rchild = NULL;
    }else if(e < T->data) {
        InsertBST(T->lchild, e);
    }else if(e > T->data) {
        InsertBST(T->rchild, e);
    }
}

//二叉排序树查找
bool SearchBST(BSTree T, ElemType key) {
    if(!T)
        return false;
    else if(T->data == key)
        return true;
    else if(key < T->data)
        SearchBST(T->lchild, key);
    else if(key > T->data)
        SearchBST(T->rchild, key);
}

int main()
{
    int m, n;       //二叉排序树元素个数及查找次数
    ElemType key;   //二叉排序树元素
    BSTree T = NULL;
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        cin >> key;
        InsertBST(T, key);
    }
    for(int i=0; i<n; i++) {
        cin >> key;
        cout << (SearchBST(T, key)?"True":"False") << ' ';
    }
    return 0;
}

//测试数据
//8 3
//1 3 5 7 8 9 10 15

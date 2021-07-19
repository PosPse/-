#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
typedef int ElemType;
typedef int Status;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//后插法创建单链表
void CreateList_R(LinkList &L, int n){
    L = new LNode;
    L->next = NULL;
    LNode *r = L;
    for(int i=0; i<n; i++){
        LNode *p = new LNode;
        p->data = i;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//后插法创建循环链表
void CreateCircleList_R(LinkList &L, int n){
    L = new LNode;
    L->next = L;
    LNode *r = L;
    for(int i=0; i<n; i++){
        LNode *p = new LNode;
        p->data = i;
        p->next = L;
        r->next = p;
        r = p;
    }
}

//单链表遍历
void ListPrint(LinkList L){
    LinkList p;
    for(p = L->next; p; p=p->next){
        cout << p->data << (p->next?' ':'\n');
    }
}

//循环链表遍历
void CircleListPrint(LinkList L){
    LinkList p;
    for(p = L->next; p && p != L; p=p->next){
        cout << p->data << (p->next?' ':'\n');
    }
}
int main()
{
    LinkList L1, L2;
    cout << "单链表创建与遍历：" << endl;
    CreateList_R(L1, 10);
    ListPrint(L1);
    cout << "循环链表创建与遍历：" << endl;
    CreateCircleList_R(L2, 10);
    CircleListPrint(L2);
    return 0;
}

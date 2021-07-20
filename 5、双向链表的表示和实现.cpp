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

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

//后插法创建双向链表
void CreateDuList_R(DuLinkList &L, int n){
    L = new DuLNode;
    L->prior = NULL;
    L->next = NULL;
    DuLinkList r = L;
    for(int i=0; i<n; i++) {
        DuLinkList p = new DuLNode;
        p->data = i;
        p->next = NULL;
        p->prior = r;
        r->next = p;
        r = p;
    }
}

//双向链表next方向遍历
void DuListPrint_Next(DuLinkList L) {
    DuLinkList p;
    for(p = L->next; p; p=p->next){
        cout << p->data << (p->next?' ':'\n');
    }
}

//双向链表prior方向遍历
void DuListPrint_Prior(DuLinkList L) {
    DuLinkList p = L;
    while(p->next){
        p = p->next;
    }
    for(p; p && p->prior; p=p->prior){
        cout << p->data << (p->prior->prior?' ':'\n');
    }
}

//双向链表元素插入
Status ListInsert_DuL(DuLinkList L, int i, ElemType e) {
    DuLinkList p = L, s;
    int j = 0;
    while(p && j<i) {
        p = p->next;
        j++;
    }
    s = new DuLNode;
    s->data = e;
    s->prior = p->prior;
    s->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

//双向链表元素删除
Status ListDelete_DuL(DuLinkList L, int i, ElemType &e) {
    DuLinkList p = L;
    int j = 0;
    while(p && j<i) {
        p = p->next;
        j++;
    }
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return OK;
}

int main()
{
    DuLinkList L;
    string op;
    int i;
    ElemType e;
    cout << "双向链表创建：" << endl;
    CreateDuList_R(L, 10);
    cout << "双向链表next方向遍历：" << endl;
    DuListPrint_Next(L);
    cout << "双向链表prior方向遍历：" << endl;
    DuListPrint_Prior(L);
    while(cin >> op) {
        if(op == "Insert"){
            cin >> i >> e;
            if(ListInsert_DuL(L, i, e) == ERROR){
                cout << "Insert failed" << endl;
            }
            else {
                cout << "双向链表next方向遍历：" << endl;
                DuListPrint_Next(L);
                cout << "双向链表prior方向遍历：" << endl;
                DuListPrint_Prior(L);
            }
        }else if(op == "Delete"){
            cin >> i;
            if(ListDelete_DuL(L, i, e) == ERROR){
                 cout << "Delete failed" << endl;
            }else {
                cout << "双向链表next方向遍历：" << endl;
                DuListPrint_Next(L);
                cout << "双向链表prior方向遍历：" << endl;
                DuListPrint_Prior(L);
            }
        }
    }
    return 0;
}

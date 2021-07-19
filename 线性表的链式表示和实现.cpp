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

//构造一个空的链表L
Status InitList(LinkList &L){
    L = new LNode;
    L->next = NULL;
    return OK;
}

//单链表L销毁
Status DestroyList(LinkList &L){
    LinkList p;
    while(L){
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}

//判断单链表L是否为空
bool ListEmpty(LinkList L){
    return L->next == NULL;
}

//求单链表L的长度
int ListLength(LinkList L){
    int len = 0;
    LinkList p = L->next;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

//取单链表中第i个数据元素的值
Status GetElem(LinkList L, int i, ElemType &e){
    LinkList p = L->next;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j>i) return ERROR;
    e = p->data;
    return OK;
}

//单链表的查找
int LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    int i = 1;
    while(p && p->data != e){
        p = p->next;
        i++;
        if(i > ListLength(L))return 0;
    }
    return i;
}

//单链表插入
Status ListInsert(LinkList &L, int i, ElemType e){
    LinkList p = L, s;
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        j++;
    }
    s =  new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//单链表删除
Status ListDelete(LinkList &L, int i){
    LinkList p = L, q;
    int j = 0;
    while(p->next && j<i-1){
        p = p->next;
        j++;
    }
    if(!p->next || j>i-1){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

//单链表遍历
void ListPrint(LinkList L){
    LinkList p;
    for(p = L->next; p; p=p->next){
        cout << p->data << (p->next?' ':'\n');
    }
}
int main()
{
    int i;
    ElemType e;
    LinkList L;
    string op;
    InitList(L);
    while(cin >> op){
        if(op == "Empty"){
            cout << (ListEmpty(L)?"Empty":"Not empty") << endl;
        }else if(op == "Length"){
            cout << "List length is " << ListLength(L) << endl;
        }else if(op == "Insert"){
            cin >> i >> e;
            if(ListInsert(L, i, e) == ERROR)
                cout << "Insert failed" << endl;
            else ListPrint(L);
        }else if(op == "GetElem"){
            cin >> i;
            if(GetElem(L, i, e) == ERROR)
                cout << "Out of index" << endl;
            else cout << "The elem at position " << i << "is " << e << endl;
        }else if(op == "LocateElem"){
            cin >> e;
            i = LocateElem(L, e);
            if(i == 0)
                cout << e << " is not found in list" << endl;
            else
                cout << e << " is found at the position " << i << endl;
        }else if(op == "Delete"){
            cin >> i;
            if(ListDelete(L, i) == ERROR)
                cout << "Delete failed" << endl;
            else ListPrint(L);
        }else if(op == "ListPrint"){
            ListPrint(L);
        }
    }
    DestroyList(L);
    return 0;
}

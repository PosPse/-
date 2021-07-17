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

typedef struct {
    ElemType *elem;
    int length;
}Sqlist;

//构造一个空的线性表L
Status InitList(Sqlist &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)exit(OVERFLOW);
    L.length = 0;
    return OK;
}

//创造线性表L
Status CreateList(Sqlist &L) {
    //5 7 9 1 0 2 8 6 3 4
    int n;
    cout << "输入元素个数：";
    cin >> n;
    L.length = n;
    cout << "依次输入：";
    for(int i=0; i<n; i++) {
        cin >>L.elem[i];
    }
    return OK;
}

//输出线性表L
void PrintList(Sqlist L) {
    for(int i=0; i<L.length; i++) {
        cout << L.elem[i] << ' ';
    }
    cout << endl;
}

//销毁线性表L
void DestroyList(Sqlist &L) {
    if(L.elem) delete []L.elem;
}

//L为空表，则返回TRUE，否则返回FALSE
bool ListEmpty(Sqlist L) {
    return L.length == 0;
}

//返回L中元素的个数
int ListLength(Sqlist L) {
    return L.length;
}

//用e返回L中的第i个元素
Status GetList(Sqlist L, int i, ElemType &e) {
    if(i<1 || i>L.length) return ERROR;
    e = L.elem[i - 1];
    return OK;
}

//返回L中第1个与e相同元素的位置；若这样的元素不存在，则返回0
int LocateElem(Sqlist L, ElemType e) {
    for(int i=0; i<L.length; i++) {
        if(L.elem[i] == e) return i+1;
    }
    return 0;
}

//在L的第i个元素之前插入新的元素e，L的长度增1
Status ListInsert(Sqlist &L, int i, ElemType e) {
    if(i<1 || i>L.length+1) return ERROR;
    if(L.length == LIST_INIT_SIZE) return ERROR;
    for(int j=L.length-1; j>=i-1; j--) {
        L.elem[j+1] = L.elem[j];
    }
    L.elem[i-1] = e;
    L.length++;
    return OK;
}

//删除L的第i个元素，并用e返回其值，L的长度减1
Status ListDelete(Sqlist &L, int i, ElemType &e) {
    if(i < 1 || i > L.length) return ERROR;
    e = L.elem[i-1];
    for(int j=i; j<=L.length; j++) {
        L.elem[j-1] = L.elem[j];
    }
    L.length--;
    return OK;
}
int main()
{
    Sqlist L;
    ElemType e;
    int i;
    InitList(L);
    CreateList(L);
    PrintList(L);
    cout << "L是否为空：" << ListEmpty(L) << endl;
    cout << "L长度：" << ListLength(L) << endl;
    cout << "输入第几个元素：" ;
    cin >> i;
    GetList(L, i, e);
    cout << "第" << i << "个元素为：" << e << endl;
    cout << "输入需要查找的元素：" ;
    cin >> e;
    cout << "查找" << e << "的位置：" << LocateElem(L, e) << endl;
    cout << "输入插入位置和插入的元素：";
    cin >> i >> e;
    ListInsert(L, i, e);
    PrintList(L);
    cout << "输入删除元素的位置：";
    cin >> i;
    ListDelete(L, i, e);
    cout << "删除的元素为：" << e <<endl;
    cout << "删除后L元素个数为：" << L.length <<endl;
    PrintList(L);
    return 0;
}
//5 7 9 1 0 2 8 6 3 4

#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 100
typedef int Status;
typedef int SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

//顺序栈初始化
Status InitStack(SqStack &S) {
    S.base = new SElemType[MAXSIZE];
    if(!S.base) exit(ERROR);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//顺序栈销毁
void DestroyStack(SqStack &S) {
    delete []S.base;
    S.base = S.top = NULL;
    S.stacksize = 0;
}

//顺序栈入栈
Status Push(SqStack &S, SElemType e) {
    if(S.top - S.base == S.stacksize)
        return ERROR;
    *(S.top++) = e;
    return OK;
}

//顺序栈出栈
Status Pop(SqStack &S, SElemType &e) {
    if(S.top == S.base)
        return ERROR;
    e = *(--S.top);
    return OK;
}

//取顺序栈的栈顶元素
SElemType GetTop(SqStack S) {
    if(S.top == S.base) return ERROR;
    return *(S.top - 1);
}

//判断栈是否为空
bool StackEmpty(SqStack S) {
    return S.top == S.base;
}

//求栈的长度
int StackLength(SqStack S) {
    return S.top - S.base;
}

//输出栈元素
void PrintStack(SqStack S) {
    while(S.top != S.base) {
        S.top--;
        cout << *S.top << ' ';
    }
    cout << endl;
}

int main()
{
    SqStack s;
    SElemType e;
    string op;
    InitStack(s);
    while(cin >> op) {
        if(op == "Push") {
            cin >> e;
            if(Push(s, e) == ERROR)
                cout << "Push Failure\n";
            else PrintStack(s);
        }else if(op == "Pop") {
            if(Pop(s, e) == ERROR)
                cout << "Push Failure\n";
            else cout << e << " is poped\n";
        }else if(op == "Empty") {
            cout << (StackEmpty(s)?"empty":"not empty") << endl;
        }else if (op == "GetTop") {
            if(StackEmpty(s))
                cout << "GetTop failure\n";
            else cout << "The top element is " << GetTop(s) << endl;
        }else if(op == "Length") {
            cout << "The length of stack is " << StackLength(s) << endl;
        }else if(op == "Print") {
            PrintStack(s);
        }
     }
    DestroyStack(s);
    return 0;
}

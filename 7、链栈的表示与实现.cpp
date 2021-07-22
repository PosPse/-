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

typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;

//链栈初始化
Status InitStack(LinkStack &s) {
    s = NULL;
    return OK;
}

//链栈销毁
void DestroyStack(LinkStack &s) {
    LinkStack next;
    while(s) {
        next = s->next;
        delete s;
        s = next;
    }
}

//链栈入栈
Status Push(LinkStack &s, SElemType e) {
    LinkStack p = new StackNode;
    p ->data = e;
    p->next = s;
    s = p;
    return OK;
}

//链栈出栈
Status Pop(LinkStack &s, SElemType &e) {
    LinkStack p;
    if(s == NULL) return ERROR;
    e = s->data;
    p = s;
    s = s->next;
    delete p;
    return OK;
}

//取链栈的栈顶元素
SElemType GetTop(LinkStack s) {
    if(s == NULL) return ERROR;
    return s->data;
}

//判断栈是否为空.
bool StackEmpty(LinkStack s) {
    return s == NULL;
}

//求栈的长度
int StackLength(LinkStack s) {
    int len = 0;
    while(s) {
        len++;
        s = s->next;
    }
    return len;
}
//输出栈元素
void PrintStack(LinkStack s) {
    while(s){
        cout << s->data << ' ';
        s = s->next;
    }
    cout << endl;
}
int main()
{
    LinkStack s;
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

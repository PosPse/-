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
typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//链队初始化
Status InitQueue(LinkQueue &q) {
    q.front = q.rear = new QNode;
    q.front->next = NULL;
    return OK;
}

//链队销毁
void DestroyQueue(LinkQueue &q) {
    while(q.front) {
        q.rear = q.front->next;
        delete q.front;
        q.front = q.rear;
    }
}

//判断队列是否为空
bool QueueEmpty(LinkQueue q) {
    return q.front == q.rear;
}

//求队列长度
int QueueLength(LinkQueue q) {
    int len = 0;
    QueuePtr p = q.front->next;
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}

//链队入队
Status EnQueue(LinkQueue &q, QElemType e) {
    QueuePtr p = new QNode;
    p->data = e;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;
    return OK;
}

//链队出队
Status DeQueue(LinkQueue &q, QElemType &e) {
    if(q.front == q.rear)
        return ERROR;
    QueuePtr p = q.front->next;
    e = p->data;
    q.front->next = p->next;
    if(q.rear == p)
        q.rear = q.front;
    delete p;
    return OK;

}

//取链队的头元素
QElemType GetHead(LinkQueue q) {
    return q.front->next->data;
}

//输出队列元素
void PrintQueue(LinkQueue q) {
    QueuePtr p;
    for(p=q.front->next; p; p=p->next){
        cout << p->data << ' ';
    }
    cout << endl;
}

int main()
{
    LinkQueue q;
    QElemType e;
    string op;
    InitQueue(q);
    while(cin >> op) {
        if(op == "EnQueue") {
            cin >> e;
            if(EnQueue(q, e) == ERROR)
                cout << "EnQueue Failure\n";
            else PrintQueue(q);
        }else if(op == "DeQueue") {
            if(DeQueue(q, e) == ERROR)
                cout << "DeQueue Failure\n";
            else cout << e << " is deleted\n";
        }else if(op == "Empty") {
            cout << (QueueEmpty(q)?"empty":"not empty") << endl;
        }else if (op == "GetHead") {
            if(QueueEmpty(q))
                cout << "GetHead failure\n";
            else cout << "The top element is " << GetHead(q) << endl;
        }else if(op == "Length") {
            cout << "The length of queue is " << QueueLength(q) << endl;
        }else if(op == "Print") {
            PrintQueue(q);
        }
     }
    DestroyQueue(q);
    return 0;
}

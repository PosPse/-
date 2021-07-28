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

typedef struct {
    QElemType *base;
    int front;
    int rear;
}SqQueue;

//循环队列初始化
Status InitQueue(SqQueue &q) {
    q.base = new QElemType[MAXSIZE];
    if(!q.base) exit(OVERFLOW);
    q.front = q.rear = 0;
    return OK;
}

//循环队列销毁
void DestroyQueue(SqQueue &q) {
    if(q.base) {
        delete []q.base;
        q.base = NULL;
        q.front = q.rear = 0;
    }
}

//判断队列是否为空
bool QueueEmpty(SqQueue q) {
    return q.front == q.rear;
}

//求循环队列的长度
int QueueLength(SqQueue q) {
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

//循环队列入队
Status EnQueue(SqQueue &q, QElemType e) {
    if((q.rear + 1) % MAXSIZE == q.front)
        return ERROR;
    q.base[q.rear] = e;
    q.rear = (q.rear + 1) % MAXSIZE;
    return OK;
}

//循环队列出队
Status DeQueue(SqQueue &q, QElemType &e) {
    if(q.front == q.rear)
        return ERROR;
    e = q.base[q.front];
    q.front = (q.front + 1) % MAXSIZE;
    return OK;
}

//取循环队列的队头元素
QElemType GetHead(SqQueue q) {
    return q.base[q.front];
}

//输出循环队列元素
void PrintQueue(SqQueue q) {
    for(int i=q.front; i!=q.rear; i=(i+1) % MAXSIZE) {
        cout << q.base[i] << ' ';
    }
    cout << endl;
}

int main()
{
    SqQueue q;
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

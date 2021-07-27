#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MaxInt 32767 //表示极大值
#define MVNum 100 //最大顶点数
typedef string VerTexType;  //顶点的数据类型
typedef int ArcType; //边的权值类型
typedef int Status;

typedef int QElemType;  //队列
typedef int Status;

//图邻接矩阵
typedef struct {
    VerTexType vexs[MVNum];  //顶点表
    ArcType arcs[MVNum][MVNum];  //邻接矩阵
    int vernum, arcnum;      //当前点数和边数
}AMGraph;

//队列
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct {
    QueuePtr front; //队头指针
    QueuePtr rear; //队尾指针
} LinkQueue;

//得到顶点i的数据
VerTexType Vertexdata(AMGraph G, int i) {
    return G.vexs[i];
}

//返回v的第一个邻接点编号，没有返回-1
int FirstAdjVex(AMGraph G, int v) {
    for(int i=0; i<G.vernum; i++) {
        if(G.arcs[v][i] != 0)
            return i;
    }
    return -1;
}

//返回v相对于w的下一个邻接点，没有返回-1
int NextAdjVex(AMGraph G, int v, int w) {
    for(int i=w+1; i<G.vernum; i++){
        if(G.arcs[v][i] != 0)
            return i;
    }
    return -1;
}

//输出各个顶点的邻接点
void PrintAdjVex(AMGraph G) {
    for(int i=0; i<G.vernum; i++) {
        cout << Vertexdata(G, i) << ':';
        for(int w=FirstAdjVex(G, i); w>=0; w=NextAdjVex(G, i, w)) {
            cout << ' ' << Vertexdata(G, w);
        }
        cout << endl;
    }
}

//确定V在G中的位置
int LocateVex(AMGraph G, VerTexType v) {
    for(int i=0; i<G.vernum; i++)
        if(G.vexs[i] == v)
            return i;
    return -1;
}

//创建无向网
Status CreateUDN(AMGraph &G) {
    cin >> G.vernum >> G.arcnum;
    for(int i=0; i<G.vernum; i++)
        cin >> G.vexs[i];
    for(int i=0; i<G.vernum; i++)
        for(int j=0; j<G.vernum; j++)
            G.arcs[i][j] = 0;
    for(int k=0; k<G.arcnum; k++) {
        VerTexType v1, v2;
        ArcType w = 1;
        cin >> v1 >> v2;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = G.arcs[j][i] = w;
    }

}

//输出邻接矩阵
void PrintUDG(AMGraph G) {
    cout << "    ";
    for(int i=0; i<G.vernum; i++)
        cout << setw(4) <<G.vexs[i];
    cout << endl;
    for(int i=0; i<G.vernum; i++) {
            cout << setw(4) << G.vexs[i];
        for(int j=0; j<G.vernum; j++) {
            cout << setw(4) << G.arcs[i][j];
        }
        cout << endl;
    }
}

//DFS遍历图
bool visited_DFS[MVNum];
void DFS(AMGraph G, int v) {
    cout << G.vexs[v] << ' ';
    visited_DFS[v] = true;
    for(int w=FirstAdjVex(G, v); w>=0; w=NextAdjVex(G, v, w)) {
        if(!visited_DFS[w])
            DFS(G, w);
    }
}

void DFSTraverse(AMGraph G) {
    cout << "DFS：";
    memset(visited_DFS, false, sizeof(bool));
    for(int v; v<G.vernum; v++) {
        if(!visited_DFS[v])
            DFS(G, v);
    }
    cout << endl;
}

//BFS遍历图
bool visited_BFS[MVNum];

//链队初始化
Status InitQueue(LinkQueue &q) {
    q.front = q.rear = new QNode;
    q.front->next = NULL;
    return OK;
}

//判断队列是否为空
bool QueueEmpty(LinkQueue q) {
    return q.front == q.rear;
}

//入队
Status EnQueue(LinkQueue &q, QElemType e) {
    QNode *p = new QNode;
    p->data = e;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;
    return OK;
}

//出队
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

void BFSTraverse(AMGraph G, int v) {
    QElemType u;
    LinkQueue q;
    memset(visited_BFS, false, sizeof(bool));
    cout << "BFS：" << G.vexs[v] << ' ';
    visited_BFS[v] = true;
    InitQueue(q);
    EnQueue(q, v);
    while(!QueueEmpty(q)) {
        DeQueue(q, u);
        for(int w=FirstAdjVex(G, u); w>=0; w=NextAdjVex(G, u, w)) {
            if(!visited_BFS[w]) {
                cout << G.vexs[w] << ' ';
                visited_BFS[w] = true;
                EnQueue(q, w);
            }
        }
    }
}

int main()
{
    AMGraph G;
    CreateUDN(G);
    PrintAdjVex(G);
    PrintUDG(G);
    DFSTraverse(G);
    BFSTraverse(G, 0);
    return 0;
}

//测试数据
//8 9
//v1 v2 v3 v4 v5 v6 v7 v8
//v1 v2
//v1 v3
//v2 v4
//v2 v5
//v3 v6
//v3 v7
//v4 v8
//v5 v8
//v6 v7

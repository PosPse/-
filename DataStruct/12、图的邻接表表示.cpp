#include <iostream>
#include <iomanip>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MVNum 100         //最大顶点数

typedef string VerTexType; //顶点信息
typedef int OtherInfo;    //和边相关的信息
typedef int Status;

typedef struct ArcNode {                //边结点
    int adjvex;                          //该边所指向的顶点的位置
    struct ArcNode *nextarc;          //指向下一条边的指针
    OtherInfo info;                      //和边相关的信息
} ArcNode;

typedef struct VNode {
    VerTexType data;                    //顶点信息
    ArcNode *firstarc;                //指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum];                //AdjList表示邻接表类型

typedef struct {
    AdjList vertices;                  //邻接表
    int vexnum, arcnum;              //图的当前顶点数和边数
} Graph;

//得到顶点i的数据
VerTexType Vertexdata(const Graph &G, int i) {
    return G.vertices[i].data;
}

//确定点v在G中的位置
int LocateVex(Graph G, VerTexType v) {
    for(int i=0; i<G.vexnum; i++)
        if(G.vertices[i].data == v)
        return i;
    return -1;
}

//对每个顶点的链表排序，按顶点编号从小到大排列
void ArclistSort(ArcNode *arclist) {
    ArcNode *i,*j;
    if(arclist->nextarc == NULL || arclist == NULL){
        return ;
    }
    for(i=arclist; i; i=i->nextarc) {
        for(j=arclist; j->nextarc; j=j->nextarc) {
            if(j->adjvex > j->nextarc->adjvex) {
                swap(j->adjvex, j->nextarc->adjvex);
            }
        }
    }
}

//返回v的第一个邻接顶点。若顶点在G中没有邻接表顶点，则返回-1
int FirstAdjVex(const Graph &G, int v) {
    if(LocateVex(G, G.vertices[v].data) == -1)
        return -1;
    if(G.vertices[v].firstarc)
        return G.vertices[v].firstarc->adjvex;
    return -1;
}

// 返回v的（相对于w的）下一个邻接顶点。
int NextAdjVex(const Graph &G, int v, int w) {
    ArcNode *p = G.vertices[v].firstarc;
    while(p && w != p->adjvex) {
        p = p->nextarc;
    }
    if(!p || !p->nextarc)
        return -1;
    else return p->nextarc->adjvex;
}

//创建无向网
Status CreateUDG(Graph &G) {
    VerTexType v1, v2;
    ArcNode *p1, *p2;
    cin >> G.vexnum >> G.arcnum;
    for(int i=0; i<G.vexnum; i++) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for(int k=0; k<G.arcnum; k++) {
        cin >> v1 >>v2;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
    //排序
    for(int i=0; i<G.vexnum; i++)
        ArclistSort(G.vertices[i].firstarc);
}

//输出邻接表
void PrintUPG(Graph G) {
    for(int i = 0; i < G.vexnum; i++) {
        cout << Vertexdata(G, i) << ":";
        for(int w = FirstAdjVex(G, i); w >= 0; w = NextAdjVex(G, i, w)) {
            cout << ' ' << Vertexdata(G, w);
        }
        cout << endl;
    }
}

int main()
{
    Graph G;
    CreateUDG(G);
    PrintUPG(G);
    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

#define MVNum 100         //最大顶点数
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef string VerTexType; //顶点信息
typedef int OtherInfo;    //和边相关的信息

typedef int QElemType;    //队列 
typedef int Status;

//- - - - -图的邻接表存储表示- - - - -
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

//- - - - - 队列的链式存储结构- - - - -
typedef struct QNode {
	QElemType data;
	struct QNode *next;
} QNode, *QueuePtr;
typedef struct {
	QueuePtr front; //队头指针
	QueuePtr rear; //队尾指针
} LinkQueue;

//得到顶点i的数据
VerTexType Vertexdata(const Graph &g, int i) {
	return g.vertices[i].data;
}

int LocateVex(const Graph &g, VerTexType v) {
	//确定点v在G中的位置
	for(int i = 0; i < g.vexnum; ++i)
		if(g.vertices[i].data == v)
			return i;
	return -1;
}//LocateVex

//返回v的第一个邻接顶点。若顶点在G中没有邻接表顶点，则返回-1。
int FirstAdjVex(const Graph &g, int v) {
	if(LocateVex(g, g.vertices[v].data) == -1)
		return -1;
	if(g.vertices[v].firstarc)
		return g.vertices[v].firstarc->adjvex;
	return -1;
}

// 返回v的（相对于w的）下一个邻接顶点。
int NextAdjVex(const Graph &g, int v, int w) {
	ArcNode *p = g.vertices[v].firstarc;
	while(p && w != p->adjvex) {
		p = p->nextarc;
	}
	if(!p || !p->nextarc)
		return -1;
	else return p->nextarc->adjvex;
}

//对每个顶点的链表排序，按顶点编号从小到大排列
void sort(ArcNode *arclist) {
	ArcNode *i,*j;
	if(arclist->nextarc == NULL || arclist == NULL)
		return ;
	for(i = arclist ; i ; i = i->nextarc) {
		for(j = arclist ; j->nextarc ; j = j->nextarc) {
			if(j->adjvex > j->nextarc->adjvex) {
				swap(j->adjvex, j->nextarc->adjvex);
			}
		}
	}
}

int CreateUDG(Graph &g) {
	//采用邻接表表示法，创建无向图G
	int i,j,k;
	VerTexType v1,v2;
	ArcNode *p1,*p2;
	cin >> g.vexnum >> g.arcnum ;
	for(i = 0 ; i < g.vexnum ; i++) {
		cin >> g.vertices[i].data;
		g.vertices[i].firstarc = NULL;
	}
	for(k = 0 ; k < g.arcnum ; k++) {
		cin >> v1 >> v2;
		i = LocateVex(g, v1);
		j = LocateVex(g, v2);
		p1 = new ArcNode;
		p1->adjvex = j;
		p1->nextarc = g.vertices[i].firstarc;
		g.vertices[i].firstarc = p1;
		p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = g.vertices[j].firstarc;
		g.vertices[j].firstarc = p2;
	}
	/***********************************/
	for(i = 0; i < g.vexnum; ++i) {
		sort(g.vertices[i].firstarc); ////保证有序，不依赖输入次序
	}//for
	return OK;
}//CreateUDG

void PrintDian(Graph g){
	for(int i = 0; i < g.vexnum; i++) {
		cout << Vertexdata(g, i) << ":";
		for(int w = FirstAdjVex(g, i); w >= 0; w = NextAdjVex(g, i, w)) {
			cout << ' ' << Vertexdata(g, w);
		}
		cout << endl;
	}
	cout << endl;
} //输出各个顶点的邻接点

bool visited[MVNum];

Status InitQueue(LinkQueue &q) { //构造一个空队列Q
	q.front = q.rear = new QNode; //生成新结点作为头结点，队头和队尾指针指向此结点
	q.front->next = NULL; //头结点的指针域置空
	return OK;
}//链队的初始化

Status EnQueue(LinkQueue &q, QElemType e) {

	QNode *p = new QNode;
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return OK;
}//　链队的入队

Status QueueEmpty(LinkQueue q) {
	return q.front == q.rear ;
}

Status DeQueue(LinkQueue &q, QElemType &e) {
	if(q.front == q.rear )
		return ERROR;
	QueuePtr p = q.front ->next;
	e = p->data ;
	q.front->next = p->next ;
	if(q.rear == p)
		q.rear = q.front ;
	delete p;
	return OK;
}//链队的出队

QElemType GetHead(LinkQueue q) {
	return q.front->next->data;
}//取链队的队头元素

void BFSTraverse(Graph g, int v) {
	int u, w;
	LinkQueue q;
	
	cout << Vertexdata(g, v) << " ";
	visited[v] = true;
	InitQueue(q);
	EnQueue(q,v); 
	while(!QueueEmpty(q)) {
		DeQueue(q, u);
		for(w=FirstAdjVex(g,u); w>=0; w=NextAdjVex(g,u,w)) {
			if(!visited[w]) {
				cout << Vertexdata(g, w) << " ";
				visited[w] = true;
				EnQueue(q,w);
			}
		}
	}
	cout<<endl;
}//广度优先搜索 

bool Visited[MVNum];

void DFS(Graph g, int v) {
	cout << g.vertices[v].data <<' ';
	Visited[v] = true;
	int w;
	for(w = FirstAdjVex(g, v); w >= 0; w = NextAdjVex(g, v, w)) {
		if(!Visited[w]) {
			DFS(g,w);
		}
	}
}

void DFSTraverse(Graph g) {
	int v;
	for(v=0; v<g.vexnum; v++) {
		Visited[v] = false;
	}
	for(v=0; v<g.vexnum; v++) {
		if(!Visited[v]) {
			DFS(g,v);
		}
	}
	cout<<endl<<endl;
}//深度优先搜索 

void DestroyUDG(Graph &g) {
	//you should do this
}

int main() {
	Graph g;
	CreateUDG(g);      //创建邻接表 
	PrintDian(g);      //打印各邻接点
	cout << "深度优先搜索: ";
	DFSTraverse(g);    //深度优先搜索 
	cout << "广度优先搜索: "; 
	BFSTraverse(g,0);  //广度优先搜索 
	DestroyUDG(g);     //销毁图
	return 0;
}//main如图+

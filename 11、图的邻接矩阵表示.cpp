#include <iostream>
#include <iomanip>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MaxInt 32767 //表示极大值
#define MVNum 100 //最大顶点数
typedef char VerTexType;  //顶点的数据类型
typedef int ArcType; //边的权值类型
typedef int Status;

typedef struct {
    VerTexType vexs[MVNum];  //顶点表
    ArcType arcs[MVNum][MVNum];  //邻接矩阵
    int vernum, arcnum;      //当前点数和边数
}AMGraph;

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
        ArcType w;
        cin >> v1 >> v2 >> w;
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
int main()
{
    AMGraph G;
    CreateUDN(G);
    PrintAdjVex(G);
    PrintUDG(G);
    return 0;
}

//测试数据
//6 10
//a b c d e f
//a b 5
//b c 4
//a c 8
//a f 3
//a d 7
//c f 9
//c d 5
//d f 6
//f e 1
//e d 5

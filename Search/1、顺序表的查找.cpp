#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MaxSize 100
typedef int ElemType;
typedef int KeyType;
typedef int Status;

typedef struct {
    ElemType *elem;
    int length;
}SSTable;

//初始化顺序表
Status InitSSTable(SSTable &ST) {
    ST.elem = new ElemType[MaxSize];
    if(!ST.elem)
        exit(OVERFLOW);
    ST.length = 0;
    return OK;
}

//创建顺序表
void CreateSSTable(SSTable &ST) {
    int len;
    cin >> len;
    ST.length = len;
    for(int i=0; i<ST.length; i++) {
        cin >> ST.elem[i];
    }
}

//第一种顺序查找
int Search_Seq(SSTable ST, KeyType key) {
    for(int i=ST.length-1; i>=0; i--) {
        if(ST.elem[i] == key)
            return i;
    }
    return -1;
}

//第二种顺序查找
int Search_Seq2(SSTable ST, KeyType key) {
    ST.elem[0] = key;
    int i;
    for(i=ST.length-1; ST.elem[i] != key; --i);
    return i;
}

int main()
{
    SSTable ST;
    InitSSTable(ST);
    CreateSSTable(ST);
    cout << "第一种顺序查找：" << Search_Seq(ST, 3) << endl;
    cout << "第二种顺序查找：" << Search_Seq2(ST, 3) << endl;
    return 0;
}

//测试数据
//10
//1 2 3 5 6 9 8 0 4 7

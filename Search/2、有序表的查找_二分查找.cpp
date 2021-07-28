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
        ST.elem[i] = i;
    }
}

//输出有序表
void PrintSSTable(SSTable ST) {
    for(int i=0; i<ST.length; i++)
        cout << ST.elem[i] << ' ';
    cout << endl;
}

//二分查找
int Search_Bin(SSTable ST, KeyType key) {
    int low = 1, high = ST.length;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(key == ST.elem[mid])
            return mid;
        else if(key < ST.elem[mid])
            high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int main()
{
    SSTable ST;
    KeyType key;
    InitSSTable(ST);
    CreateSSTable(ST);
    PrintSSTable(ST);
    cout << "输入key：";
    cin >> key;
    cout << "二分查找：" << Search_Bin(ST, key) << endl;
    return 0;
}

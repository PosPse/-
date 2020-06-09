#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

#define MAXSIZE 1000
typedef int KeyType;

typedef struct {
	KeyType key;              //关键字项
	// InfoType otherinfo;    //其他数据项
} RedType;					 //记录类型

typedef struct {
	RedType r[MAXSIZE+1];     //r[0]闲置或用作哨兵单元
	int length;	              //顺序表长度
} SqList;                     //顺序表类型

void InsertSort(SqList &L) {
	int i, j;
	for(i = 2; i <= L.length; i++) {              
		if(L.r[i].key < L.r[i-1].key) {                      //“<”，需将L.r[i]插入有序子表 
			L.r[0] = L.r[i];                                 //复制为哨兵 
			L.r[i] = L.r[i-1];
			for(j = i-2; L.r[0].key < L.r[j].key; --j) {
				L.r[j+1] = L.r[j];                           //记录后移 
			}
			L.r[j+1]= L.r[0];                                //插入到正确位置 
		}
	}
}//直接插入排序 

void PrintSort(SqList L) {
	int i;
	for(i = 1; i <= L.length; i++) {
		cout << L.r[i].key << " ";
	}
	cout << endl;
}//排序后输出

int main() {
	SqList L;
	int n, i;
	cin >> L.length;                   //顺序表长度 
	for(i = 1; i <= L.length; i++) {    
		cin >> L.r[i].key;
	}
	InsertSort(L);                     //直接插入排序 
	PrintSort(L);                      //排序后输出 
	return 0;
}

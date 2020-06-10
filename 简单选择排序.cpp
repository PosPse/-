#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

#define  MAXSIZE  1000          			//顺序表的最大长度
typedef struct {
	int key;
	char *otherinfo;
} ElemType;
//顺序表的存储结构
typedef struct {
	ElemType *r;	         						//存储空间的基地址
	int  length;            						//顺序表长度
} SqList;											//顺序表类型

void CreateSqList(SqList &L) {
	int i,n;
	cin >> n;											//输入待排序元素个数
	for(i=1; i<=n; i++) {                               //输入各元素
		cin >> L.r[i].key;
		L.length++;
	}
}

void SelsctSort(SqList &L) {
	//对顺序表L做简单选择排序 
	int i, j, k;
	for(i = 1; i < L.length; i++) {                    //在L.r[i..L.length]中选择关健字最小的记录            
		k = i;
		for(j = i+1; j <= L.length; ++j) {
			if(L.r[j].key < L.r[k].key) {
				k = j;
			}
		}
		if(k != i) {
			swap(L.r[i], L.r[k]);                     //交换r[i]和r[k] 
		}
	}//for
}//SelsctSort

void show(SqList L) {
	int i;
	for(i=1; i<=L.length; i++)
		cout << L.r[i].key << ' ';
	cout << endl;
}//show

int main() {
	SqList L;
	L.r=new ElemType[MAXSIZE+1];
	L.length=0;
	CreateSqList(L);                                 //创建顺序表
	SelsctSort(L);                                   //简单选择排序
	show(L);                                         //排序结果
}

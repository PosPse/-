#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

#define  MAXSIZE  100000          			//顺序表的最大长度
typedef struct {
	int key;
	char *otherinfo;
} ElemType;
//顺序表的存储结构
typedef struct {
	ElemType *r;	         						//存储空间的基地址
	int  length;            						//顺序表长度
} SqList;											//顺序表类型

void ScanfSqList(SqList &L) {
	int i,n;
	cin >> n;											//输入待排序元素个数
	for(i=1; i<=n; i++) {                               //输入各元素
		cin >> L.r[i].key;
		L.length++;
	}
}//ScanfSqList顺序表输入 

void HeapAdjust(SqList &L, int s, int m){
	//假设 r[s+1..m] 已经是堆，将 r[s..m] 调整为以 r[s] 为根的大根堆 
	int j;
	ElemType rc;
	rc = L.r[s];
	for(j = 2*s; j <= m; j *= 2) {                 //沿 key 较大的孩子结点向下筛选 
		if(j < m && L.r[j].key < L.r[j+1].key)
		++j;									   //j 为 key 较大的记录的下标 
		if(rc.key >= L.r[j].key)
		break;                                     //rc 应插入在位置s上 
		L.r[s] = L.r[j];
		s = j;
	}
	L.r[s] = rc;                                   //插入 
}//HeapAdjust堆调整 

void CreatHeap(SqList &L) {
	//把无序序列 L.r[i..n] 建成大根堆 
	int i, n;
	n = L.length;
	for(i = n/2; i > 0; --i) {
		HeapAdjust(L, i, n);
	} 
}//CreatHeap创建堆 

void HeapSort(SqList &L) {
	//对顺序表L进行堆排序
	//把无序序列 L.r[i..L.length] 建成大根堆 
	int i;
	CreatHeap(L);
	for(i = L.length; i > 1; --i) {
		swap(L.r[1], L.r[i]);                     //将堆顶记录和 L.r[1..i] 最后一个记录交换 
		HeapAdjust(L, 1, i-1);                    //将 L.r[1..i] 重新调整为大根堆 
	}
}//HeapSort堆排序 

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
	ScanfSqList(L);                                 //创建顺序表
	HeapSort(L);                                    //堆排序
	show(L);                                        //排序结果
}

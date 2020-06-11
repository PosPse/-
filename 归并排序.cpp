#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

#define  MAXSIZE  100000         			//顺序表的最大长度
typedef struct {
	int key;
	char *otherinfo;
} RedType;
//顺序表的存储结构
typedef struct {
	RedType *r;	         						//存储空间的基地址
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

void Merge(RedType R[], RedType T[], int low, int mid, int high) {
	//有序表 R[low..high] 和 L[mid+1..high] 归并为 T[low..high] 
	int i, j, k;
	i = low;
	j = mid + 1;
	k = low;
	while(i <= mid && j <= high) {
		if(R[i].key <= R[j].key)
			T[k++] = R[i++];
		else T[k++] = R[j++];
	}
	while(i <= mid)T[k++] = R[i++];
	while(j <= high)T[k++] = R[j++];
}//Merge

void MSort(RedType R[], RedType T[], int low, int high) {
	// R[low..high]归并排序后放入 T[low..high] 
	int mid;
	RedType *S = new RedType[MAXSIZE];
	if(low == high) {
		T[low] = R[low];
	} else {
		mid = (low + high) / 2;
		MSort(R, S, low, mid);
		MSort(R, S, mid+1, high);
		Merge(S, T, low, mid, high);
	}//else
}//MSort

void MergeSort(SqList &L) {
	//对顺序表 L 做归并排序 
	MSort(L.r, L.r, 1, L.length);
}//MergeSort归并排序 

void show(SqList L) {
	int i;
	for(i=1; i<=L.length; i++)
		cout << L.r[i].key << ' ';
	cout << endl;
}//show

int main() {
	SqList L;
	L.r=new RedType[MAXSIZE+1];
	L.length=0;
	ScanfSqList(L);                                 //创建顺序表
	MergeSort(L);                                    //堆排序
	show(L);                                        //排序结果
}

#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;
#define  MAXSIZE  1000          			//顺序表的最大长度
typedef struct {
	int key;                                        //顺序表的存储结构
	//char *otherinfo;
} ElemType;

typedef struct {
	ElemType *r;	         						//存储空间的基地址
	int  length;            						//顺序表长度
} SqList;											//顺序表类型

void ShellInsert(SqList &L,int dk) {
	//对顺序表L做一趟增量是dk的希尔插入排序
	int i,j;
	for(i = dk+1; i <= L.length; ++i)
		if(L.r[i].key<L.r[i-dk].key) {                     //需将L.r[i]插入有序增量子表                          
			L.r[0]=L.r[i];						           //暂存在L.r[0]
			for(j=i-dk; j>0&& L.r[0].key<L.r[j].key; j-=dk)
				L.r[j+dk]=L.r[j];				           //记录后移
			L.r[j+dk]=L.r[0];					           //将r[0]即原r[i]，插入到正确位置
		}										//for
}//ShellInsert

void ShellSort(SqList &L,int dt[ ],int t) {
	//按增量序列dt[0..t-1]对顺序表L作t趟希尔排序
	int k;
	for(k=0; k<t; ++k)
		ShellInsert(L,dt[k]);			 		
}//ShellSort												

void show(SqList L) {
	int i;
	for(i = 1; i <= L.length; i++)
		cout << L.r[i].key << ' ';
		cout << endl; 
}

int main() {
	SqList L;
	L.r=new ElemType[MAXSIZE+1];
	L.length=0;
	
    int i, n, t;
	cin >> n;										//排序元素个数
	for(i = 1; i <= n; i++) {                       //输入各排序元素 
		cin >> L.r[i].key;
		L.length++;
	}

	int dt[100];  
	i = 0; 
	n /= 2;                                        //增量数组
	while(n) {
	dt[i] = n;
	i++;
	n /= 2;
	}
	t = i; 
	ShellSort(L,dt,t);                            //排序后输出 
	show(L);
}

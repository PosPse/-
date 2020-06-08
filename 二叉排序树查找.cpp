#include<iostream>
#include<cstdio>

using namespace std;

typedef struct BSTNode {
	int data;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

void InsertBST(BSTree &T, int key) {
	if(!T) {
		T = new BSTNode;
		T->data = key;
		T->lchild = T->rchild = NULL;
	} else if (key < T->data)
		InsertBST(T->lchild, key);
	else if (key > T->data)
		InsertBST(T->rchild, key);
}//建立二叉排序树

bool SearchBST(BSTree T, int key) {
	if(!T)
		return false;
	else if(T->data == key)
		return true;
	else if(key < T->data)
		SearchBST(T->lchild, key);
	else if(key > T->data)
		SearchBST(T->rchild, key);
}//二叉排序树查找

int main() {
	int m, n, key;
	BSTree T = NULL;
	cin >> m >> n;                        //m:二叉排序树元素个数，n:查找次数
	for(int i = 1; i<=m; i++) {
		cin >> key;
		InsertBST(T, key);                //建立二叉排序树
	}
	for(int i = 1; i<=n; i++) {
		cin >> key;
		cout << SearchBST(T, key) <<" ";  //二叉排序树查找
	}
	cout << endl;
	return 0;
}//main

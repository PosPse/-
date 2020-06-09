//链地址法的散列表
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

typedef struct node {
	int key;
	struct node *next;
} Node, *PNode;

typedef struct {
	PNode *elem;
	int sz; //size of hashtable
} HashTable;

void InitHashTable(HashTable &ht, int n) {
	ht.sz = n;
	//申请大小为n的指针数组，每个指针初始化为NULL
	ht.elem = new PNode[n]();
}


//将k插入ht中对应的链表尾部，如果表中k已经存在，直接返回false，否则插入k后返回true
bool InsertHashTable(HashTable &ht, int k) {
	int id = k % ht.sz;
	PNode p, pre, e;
	for(pre = NULL, p = ht.elem[id]; p != NULL; pre = p, p = p->next) {
		if(p->key == k)
			return false;
	}
	e = new Node;
	e->key = k;
	e->next = NULL;
	if(pre == NULL)
		ht.elem[id] = e;
	else
		pre->next = e;
	return true;
}

//如果表中存在k，返回指向对应结点的指针，否则返回NULL
PNode SearchHashTable(HashTable ht, int k) {
	/****在此下面完成代码************/
	int id = k % ht.sz;
	PNode p;
	for(p = ht.elem[id]; p != NULL && p->key != k; p = p->next);
	return p;
}

//删除表中含关键字k的结点并返回true。如果不存在，直接返回false。
bool DeleteHashTable(HashTable &ht, int k) {
	int id = k % ht.sz;
	PNode pre = NULL, p;
	for(p = ht.elem[id]; p != NULL && p->key != k; pre = p, p = p->next);
	if(p == NULL)
		return false;
	if(pre == NULL) {
		ht.elem[id] = p->next;
	} else {
		pre->next = p->next;
	}
	delete p;
	return true;
}

static void PrintLinklist(PNode h) {
	for(PNode p = h; p; p = p->next) {
		cout << "->" << p->key;
	}
	cout << endl;
}

void  PrintHashTable(HashTable ht) {
	cout << "Print the hash table\n";
	for(int i = 0; i < ht.sz; i++) {
		cout << '[' << i << ']';
		PrintLinklist(ht.elem[i]);
	}
}

void DestroyHashTable(HashTable &ht) {
	//You should do this!
}

int main() {
	int n;
	HashTable ht;
	string op;
	cin >> n;
	InitHashTable(ht, n);
	while(cin >> op) {
		int k;
		if(op == "insert") {
			cin >>  k;
			if(!InsertHashTable(ht, k))
				cout << k << " is " <<  "already existed in hash table\n";
		} else if(op == "search") {
			cin >>  k;
			cout << k << " is" << (SearchHashTable(ht, k) ? "" : " not") << " found\n";
		} else if(op == "delete") {
			cin >>  k;
			if(DeleteHashTable(ht, k)) {
				PrintHashTable(ht);
			} else
				cout << k << " is " <<  "not existed in hash table\n";
		} else if(op == "print") {
			PrintHashTable(ht);
		}
	}
	DestroyHashTable(ht);
	return 0;
}//main

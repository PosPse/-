#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MaxSize 100
typedef int Status;
typedef int ElemType;

typedef struct Node {
    ElemType key;
    struct Node *next;
}Node, *PNode;

typedef struct {
    PNode *elem;
    int size;
}HashTable;

//初始化HashTable
Status InitHashTable(HashTable &H, int n) {
    H.size = n;
    H.elem = new PNode[n]();
}

//将key插入H中对应的链表尾部，如果表中key已经存在，直接返回false，否则插入key后返回true
bool InsertHashTable(HashTable &H, ElemType key) {
    int id = key % H.size;
    PNode p, pre, e;
    for(pre=NULL, p=H.elem[id]; p!=NULL; pre=p, p=p->next) {
        if(p->key == key)
            return false;
    }
    e = new Node;
    e->key = key;
    e->next = NULL;
    if(pre == NULL)
        H.elem[id] = e;
    else
        pre->next = e;
    return true;
}

//如果表中存在key，返回指向对应结点的指针，否则返回NULL
PNode SearchHashTable(HashTable H, ElemType key) {
    int id = key % H.size;
    PNode p;
    for(p=H.elem[id]; p!=NULL && p->key!=key; p=p->next);
    return p;
}

//删除表中含关键字key的结点并返回true。如果不存在，直接返回false
bool DeleteHashTable(HashTable &H, ElemType key) {
    int id = key % H.size;
    PNode pre = NULL, p;
    for(p=H.elem[id]; p!=NULL && p->key!=key; pre=p, p=p->next);
    if(p == NULL) {
        return false;
    }
    else if(pre == NULL) {
        H.elem[id] = p->next;
    }else {
        pre->next = p->next;
    }
    delete p;
    return true;

}

//输出哈希表
void PrintLinklist(PNode head) {
    for(PNode p=head; p; p=p->next) {
        cout << "->" << p->key;
    }
    cout << endl;
}

void PrintHashTable(HashTable H) {
    cout << "Print the hash table\n";
    for(int i=0; i<H.size; i++) {
        cout << '[' << i << ']';
        PrintLinklist(H.elem[i]);
    }
}
int main()
{
    int size;
    HashTable H;
    string op;
    cin >> size;
    InitHashTable(H, size);
    while(cin >> op) {
        ElemType key;
        if(op == "insert") {
            cin >> key;
            if(!InsertHashTable(H, key))
                cout << key << " is" << " already existed in hash table\n";
        }else if(op == "search") {
            cin >> key;
            cout << key << " is" << (SearchHashTable(H, key)?"" : " not") << " found\n";
        }else if(op == "delete") {
            cin >> key;
            if(DeleteHashTable(H, key))
                PrintHashTable(H);
            else
                cout << key << " is " <<  "not existed in hash table\n";
        }else if(op == "print") {
            PrintHashTable(H);
        }
    }
    return 0;
}

//测试数据
//13
//insert 19
//insert 14
//insert 14
//insert 23
//insert 1
//print
//search 68
//insert 68
//insert 20
//insert 84
//insert 27
//search 68
//insert 55
//insert 11
//insert 10
//insert 79
//print
//insert 27
//delete 1
//delete 80
//delete 19
//delete 55

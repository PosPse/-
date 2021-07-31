#include <iostream>
using namespace std;

#define MAX_SIZE 100

//输入数据
void initArray(int *arr, int length) {
    for(int i=0; i<length; i++) {
        cin >> arr[i];
    }
}

//插入排序
void insertSort(int *arr, int length) {
    for(int i=0; i<length - 1; i++) {
        int current = arr[i+1];
        int index = i;
        while(index >= 0 && current < arr[index]) {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] =current;
    }
}

//输出数组
void printArray(int *arr, int length) {
    for(int i=0; i<length; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int arr[MAX_SIZE];
    int length;
    cin >> length;
    initArray(arr, length);
    insertSort(arr, length);
    printArray(arr, length);
    return 0;
}

//测试数据
//10
//5 2 6 9 7 8 4 0 1 3

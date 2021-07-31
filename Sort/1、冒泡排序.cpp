#include <iostream>
using namespace std;

#define MAX_SIZE 100

//输入数据
void InitArray(int *arr, int length) {
    for(int i=0; i<length; i++) {
        cin >> arr[i];
    }
}

//冒泡排序
void BubbleSort(int *arr, int length) {
    for(int i=0; i<length; i++) {
        for(int j=0; j<length - i - 1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

//输出数组
void PrintArray(int *arr, int length) {
    for(int i=0; i<length; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int arr[MAX_SIZE];
    int length;
    cin >> length;
    InitArray(arr, length);
    BubbleSort(arr, length);
    PrintArray(arr, length);
    return 0;
}

//测试数据
//10
//5 2 6 9 7 8 4 0 1 3

#include <iostream>
using namespace std;

#define MAX_SIZE 100

//输入数据
void InitArray(int *arr, int length) {
    for(int i=0; i<length; i++) {
        cin >> arr[i];
    }
}

//选择排序
void SelectionSort(int *arr, int length) {
    for(int i=0; i<length; i++) {
        int minIndex = i;
        for(int j=i+1; j<length; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
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
    SelectionSort(arr, length);
    PrintArray(arr, length);
    return 0;
}

//测试数据
//10
//5 2 6 9 7 8 4 0 1 3

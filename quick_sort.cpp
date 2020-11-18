// 快速排序 递归解法 2020.11.18
// 选取序列最右端为基准值mid，将mid左边所有值与mid比较，划分为两个区间，得到一个重合指针
// 四个区间
// 1.左边小于mid的区间
// 2.重合的指针位置
// 3.右边大于mid的区间
// 4.基准值
// 判断基准值与mid的大小，分两种情况
// 在每种情况下，对两边区间进行递归排序
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort_recu(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    //左指针与右指针重合，循环结束
    while (left < right)
    {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    //判断重合后的指针left指向的值
    //如果该值大于基准值（此处为arr[end])，将两者值交换，然后两边区间递归排序
    if (arr[left] > mid)
        swap(&arr[left], &arr[end]);
    //如果该值小于等于基准值，将重合的指针右移1位，交换其和基准值，然后两边区间递归排序
    else
    {
        left++;
        swap(&arr[left], &arr[end]);
    }
    quick_sort_recu(arr, start, left - 1);
    quick_sort_recu(arr, left + 1, end);
}

int main()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = sizeof(arr) / sizeof(*arr);
    int start = 0, end = len - 1;
    quick_sort_recu(arr, start, end);
    // for(int i:arr)
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
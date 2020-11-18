#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;    
}

void quick_sort_recu(int arr[],int start,int end)
{
    if(start>=end)
        return;
    int mid=arr[end];
    int left=start,right=end-1;
    while(left<right)
    {
        while(arr[left]<mid&&left<right)
            left++;
        while(arr[right]>=mid&&left<right)
            right--;
        swap(&arr[left],&arr[right]);
    }
    if(arr[left]>=arr[end])
        swap(&arr[left],&arr[end]);
    else
        left++;

    quick_sort_recu(arr,start,left-1);
    quick_sort_recu(arr,left+1,end);
}



int main()
{
    int arr[]= { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len=sizeof(arr)/sizeof(*arr);
    int start=0,end=len-1;
    quick_sort_recu(arr,start,end);
    // for(int i:arr)
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
}
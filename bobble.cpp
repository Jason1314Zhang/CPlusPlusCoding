#冒泡排序
#include <iostream>
using namespace std;

void bobble_sort(int arr[],int len)
{
    int temp=0;
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}

int main()
{
    int arr[]={ 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len=sizeof(arr)/sizeof(*arr);
    
    bobble_sort(arr,len);
    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
    
}
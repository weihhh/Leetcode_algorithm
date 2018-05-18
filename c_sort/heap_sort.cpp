#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int *x,int *y);
void max_heapify(int arr[],int i,int heap_size);
void biuld_max_heap(int arr[],int len);
void heap_sort(int arr[],int len);

void swap(int *x,int *y){
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}

void max_heapify(int arr[],int i,int heap_size){
    int largest;//存储最大值下标
    int left=2*i+1;//左孩子在数组中的下标
    int right=2*i+2;//右孩子在数组中的下标

    if (left<heap_size && arr[left]>arr[i]){
        largest=left;
    } 
    else{
        largest=i;
    }

    if (right<heap_size && arr[right]>arr[largest]){
        largest=right;
    } 
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        max_heapify(arr,largest,heap_size);//递归调用，需要递归的维持最大堆
    }
}

void biuld_max_heap(int arr[],int heap_size){
    int i;
    for (i=heap_size/2-1;i>=0;i--){//从最后一个非叶子节点开始
        max_heapify(arr,i,heap_size);
    }
}

void heap_sort(int arr[],int heap_size){
    int i;
    biuld_max_heap(arr,heap_size);
    for(i=heap_size-1;i>0;i--){
        swap(&arr[i],&arr[0]);//交换堆顶最大值和末尾值
        max_heapify(arr,0,--heap_size);

    }
}

int main()
{

    int array[]={0,14,10,8,7,9,3,2,4,1};
    int len=10,i;
    heap_sort(array,len);

    cout<<"heap sort result:\n";
    for (i=1; i<len; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
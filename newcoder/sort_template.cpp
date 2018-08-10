#include <iostream>
#include<stdio.h>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>   // std::greater
using namespace std;

void fre() { freopen("input.in", "r", stdin); freopen("output.out", "w", stdout); }
#define MS(x, y) memset(x, y, sizeof(x))


/*------------------------   插入排序    -----------------*/
//由小到大
//排好序O（n）,逆序O（n^2）
//直接插入排序，也是稳定排序
template<typename T>
void insert_sort(T *array,int length){
    if(length<1)
        return;
    for(int i=1;i<length;++i){//0位置已排序
        int j=i-1;
        T tmp=array[i];//优化为移动，暂存待插入元素
        while(j>=0&&array[j]>tmp){
            array[j+1]=array[j];//后移一位
            --j;
        }
        array[j+1]=tmp;
    }
}

/*------------------------   冒泡排序    -----------------*/
//最坏O（n^2）,最好O（n^2）,可优化为O（n），记录一轮是否有交换，没有交换则已排序好，直接退出
//两元素相等，不会交换，所以稳定
template<typename T>
void bubble_sort(T *array,int length){
    if(length<1)
        return;
    for(int i=1;i<length;++i){
        for (int j = 0; j < length-1; ++j){
            if(array[j]>array[j+1])
                swap(array[j],array[j+1]);
        }
    }
}


/*------------------------   选择排序    -----------------*/
// 最坏O（n^2）,最好O（n^2）
template<typename T>
void select_sort(T *array,int length){
    if(length<1)
        return;
    for (int i = 0; i < length-1; ++i)//i位置待排序，从后面找比当前i位置元素小的交换
    {
        int min=i;
        for (int j =i+1; j < length; ++j)
        {
            if(array[j]<array[min])
                min=j;
        }
        if(min!=i)
            swap(array[min],array[i]);
    }
}


/*------------------------   归并排序    -----------------*/
template<typename T>
void Merge(T *array,T *temp,int start_index,int mid_index,int end_index){
    //start_index-->mid_index 和 mid_index+1-->end_index 已经有序
    int i=start_index,j=mid_index+1,k=start_index;//i,j表示前后两段有序序列的序号，k表示辅助空间序号
    while(i<=mid_index&&j<=end_index){
        if(array[i]<=array[j]){
            temp[k++]=array[i++];
        }
        else{
            temp[k++]=array[j++];
        }
    }
    //选取两段中小的，可能会有一段已经取完，另一段还剩余
    while(i<=mid_index)
        temp[k++]=array[i++];
    while(j<=end_index)
        temp[k++]=array[j++];
    //复制辅助空间到原数组
    for (int x = start_index; x <=end_index ; ++x)
    {
        array[x]=temp[x];
    }
    // cout<<" start_index: "<<start_index<<"mid_index: "<<mid_index<<"end_index: "<<end_index<<endl;
    // for (int x = start_index; x <=end_index ; ++x)
    // {
    //     cout<<array[x]<<" ";
    // }
    // cout<<endl;
}

template<typename T>
void Divide(T *array,T *temp,int start_index,int end_index){
    if(start_index>=end_index)
        return;
    int mid_index=(start_index+end_index)/2;
    Divide(array,temp,start_index,mid_index);
    Divide(array,temp,mid_index+1,end_index);
    Merge(array,temp,start_index,mid_index,end_index);
}

//需要额外空间
template<typename T>
void Merge_sort(T *array,int length){
    T temp[length];
    Divide(array,temp,0,length-1);
}

/*------------------------   快速排序    -----------------*/
// 快速排序，如果选择关键值的子列表的最大或最小元素，则会导致最差情况出现
template<typename T>
void partition_sort(T *array,int start_index,int end_index){
    if(start_index>=end_index)
        return;
    int first=start_index;
    int last=end_index;
    T key=array[first];//保存当前作为关键词的元素,默认取第一个
    while(first<last){
        //取第一个，则末尾哨兵先动
        while(first<last&&array[last]>key)
            --last;
        //现在last元素小于等于key
        // array[first]=array[last];
        while (first < last && array[first] <= key) {
            ++first;
        }
        // array[last]=array[first];
        swap(array[first],array[last]);        
    }
    //相遇，则此位置为key最终位置
    // array[first]=key;
    swap(array[start_index],array[first]);
    partition_sort(array,start_index,first-1);
    partition_sort(array,first+1,end_index);

}


template<typename T>
void Quick_sort(T *array,int length){
    partition_sort(array,0,length-1);
}

/*------------------------   内置快速排序    -----------------*/

template<typename T>
void Buildin_quick_sort_(T *array,int length){
    // sort(array,array+length,std::greater<int>());//从大到小
    sort(array,array+length,std::less<int>());//从大到小
}



void solvecase(bool flag_int=true){
    int length;
    cin>>length;
    int array[length];
    char array_char[length+1];
    if(flag_int){
        for (int i = 0; i < length; ++i)
        {

            cin>>array[i];
        }
        Buildin_quick_sort_(array,length);
        for (int i = 0; i < length; ++i)
        {
            cout<<array[i]<<" ";
        }
    }
    else{
        for (int i = 0; i < length; ++i)
        {

            cin>>array_char[i];
        }
        Buildin_quick_sort_(array_char,length);
        for (int i = 0; i < length; ++i)
        {
            cout<<array_char[i]<<" ";
        }
    }

    printf("\n" );
}

int main() {
    fre();//测试使用
    int casenum,casei;
    bool flag_int=true;
    scanf("%d",&casenum);
    // cout<<casenum<<endl;
    for(casei=1;casei<=casenum;++casei){
        if(casei==casenum){
            flag_int=false;
        }
        solvecase(flag_int);
        // cout<<answer<<endl;
    }
    return 0;
//     int a,b;
//     while(cin >> a >> b)//注意while处理多个case
//         cout << a+b << endl;
}
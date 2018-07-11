#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<time.h>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

// unsigned long GetTickCount()
// {
//     struct timespec ts;
 
//     clock_gettime(CLOCK_MONOTONIC, &ts);
 
//     return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
// }


int RandomInRange(int start,int end){
    //[start,end),rand返回无符号整数
    return (rand() % (end-start))+ start;
}

//small指向小于指定值的最后一个数，++后就是大于等于指定值的，让index先行去找小于的，然后和++small交换，则将小的换到前面
int partition(vector<int> &data,int start,int end){
    if(data.empty()||start<0||end>data.size()-1)
        throw -1;
    if(start==end)
        return start;
    int index=RandomInRange(start,end);//这里unsigned 转换为int，隐患
    cout<<"here!"<<endl;
    // cout<<"now index: "<<index<<endl;
    swap(data[index],data[end]);
    // cout<<" swap one-------------"<<endl;
    // for(int i=0;i<data.size();++i)
    //     cout<<data[i]<<endl;
    int small=start-1;
    for(index=start;index<end;++index){
        // cout<<"-------------: "<<index<<endl;
        // for(int i=0;i<data.size();++i)
        //     cout<<data[i]<<endl;
        if(data[index]<data[end]){
            ++small;//small的下一个指向大于当前指定界定值
            if(small!=index)
                swap(data[index],data[small]);
        }
    }
    ++small;
    swap(data[end],data[small]);
    return small;
}

// int find_first_k(vector<int > data,int k){
//     if(data.empty()||k>(data.size()-1))
//         throw -1;
//     //TODO
//     return 0
// }
int check_morethanhalf(vector<int> &data,int number){
    int time=0;
    for(int i=0;i<data.size();++i){
        if(data[i]==number)
            ++time;
    }
    bool ismorethanhalf=true;
    if(time*2<=data.size())
        ismorethanhalf=false;
    return ismorethanhalf;

}

//实现的是找到中位数，超过一半次数的肯定是中位数，但中位数不一定就是超过一般次数的，所以需要check_morethanhal函数进行确认
//如果不用中位数的方法，要统计每一个的出现次数，然后确认超过一半的
int morethanhalf(vector<int> &numbers){
    if(numbers.empty())
        throw -1;

    int middle=numbers.size()>>2;//中位数

    int begin =0;
    int end=numbers.size()-1;
    int index=partition(numbers,begin,end);
    while(index!=middle){
        if(index>middle){
            end=index-1;
            index=partition(numbers,begin,end);
        }
        else{
            begin=index+1;
            index=partition(numbers,begin,end);
        }
    }
    int result=numbers[middle];
    bool flag=check_morethanhalf(numbers,result);
    if(!flag)
        result=0;
    return result;

}
int morethanhalf_nice(vector<int > numbers){
    if(numbers.empty())
        return 0;
    int result=numbers[0];
    int times=1;
    for(int i=0;i<numbers.size();++i){
        if(times==0){
            result=numbers[i];
            times=1;
        }
        else if(result!=numbers[i])
            --times;
        else if(result==numbers[i])
            ++times;
    }
    bool flag=check_morethanhalf(numbers,result);
    if(!flag)
        result=0;
    return result;
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL)); 
    int v1[]={7,2,6,4,5,3,9};
    int arraysize;
    GET_ARRAY_LEN(v1,arraysize);
    std::vector<int> v(v1,v1+arraysize);
    // int result=partition(v,0,v.size()-1);
    // cout<<"End"<<endl;
    // cout<<result<<endl;
    int result=morethanhalf(v);
    cout<<"result: "<<result<<endl;
    cout<<"-------------"<<endl;
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<endl;
    return 0;
}
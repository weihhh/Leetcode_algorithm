#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<time.h>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;


class Solution {
public:
    int RandomInRange(int start,int end){
        //[start,end),rand返回无符号整数
        return (rand() % (end-start))+ start;
    }

    //small指向小于指定值的最后一个数，++后就是大于等于指定值的，让index先行去找小于的，然后和++small交换，则将小的换到前面
    int partition(vector<int> &data,int start,int end){
        cout<<"start: "<<start<<"end: "<<end<<endl;
        if(data.empty()||start<0||end>data.size()-1||start>end)
            throw -1;
        if(start==end)
            return start;
        int index=RandomInRange(start,end);//这里unsigned 转换为int，隐患
        cout<<"random index: "<<index<<endl;
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

    void quick_sort(vector<int> &input,int begin,int end) {
        if(input.empty()||begin==end||begin<0||end>input.size()||begin>end)
            return ;
        int index=partition(input,begin,end);
        quick_sort(input,begin,index-1);
        quick_sort(input,index+1,end);
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL)); 
    // int v1[]={7,2,6,4,5,3,9};
    // int v1[]={1,1,1,1,1};
    // int v1[]={};
    int v1[]={2,1,3};
    int arraysize;
    GET_ARRAY_LEN(v1,arraysize);
    std::vector<int> v(v1,v1+arraysize);
    // int result=partition(v,0,v.size()-1);
    // cout<<"End"<<endl;
    // cout<<result<<endl;
    Solution st;
    st.quick_sort(v,0,v.size()-1);
    // cout<<"result: "<<result<<endl;
    cout<<"-------------"<<endl;
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<endl;
    return 0;
}
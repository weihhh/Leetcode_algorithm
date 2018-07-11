#include<iostream>
#include<algorithm>
#include<vector>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
            return;
        int i=0,j=0,tmp=0;
        int size=array.size();
        while(i<size){
            while((i<size)&&((array[i]&0x1)==1))
                ++i;
            //找到第一个偶数
            cout<<"first even: "<<i<<endl;
            j=i+1;
            while(j<size&&((array[j]&0x1)==0))
                ++j;
            if(j<size){
                cout<<"first odd: "<<j<<endl;
                //找到第一个奇数
                tmp=array[j];
                cout<<"tmp: "<<tmp<<endl;
                //i-(j-1)后移一位,注意！！！！！！！！后移需要从后往前
                for(int place=j;place>i;--place)
                    array[place]=array[place-1];
                array[i]=tmp;
                ++i;
                for(int x=0;x<array.size();++x)
                    cout<<array[x]<<endl;
            }
            else
                //直到最后也未找到奇数
                break;
        }
    }
};

int main(){
    Solution st;
    int v1[7]={2,4,6,1,3,5,7};
    int arraysize;
    GET_ARRAY_LEN(v1,arraysize);
    std::vector<int> v(v1,v1+arraysize);
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<endl;
    st.reOrderArray(v);
    cout<<"#############"<<endl;
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<endl;
}
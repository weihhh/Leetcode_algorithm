#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
    // string LeftRotateString(string str, int n) {
    //     int size =str.size();
    //     if(size<2)
    //         return str;
    //     queue<char> q;
    //     for(int i=0;i<size;++i){
    //         q.push(str[i]);
    //     }
    //     int tmp=n;
    //     while(tmp>0){
    //         char x=q.front();
    //         q.pop();
    //         q.push(x);
    //         --tmp;
    //     }
    //     tmp=0;
    //     while(!q.empty()){
    //         str[tmp]=q.front();
    //         q.pop();
    //         tmp++;
    //     }
    //     return str;
    // }
    string LeftRotateString(string str, int n){
        int size =str.size();
        if(size<2||n<1)
            return str;
        int left=n%size;
        cout<<left<<endl;
        if(left==0)
            return str;
        ReverseWord(str,0,left-1);
        ReverseWord(str,left,size-1);//目标时将前left字符放到末尾去，所以首先翻转各个部分，如果先反转整体，则函数中序号要改变
        ReverseWord(str,0,size-1);
        return str;
    }

    void ReverseWord(string &str,int begin,int end){
        while(begin<end){
            swap(str[begin],str[end]);
            ++begin;
            --end;
        }
    }
};

int main(){
    Solution st;
    int v1[7]={2,4,6,1,3,5,7};
    int arraysize;
    GET_ARRAY_LEN(v1,arraysize);
    std::vector<int> v(v1,v1+arraysize);
    string str="abcdef";
    cout<<str<<endl;
    // for(int i=0;i<v.size();++i)
    //     cout<<v[i]<<endl;
    string result=st.LeftRotateString(str,2);
    cout<<"#############"<<endl;
    cout<<result<<endl;
}
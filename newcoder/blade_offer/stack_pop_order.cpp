#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int allsize=popV.size();
        int i=0;
        vector<int>::iterator first=popV.begin();
        vector<int>::iterator find_result,tmp=pushV.begin();
        stack<int> help;
        while(first!=popV.end()){
            cout<<"bug 1"<<endl;
            if(help.empty()||(*first!=help.top())){
                find_result=find(tmp,pushV.end(),*first);
                cout<<"find_result: "<<*find_result<<endl;
                cout<<"tmp: "<<*tmp<<endl;
                if(find_result==pushV.end())
                    return false;
                while(tmp!=find_result){
                    cout<<"bug 2"<<endl;
                    help.push(*tmp);
                    ++tmp;
                }
                ++tmp;
            }
            else
                help.pop();
            ++first;
        }
        return true;      
    }
};

int main(){
    Solution st;
    int v1[5]={1,2,3,4,5};
    int v2[5]={4,5,3,2,1};
    int arraysize;
    GET_ARRAY_LEN(v1,arraysize);
    std::vector<int> data1(v1,v1+arraysize);
    std::vector<int> data2(v2,v2+arraysize);
    for(int i=0;i<data1.size();++i)
        cout<<data1[i]<<endl;
    for(int i=0;i<data1.size();++i)
        cout<<data2[i]<<endl;
    bool result=st.IsPopOrder(data1,data2);
    cout<<"#############"<<endl;
    cout<<result<<endl;

}
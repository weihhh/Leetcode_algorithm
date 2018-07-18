#include<iostream>
#include<algorithm>
#include<vector>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        std::vector<int> result;
        if(array.size()<2)
            return result;
        vector<int>::iterator small=array.begin(),big=array.end()-1;
        while((*small+*big)!=sum&&small!=big){
            if((*small+*big)<sum)
                ++small;
            else
                --big;
        }
        if(small!=big){
            result.push_back(*small);
            result.push_back(*big);
        }
        return result;
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
    std::vector<int> result;
    result=st.FindNumbersWithSum(v,5);
    cout<<"#############"<<endl;
    for(int i=0;i<result.size();++i)
        cout<<result[i]<<endl;
}
#include<iostream>
#include<algorithm>
#include<vector>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()<5)
            return false;
        bool result=false;
        vector<int>::iterator begin=numbers.begin(),end=numbers.end(),walker=numbers.begin();
        //需要先排序
        sort(begin,end);
        for(int i=0;i<numbers.size();++i)
            cout<<numbers[i]<<endl;
        int kings=0;
        int lag=0;
        
        while(walker!=end){
            if(*walker==0){
                ++kings;
                ++walker;
                continue;
            }
            if(walker!=begin&&(*(walker-1))!=0){
                if(*(walker-1)==*walker)
                    //一旦相等，则不可能连排
                    return result;
                else{
                    if((*walker)-(*(walker-1))!=1){
                        cout<<*walker-(*(walker-1));
                        lag+=*walker-(*(walker-1))-1;
                    }
                }
            }
            ++walker;
        }
        cout<<"lag: "<<lag<<endl;
        cout<<"kings: "<<kings<<endl;
        if(lag<=kings)
            result=true;
        return result;
    }
};


int main(){
    Solution st;
    int v1[5]={2,4,6,0,3};
    int arraysize;
    GET_ARRAY_LEN(v1,arraysize);
    std::vector<int> v(v1,v1+arraysize);
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<endl;
    bool result=st.IsContinuous(v);
    cout<<"#############"<<endl;
    cout<<result<<endl;
}
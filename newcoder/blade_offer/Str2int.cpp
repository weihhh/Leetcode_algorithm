#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        string::iterator walker=str.end()-1,begin=str.begin();
        int bit=0;
        int result=0;
        while(walker!=begin){
            if((*walker-'0'>=0)&&(*walker-'0')<10){
                result+=(*walker-'0')*pow(10,bit);
                cout<<(*walker-'0')*pow(10,bit)<<endl;
            }
            else 
                return 0;
            --walker;
            ++bit;
        }
        if(*walker=='+')
            return result;
        else if(*walker=='-')
            return -result;
        result+=(*walker-'0')*pow(10,bit);
        return result;
    }
};


int main(){
    Solution st;
    string input="+123";
    
    int result=st.StrToInt(input);
    cout<<"#############"<<endl;
    cout<<result<<endl;
}
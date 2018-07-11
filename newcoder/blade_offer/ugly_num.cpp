#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
   int GetUglyNumber_Solution(int index) {
        if (index < 7)return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i;//t2表示只有序号大于t2的数乘以2才能大于当前最大丑数
        for (i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2)t2++;
            if (res[i] == res[t3] * 3)t3++;
            if (res[i] == res[t5] * 5)t5++;
        }
        return res[index - 1];
    }
};


int main(int argc, char const *argv[])
{

    Solution st;
    // st.quick_sort(v,0,v.size()-1);
    int result=st.GetUglyNumber_Solution(7);
    cout<<"result: "<<result<<endl;
    // cout<<"-------------"<<endl;
    // for(int i=0;i<v.size();++i)
    //     cout<<v[i]<<endl;
    return 0;
}
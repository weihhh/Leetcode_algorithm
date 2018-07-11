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
    int PowerBase10(unsigned int n){
        int result=1;
        for(unsigned int i=0;i<n;++i)
            result*=10;
        return result;
    }

    int NumberOf1Between1AndN_Solution(int n)
    {
        /*
        int all_one=0;
        for(int i=1;i<=n;++i){
            all_one+=cal_one(i);
        }
        return all_one;
    }
    int cal_one(int num){
        int now_one=0;
        while(num){
            if(num%10==1)
                now_one+=1;
            num/=10;
        }
        return now_one;
    }
    */
    if(n<1)
        return 0;
    char strN[50];
    sprintf(strN,"%d",n);//转换n为字符串形式
    return cal_one(strN);
    }
    int cal_one(char* strN){
        cout<<"one!"<<endl;
        if(strN==NULL||*strN<'0'||*strN>'9'||*strN=='\0')
            return 0;
        int first_num=*strN-'0';//第一个数字
        unsigned int length=static_cast<unsigned int>(strlen(strN));//整个数字位数
        //注意位数为1的时候要特殊处理！！！！！！！！！！！，否则下面length-2会出错
        if(length==1&&first_num==0)
            return 0;
        if(length==1&&first_num>0)
            return 1;
        //编程过程假设一个数21345
        int first_digit_num=0;
        if(first_num>1){
            //第一位大于1的话肯定会有1000-1999这样的1000个数或者10000-19999这样的10000个数
            //当前位个数减一
            first_digit_num+=PowerBase10(length-1);
        }
        else if(first_num==1){
            //如果第一位是1，例如1234，则第一位为1的个数为234+1
            first_digit_num+=atoi(strN+1)+1;//atoi空字符串返回0
        }
        cout<<"before!"<<endl;
        int numOtherdigit=first_num*(length-1)*PowerBase10(length-2);//
        int numRecursive=cal_one(strN+1);
        cout<<"after!"<<endl;
        return first_digit_num+numOtherdigit+numRecursive;

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
    // st.quick_sort(v,0,v.size()-1);
    int result=st.NumberOf1Between1AndN_Solution(6);
    cout<<"result: "<<result<<endl;
    // cout<<"-------------"<<endl;
    // for(int i=0;i<v.size();++i)
    //     cout<<v[i]<<endl;
    return 0;
}
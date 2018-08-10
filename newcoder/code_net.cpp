#include <iostream>
#include<stdio.h>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>   // std::greater
using namespace std;

void fre() { freopen("input.in", "r", stdin); freopen("output.out", "w", stdout); }
#define MS(x, y) memset(x, y, sizeof(x))


template<typename T>
void Quick_sort(T *array,int length){
    partition_sort(array,0,length-1);
}



void solvecase(){
    string code;
    string special=("!@#$%^&*()_-=+[]{},.<>/?");
    string lowcase=("qwertyuiopasdfghjklzxcvbnm");
    string upcase=("QWERTYUIOPASDFGHJKLZXCVBNM");
    string number=("1234567890");
    string weak[6]={"password","admin","qwerty","hello","iloveyou","112233"};
    cin>>code;
    bool flag=false;
    //长度检查
    if(code.size()>=8){
        //判断是否有特殊字符、数字、字母
        if(code.find_first_of(special)!=string::npos){
            if(code.find_first_of(lowcase)!=string::npos){
                if(code.find_first_of(upcase)!=string::npos){
                    if(code.find_first_of(number)!=string::npos){
                        //连续三个数字等差
                        int num=0;
                        int gap=-1;
                        char last;
                        bool nice=true;
                        for(int i=1;i<=code.size()-1;++i){
                            if(isdigit(code[i])&&isdigit(code[i-1])&&isdigit(code[i+1])){
                                //此处遗漏ascill码相邻非数字情况
                                if(code[i]-code[i-1]==code[i+1]-code[i]){
                                    nice=false;
                                }
                            }
                        }
                        if(nice==true){
                            //弱密码
                            bool nice_2=true;
                            for (int i = 0; i < 6; ++i)
                            {
                                if(code.find(weak[i])!=string::npos){
                                    nice_2=false;
                                }
                            }
                            // if(nice_2){
                            //     flag=true;
                            // }
                            if(nice_2){
                                bool nice_3=true;
                                for (int i = 1; i < code.size()-1; ++i)
                                {
                                    if(isalpha(code[i-1])&&isalpha(code[i+1])&&isalpha(code[i])&&(code[i]-code[i-1]==1)&&(code[i]-code[i-1]==code[i+1]-code[i])){
                                        nice_3=false;
                                    }
                                }
                                if(nice_3){
                                    flag=true;
                                }
                            }
    

                        }
                    }
                }
            }
        }
    }
    if(flag==true){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}

int main() {
    fre();//测试使用
    int casenum,casei;
    scanf("%d",&casenum);
    // cout<<casenum<<endl;
    for(casei=1;casei<=casenum;++casei){
        solvecase();
        // cout<<answer<<endl;
    }
    return 0;
}

#include <iostream>
#include<stdio.h>
#include <map>
using namespace std;

void fre() { freopen("input.in", "r", stdin); freopen("output.out", "w", stdout); }

map<int,int> Map;//用于记录出现次数
const int MAXN=200+5;
const int MAXT=10+5;
int id[MAXN],ans[MAXN];//存放历史出现id数，最后返回的答案

void solvecase(){
    int ids;
    int ans_num=0;
    Map.clear();
    scanf("%d",&ids);
    for(int i=0;i<ids;++i){
        cin>>id[i];
    }
    for(int i=ids-1;i>=0;--i){
        if(Map[id[i]]==0){//map的下标取法，若元素不存在，则值初始化一个默认
            Map[id[i]]=1;
            //逆序第一次出现，则填入ans
            ans[ans_num++]=id[i];
        }
    }
    for(int i=0;i<ans_num;++i){
        if(i==ans_num-1)
            cout<<ans[i]<<endl;
        else
            cout<<ans[i]<<" ";
    }

}

int main() {
    fre();
    int casenum,casei;
    scanf("%d",&casenum);

    for(casei=1;casei<=casenum;++casei){
        solvecase();
    }
    return 0;
//     int a,b;
//     while(cin >> a >> b)//注意while处理多个case
//         cout << a+b << endl;
}
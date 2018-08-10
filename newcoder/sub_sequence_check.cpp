#include <iostream>
#include<stdio.h>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>   // std::greater
using namespace std;

void fre() { freopen("input.in", "r", stdin); freopen("output.out", "w", stdout); }
#define MS(x, y) memset(x, y, sizeof(x))

/*------------------------   内置快速排序    -----------------*/

template<typename T>
void Buildin_quick_sort_(T *array,int length){
    // sort(array,array+length,std::greater<int>());//从大到小
    sort(array,array+length,std::less<int>());//从大到小
}

void solvecase(){
    string ori;
    string sub;
    cin>>ori;
    cin>>sub;
    if(sub.size()==0){
        cout<<"Yes"<<endl;
    }
    std::size_t found=0;
    int size_now=0;
    while(size_now!=sub.size())
    {
        found=ori.find_first_of(sub[size_now]);
        if(found==string::npos)
            break;
        ori=ori.substr(found+1);
        size_now++;
    }
    if(size_now==sub.size())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

/*------------------------   多例模式   -----------------*/
// int main() {
//     fre();//测试使用
//     int casenum,casei;
//     scanf("%d",&casenum);
//     // cout<<casenum<<endl;
//     for(casei=1;casei<=casenum;++casei){
//         solvecase();
//         // cout<<answer<<endl;
//     }
//     return 0;
// }

/*------------------------   单例模式    -----------------*/
int main() {
    fre();//测试使用
    solvecase();
    return 0;
}
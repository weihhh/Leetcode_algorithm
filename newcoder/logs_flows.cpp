#include <iostream>
#include<stdio.h>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void fre() { freopen("input.in", "r", stdin); freopen("output.out", "w", stdout); }
#define MS(x, y) memset(x, y, sizeof(x))


int answer=0;

void solvecase(){
    int m,n;
    cin>>m;//流量记录数量
    std::vector<string> logs(m);
    std::vector<int> flows(m);
    string a,b,c,d;
    int k;
    for(int i=0;i<m;++i){
        //读取输入记录,年月日 时刻 流量
        cin>>a>>b>>k;
        logs[i]=a.substr(6)+a.substr(0,2)+a.substr(3,5)+b;
        flows[i]=k;
    }
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c>>d;
        a = a.substr(6) + a.substr(0, 2) + a.substr(3, 5) + b;//起始时间
        c = c.substr(6) + c.substr(0, 2) + c.substr(3, 5) + d;//结束时间
        //lower_bound 寻找第一个大于等于给定值的迭代器,upper_bound查找大于的
        int begin_time =  lower_bound(logs.begin(), logs.end(), a)-logs.begin();
        int end_time =  upper_bound(logs.begin(), logs.end(), c)-logs.begin();
        // cout<<"end_time: "<<end_time<<endl;
        answer=0;
        for(int j=begin_time;j<end_time;++j){
            answer+=flows[j];
        }
        cout<<answer<<endl;
    }

}

int main() {
    fre();//测试使用
    solvecase();
    return 0;
//     int a,b;
//     while(cin >> a >> b)//注意while处理多个case
//         cout << a+b << endl;
}
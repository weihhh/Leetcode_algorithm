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
    string blank;
    cin>>code;
    cin>>blank;
    int Q,N,M;
    cin>>Q>>N>>M;
    std::vector<int> kill_score[M+1];
    std::vector<pair<pair<int,int>,int>> rank;
    std::vector<pair<int,pair<string,string>> kills[N];
    std::map<string,int> allscore;
    for (int i = 0; i < N; ++i)
    {
        cin>>rank[i].first.first>>rank[i].first.second>>rank[i].second;
    }
    for (int i = 0; i < M+1; ++i)
    {
        cin>>kill_score[i];
    }
    int A,B;
    cin>>A>>B;
    for (int i = 0; i < Q-1; ++i)
    {
        cin>>kills[i].first>>kills[i].second.first>>kills[i].second.second;
    }

    //计算排名
    for (int i = 0; i<Q-1; ++i)
    {
        allscore.insert(pair<string,int>(kills[i].second.second))
        /* code */
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

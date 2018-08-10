#include <iostream>
#include<stdio.h>
#include <map>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

void fre() { freopen("input.in", "r", stdin); freopen("output.out", "w", stdout); }
#define MS(x, y) memset(x, y, sizeof(x))

const int MAXM=99+5;
const int MAXN=99+5;
const int MAXT=9+5;
const int MAXLEN=9+1;
char Map[MAXM][MAXN];
char str[MAXLEN];
int DIRECTION[3][2]={{0,1},{1,0},{1,1}};
int answer=0;

//确保不越界
bool flag(int x, int y,int m,int n) {
    if(x >= m || x < 0 || y >= n || y < 0) {
        return false;
    }
    return true;
}

void solvecase(){
    int m,n;
    scanf("%d %d",&m,&n);
    // for(int i=0;i<m;++i){
    //     cin>>Map[i];
    // }
    

    MS(Map, 0);
    for (int i = 0; i < m; ++i)
    {
        // cout<<"input: "<<i<<endl;
        scanf("%s", Map[i]);
    }
    cin>>str;
    int len=strlen(str),num=0;
    cout<<"strlen: "<<len<<endl;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(Map[i][j]==str[0]){
                // cout<<"once!"<<endl;
                for(int direction=0;direction<3;++direction){//三个方向
                    int tx=i,ty=j,ok=1;
                    for(int str_i=1;str_i<len;++str_i){//目标字符长度
                        tx+=DIRECTION[direction][0];
                        ty+=DIRECTION[direction][1];
                        if(!flag(tx,ty,m,n)||Map[tx][ty]!=str[str_i]){
                            ok=0;
                            break;
                        }
                    }
                    if(ok==1)
                        answer++;
                }
                
            }
        }
    }
}

int main() {
    fre();
    int casenum,casei;
    scanf("%d",&casenum);
    // cout<<casenum<<endl;
    for(casei=1;casei<=casenum;++casei){
        solvecase();
        cout<<answer<<endl;
        answer=0;
    }
    return 0;
//     int a,b;
//     while(cin >> a >> b)//注意while处理多个case
//         cout << a+b << endl;
}
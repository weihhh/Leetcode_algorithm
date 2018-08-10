#include <iostream>
#include<stdio.h>
using namespace std;

void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }
const int N = 0, M = 0, Z = 1e9 + 7, inf = 0x3f3f3f3f;


void simple(){
    int h,m,s;
    scanf("%d:%d:%d",&h,&m,&s);//第一个非空白字符
    //如果超过正常的数字，则将十位数变为0即可
    if(h>=24)
        h%=10;
    if(m>=60)
        m%=10;
    if(s>=60)
        s%=10;
    printf("%02d:%02d:%02d\n",h,m,s );

}


void complex()
{
    
    char S[10];
    int a[10], b[10];
    struct ANS
    {
        int h, m, s;
    }ans;
    scanf("%s", S);
    a[0] = S[0] - 48;
    a[1] = S[1] - 48;
    a[2] = S[3] - 48;
    a[3] = S[4] - 48;
    a[4] = S[6] - 48;
    a[5] = S[7] - 48;
    //60 * 60 * 24
    int ansdif = inf;
    for (int i = 0; i < 24; ++i)
    {
        b[0] = i / 10;
        b[1] = i % 10;
        for (int j = 0; j < 60; ++j)
        {
            b[2] = j / 10;
            b[3] = j % 10;
            for (int k = 0; k < 60; ++k)
            {
                b[4] = k / 10;
                b[5] = k % 10;
 
                int dif = 0;
                for (int u = 0; u <= 5; ++u)
                {
                    dif += (a[u] != b[u]);
                }
                if (dif < ansdif)
                {
                    ansdif = dif;
                    ans = { i,j,k };
                }
            }
        }
    }
    printf("%02d:%02d:%02d\n", ans.h, ans.m, ans.s);
}
int main() {
    int casenum,casei;
    scanf("%d",&casenum);

    for(casei=1;casei<=casenum;++casei){
        simple();
    }
    return 0;
//     int a,b;
//     while(cin >> a >> b)//注意while处理多个case
//         cout << a+b << endl;
}
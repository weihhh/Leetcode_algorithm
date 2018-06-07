#include <iostream>
#include <math.h>  
using namespace std;
#define LL long long  
int n;
int v;
LL a[33];
int cnt=0;

void dsf(int snack, LL v_now ){
    if(snack==n){
        ++cnt;
        return;
    }
    // 如果没有满的话，可以在装进当前零食后继续放之后，
    // 装的方法数会更多，否则直接进行下一步，当前零食不放
    if(v_now+a[snack]<=v){
        dsf(snack+1,v_now+a[snack]);
    }
    dsf(snack+1,v_now);
}

int main(int argc, char const *argv[])
{
    cin>>n>>v; 
    int i;
    long total=0;
    //cout<<"n: "<<n<<"v: "<<v<<endl;
    for(i=0;i<n;i++){  
        cin>>a[i];
        total+=a[i];
        //cout<<a[i]<<endl;
    } 
    // 重点，如果总零食体积小于书包，则直接使用公式，否则超时
    if(total<=v){
        cnt=pow(2,n);
    }
    else{
    // cout<<"ok!"<<endl;
    dsf(0,0); 
    }
    cout<<cnt<<endl;
    return 0;
}
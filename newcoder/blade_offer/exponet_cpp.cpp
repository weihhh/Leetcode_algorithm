#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        //return pow(base,exponent);
        //异常情况,0,1为底,0,1为指数
        if(equal(base,0.0)||equal(base,1.0)||exponent==1)
            return base;
        if(exponent==0)
            return 1.0;
        //先计算正数情况，注意abs
        double result=1;
        //循环方法
        // for(int i=0;i<abs(exponent);++i){
        //     result*=base;
        // }
        //快速方法
        result=power_unsigned_best(base,abs(exponent));
        cout<<result<<endl;
        //指数负数
        if(exponent<0)
            result=1.0/result;
        return result;
    }

    bool equal(double num1,double num2){
        if((num1-num2)<0.00001&&(num1-num2)>0.00001)
            return true;
        return false;
    }
    double power_unsigned_best(double base,unsigned int exponent){
        cout<<"exponent: "<<exponent<<endl;
        if(exponent==0)
            return 1.0;
        if(exponent==1)
            return base;
        double result=power_unsigned_best(base,exponent>>1);
        result*=result;
        if(exponent&0x1==1)//二进制最后 一位为1，则为奇数,需要多乘以次base
            result*=base;
        return result;
    }
};

int main(){
    unsigned int testi=3;
    cout<<(testi>>2)<<endl;
    Solution st;
    double result=st.Power(2,3);
    cout<<result<<endl;
}
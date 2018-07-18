class Solution {
public:
    int rectCover(int number) {
        int result[3]={0,1,2};
        if(number<3)
            return result[number];
        int fib0=1,fib1=2,fibn=0;
        //四格即可有两种选择，剩余一个2*1，没有变化，只能是竖着放，所以f(n-1),两个2*1，则可以竖着，可以横着，但竖着已经包含再f(n-1)中，所以f(n-2)
        //综合的f(n)=f(n-1)+f(n-2)
        for(int i=3;i<=number;++i){
            fibn=fib0+fib1;
            fib0=fib1;
            fib1=fibn;
        }
        return fibn;
    }
};
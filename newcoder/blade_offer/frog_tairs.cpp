class Solution {
public:
    int jumpFloor(int number) {
        int result[3]={0,1,2};
        if(number<3)
            return result[number];
        int fib0=1,fib1=2,fibn=0;
        for(int i=3;i<=number;++i){
            fibn=fib0+fib1;
            fib0=fib1;
            fib1=fibn;
        }
        return fibn;
    }
};
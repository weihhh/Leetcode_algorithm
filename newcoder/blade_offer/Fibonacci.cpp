class Solution {
public:
    int Fibonacci(int n) {
        int result[2]={0,1};
        if(n<2)
            return result[n];
        int fib0=0,fib1=1,fibn=0;
        for(int i=2;i<=n;++i){
            fibn=fib0+fib1;
            fib0=fib1;
            fib1=fibn;
        }
        return fibn;
    }
};
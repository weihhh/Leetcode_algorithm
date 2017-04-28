#include <iostream>
using namespace std;
#include <math.h>


class Solution {
public:
    int findNthDigit(int n) {
       if(n<=9)
       {
            return n;
       } 
       long max=9,x=1;
       while(n>x*max)
       {
            n=n-x*max;
            x++;
            max*=10;    
       }
       int index=n%x;
       long num=1;
       if(index==0)
       {
        index=x;
       }
        for (int i = 1; i < x; i ++)
            num *= 10;
        num += (index == x) ? n / x - 1 : n / x;
        for (int i = index; i < x; i ++)
            num /= 10;
        return num % 10;
    }
};
int main()
{
Solution test;
int result=test.findNthDigit(1000000000);
cout<<result<<endl;
}



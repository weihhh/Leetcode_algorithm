class Solution {
public:
    int findNthDigit(int n) {
       if(n<=9)
       {
            return n;
       } 
       int x=1;
       int max=9;
       while(n>max)
       {
            x++;
            n=n-max;
            max=x*9*int(pow(10,x-1));    
       }
       int a=0,b=9*int(pow(10,x-1));
       while(a!=b&&b-a!=1)
       {
           if(n<(a+b)/2*x)
            {
                b=(a+b)/2;
            }
            else if(n>(a+b)/2*x)
            {
                a=(a+b)/2;
            }
            else 
            {
                a=b=(a+b)/2;
                n=n-(a-1)*x;
                int result=((int(pow(10,x-1))+a-1)/int(pow(10,x-n)))%10;
                return result;
            } 
       }
       
       n=n-a*x;
       int result=((int(pow(10,x-1))+a)/int(pow(10,x-n)))%10;
       return result;

    }
};




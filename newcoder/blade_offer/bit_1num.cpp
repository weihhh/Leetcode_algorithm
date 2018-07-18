class Solution {
public:
    int  NumberOf1(int n) {
        int size=sizeof(n)*8;
        int tmp=0,sum1=0;
        for(int i=size-1;i>=0;--i){
            tmp=n>>i;
            tmp=tmp&1;
            if(tmp==1)
                sum1+=1;
        }
        return sum1;

     }
};

############### best
class Solution {
public:
    int  NumberOf1(int n) {
        //补码表示负数，所有位取反再加一
        int count=0;
        while(n){
            ++count;
            n&=(n-1);//减一再相与即最右边的1变为0
        }
        return count;

     }
};
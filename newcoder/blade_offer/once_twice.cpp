class Solution {
public:
    unsigned int find_nonzero(int num){
        //从右往左找到第一个非零位
        int index=0;
        while(((num&1)==0)&&(index<8*sizeof(int))){//&1==0表示最后一位为0，index小于整形最大位
            num=num>>1;
            ++index;
        }
        return index;
    }
    bool is_nonzero(int num,unsigned int index){
        num=num>>index;
        return (num&1);
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty()||data.size()<2)
            return ;
        //依次异或,注意0异或任何数为那个数自身
        int len=data.size();
        int exclusive_or=0;
        for(int i=0;i<len;++i){
            exclusive_or^=data[i];
        }
        //判断从右往左第一个二进制1位置，出现两次的数互相抵消，对于每个位置贡献均为0，
        //此时exclusive_or的值为只出现一次的两个数的异或结果
        // 只出现一次的数一定不相同，所以肯定有一位以上非零，则这个位置上原始两个数肯定不一样
        // 对于出现两次的数，相同的数同一位置肯定相同，所以按照这个位置分两个组，出现两次的数肯定分到同一组
        unsigned int notzero_bit=find_nonzero(exclusive_or);
        *num1=*num2=0;
        for(int j=0;j<len;++j){
            if(is_nonzero(data[j],notzero_bit))
                *num1^=data[j];
            else
                *num2^=data[j];
        }
    }
};
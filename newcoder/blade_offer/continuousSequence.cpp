class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        int small=1,big=2;
        int now_sum=3;
        int middle=(sum+1)/2;//例如sum=7,sum/2=3,但是3+4=7，所以需要+1防止
        if(sum<now_sum)
            return result;
        while(small<middle){//如果small大于一半，那么再加上一个比small大的肯定不可能和位sum
            if(now_sum==sum){
                std::vector<int> tmp;
                int tmp_index=small;
                while(tmp_index<=big){
                    tmp.push_back(tmp_index);
                    ++tmp_index;
                }
                result.push_back(tmp);
                now_sum+=(++big);
            }
            if(now_sum<sum){
                now_sum+=(++big);
            }
            else{
                //如果当前sum太大，需要前面删减一个数 
                now_sum-=small++;
            }
        }
        return result;
    }
};
class Solution {
public:
    int max_global=0;
    //help 给出以end为尾的子数组和
    int help(std::vector<int> &v,int end){
        if(end==0)
            return v[0];
        int nowmax=0;
        int tmp=help(v,end-1);
        if((tmp+v[end])<v[end])
            nowmax=v[end];
        else
            nowmax= tmp+v[end];
        if(nowmax>max_global)
            max_global=nowmax;
        return nowmax;
    }
    int FindGreatestSumOfSubArray(vector<int> array) {
        // int max_subsum=array[0];
        max_global=array[0];
        if(array.empty())
            return max_global;
        int end=array.size()-1;
        help(array,end);
        return max_global;
    }
};
/*
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        //子数组要保持连续，不同于子序列
        int max_subsum=array[0];
        int now_sum=0;
        if(array.empty())
            return max_subsum;
        std::vector<int>::iterator walker=array.begin();
        for(;walker!=array.end();++walker){
            if((now_sum+*walker)<*walker)//如果当前和加上现在的数还不如当前数，说明之前和为负数，重新选择子数组起点
                now_sum=*walker;
            else{
                now_sum+=*walker;
            }
            //上述过程保证了当前数之前为至今可能最大的连续和
            if(now_sum>max_subsum)
                max_subsum=now_sum;
        }
        return max_subsum;
    }
};
*/
class Solution {
public:
    long long help(std::vector<int> &data,std::vector<int> &copy,int start,int end){
        if(start==end){
            copy[start]=data[start];
            return 0;
        }
        int middle_len=(end-start)/2;//start+middle
        long left=help(copy,data,start,start+middle_len);//注意这里传入顺序有改变，因为每次排序后的新数组都是存储在copy对应位置，
        long right=help(copy,data,start+middle_len+1,end);
        int i=start+middle_len;//前半段最后一个数字
        int j=end;//后半段最后一个数字
        int indexcopy=end;
        long long count=0;
        while(i>=start&&j>=start+middle_len+1){
            if(data[i]>data[j]){
                copy[indexcopy--]=data[i--];
                count=count+j-start-middle_len;//递归进行，默认左右两边都排好序
            }
            else{
                copy[indexcopy--]=data[j--];
            }
        }
        //下面两个for只有一个会循环运行，因为上面while保证其一不满足，即走到起点
        for(;i>=start;--i)
            copy[indexcopy--]=data[i];
        for(;j>=start+middle_len+1;--j)
            copy[indexcopy--]=data[j];
        return left+right+count;
    }
    int InversePairs(vector<int> data) {
        if(data.empty())
            return 0;
        int length=data.size();
        std::vector<int> copy;
        for(int i=0;i<length;++i)
            copy.push_back(data[i]);
        long long result=help(data,copy,0,length-1);
        return result%1000000007;
    }
};
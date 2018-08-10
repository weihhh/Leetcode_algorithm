class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        //队列实现，存储元素序号（不是元素本身，以记录当前位置）
        std::vector<int> result;
        int num_size=num.size();
        deque<int> slide_max;
        if(num_size!=0){
            for(int i=0;i<num_size;++i){
                if(!slide_max.empty()){
                    if(i>=slide_max.front()+size)//队列最大的序号不在窗口内,则弹出
                        slide_max.pop_front();
                    while(!slide_max.empty()&&num[slide_max.back()]<=num[i]){//新来的元素要从尾部一直比较到队头，小于新元素的元素肯定不会是之后窗口的最大值
                        slide_max.pop_back();
                    }
                }
                slide_max.push_back(i);
                if(i>=size-1)//形成一个窗口后才输出
                    result.push_back(num[slide_max.front()]);
            }
        }
        return result;
    }
};
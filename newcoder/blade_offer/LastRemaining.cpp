class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)
            return -1;
        list<int> loop;
        for(int i=0;i<n;++i){
            loop.push_back(i);
        }
        list<int>::iterator current=loop.begin();
        while(loop.size()>1){
            for(int j=1;j<m;++j){//从1开始，因为current初始就已经指向第一个人
                ++current;
                if(current==loop.end())
                    current=loop.begin();//到达末尾则回到头部模拟环形
            }
            // list<int>::iterator next=++current;
            // if(next==loop.end())
            //     next=loop.begin();
            // --current;
            // loop.erase(current);
            // current=next;
            current=loop.erase(current);
            if(current==loop.end())
                current=loop.begin();
        }
        return *current;
    }
};
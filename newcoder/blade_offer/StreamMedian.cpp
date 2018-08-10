class Solution {
public:
    multiset<int,greater<int>> max_heap;//最大堆存放较小的一堆数
    multiset<int,less<int>> min_heap;//最小堆
    void Insert(int num)
    {
        if(max_heap.empty()||num<*(max_heap.begin()))
            max_heap.insert(num);
        else
            min_heap.insert(num);
        //调整两个堆的数量
        if(max_heap.size()-min_heap.size()>1){
            int tmp=*(max_heap.begin());
            max_heap.erase(max_heap.begin());
            min_heap.insert(tmp);
        }
        else{
            int tmp=*(min_heap.begin());
            min_heap.erase(min_heap.begin());
            max_heap.insert(tmp);
        }
    }

    double GetMedian()
    { 
        if(max_heap.size()==min_heap.size())
            return (*(max_heap.begin())+*(min_heap.begin()))/2;
        else if(max_heap.size()>min_heap.size())
            return *(max_heap.begin());
        return *(min_heap.begin());
    }

};


class Solution {
    priority_queue<int, vector<int>, less<int> > p;//大顶堆
    priority_queue<int, vector<int>, greater<int> > q;//小顶堆
     
public:
    void Insert(int num){
        if(p.empty() || num <= p.top()) p.push(num);
        else q.push(num);
        if(p.size() == q.size() + 2) q.push(p.top()), p.pop();
        if(p.size() + 1 == q.size()) p.push(q.top()), q.pop();
    }
    double GetMedian(){ 
      return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};
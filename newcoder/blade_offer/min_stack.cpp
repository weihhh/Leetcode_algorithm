class Solution {
public:
    void push(int value) {
        data.push(value);
        if(min_assist.empty())
            min_assist.push(value);
        else{
            if(value<min_assist.top())
                min_assist.push(value);
            else
                min_assist.push(min_assist.top());
        }

    }
    void pop() {
        if(!data.empty()){
            data.pop();
            min_assist.pop();
        }
    }
    int top() {
        if(!data.empty())
            return data.top();
    }
    int min() {
        return min_assist.top();
    }
private:
    stack<int> data;
    stack<int> min_assist;
};
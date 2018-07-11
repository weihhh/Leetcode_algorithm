class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        //一直保证有一个stack为空
        if(stack2.empty()){
            while(!stack1.empty()){
                int data=stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        if(stack2.empty())
            cout<<'empty!'<<endl;
        int result=stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty())
            return "";
        sort(numbers.begin(),numbers.end(),cmp);//sort（a,b）cmp判断为真则a在前
        string res;
        for(int i=0;i<numbers.size();++i)
            res+=to_string(numbers[i]);
        return res;

    }
    static bool cmp(int a,int b){//这里static 必须 ，否则需要传入this指针
        string A=to_string(a)+to_string(b);
        string B=to_string(b)+to_string(a);
        //两个数数位一样，所以可以应用字符串比较的方式比较大小
        return A<B;
    }

};
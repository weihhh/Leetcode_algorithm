class Solution {
public:
    vector<string> Permutation(string str) {
        std::vector<string> v;
        if(str.size()==0)
            return v;

        int begin=0;
        help(str,begin,v);
        sort(v.begin(),v.end());
        return v;
    }
    void help(string& str,int begin,vector<string> &v){
        //递归到底层，输出，一路总是有一个变化，否则不会到底
        if(begin==str.size()-1){
            v.push_back(str);
            return;
        }
        //第一位与后面不相等的字符交换，然后之后所有位进行递归，
        //因第一位已经不同，后面只要到底就是一个不一样的字符串
        for(int i=begin;i<str.size();++i){
            if(str[begin]!=str[i]||i==begin){
                char tmp=str[i];
                str[i]=str[begin];
                str[begin]=tmp;
            }
            else
                continue;
            help(str,begin+1,v);//注意这里是begin+1
            //还原顺序，轮流交换
            char tmp=str[i];
            str[i]=str[begin];
            str[begin]=tmp;

        }
    }
};
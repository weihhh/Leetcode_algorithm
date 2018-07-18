class Solution {
public:
    string ReverseSentence(string str) {
        int size=str.size();
        if(size<2)
            return str;
        //首先翻转整个句子，这样连带单词也翻转
        ReverseWord(str,0,size-1);
        int begin=0,end=0;
        str+=' ';
        while(end<str.size()){
            if(str[end]!=' '){
                ++end;
                continue;
            }
            else{
                ReverseWord(str,begin,end-1);
                begin=end+1;
                ++end;
            }
        }
        str=str.substr(0,size);
        return str;
    }
    void ReverseWord(string &str,int begin,int end){
        while(begin<end){
            swap(str[begin],str[end]);
            ++begin;
            --end;
        }
    }
};
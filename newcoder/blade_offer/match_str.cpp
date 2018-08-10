class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //两个都是空指针，返回true
        if (pattern[0] == 0 && str[0] == 0)
            return true;
        //模式为空而目标中不空，则false
        if(*str=='\0' &&*pattern=='\0')
            return false;
        //目标字符串空，模式非空，比如模式“a*a*a*a*”,由于‘*’之前的元素可以出现0次，所以有可能匹配成功
        if(*(pattern+1)!='*'){
            //当前位下一个不是*，则当前位一定要匹配
            if(*str==*pattern||(*str!='\0'&&*pattern=='.'))
                return match(str+1,pattern+1);
            else
                return false;
        }
        else{
            //下一位位*，则pattern当前位可以不匹配，匹配的话两次机会
            if(*str==*pattern||(*str!='\0'&&*pattern=='.')){
                //match(str,pattern+2)表示*代表0个的情况
                //match(str+1,pattern)表示*代表多个
                return match(str+1,pattern)||match(str,pattern+2);
            }
            else
                //只能是忽略当前位
                return match(str,pattern+2);
        }


    }
};
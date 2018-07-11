class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty())
            return -1;
        string::iterator walker=str.begin();
        std::vector<int> hash_map(256,0);//8位char，256种可能,0初值
        while(walker!=str.end()){
            hash_map[*walker]+=1;
            ++walker;
        }
        walker=str.begin();
        int result=0;
        while(walker!=str.end()){
            if(hash_map[*walker]==1)
                break;
            result+=1;
            ++walker;
        }
        return result;
    }
};
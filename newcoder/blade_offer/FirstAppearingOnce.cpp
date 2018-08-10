class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        hasharray[ch-'\0']++;
        if(hasharray[ch-'\0']==1)
            //第一次出现,则放进队列，否则不需要
            data.push(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        //push进入队列时都为1，但是后续会增加，所以添加判断
        while(!data.empty()&&hasharray[data.front()]!=1)
            data.pop();
        if(data.empty())
            return '#';
        return data.front();
    }
    unsigned char hasharray[256];
    queue<char> data;
};
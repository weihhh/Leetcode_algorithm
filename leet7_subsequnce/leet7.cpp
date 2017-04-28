
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool nows;
        int nowt=0,ssize=s.size(),tsize=t.size();
        if(s=="")
        {
            return true;
        }
        for(int i=0;i<ssize;i++)
        {
            nows=false;
            for(int j=nowt;j<tsize;j++)
            {
                if(s[i]==t[j])
                {
                    nows=true;
                    nowt=j+1;
                    break;
                }
               
            }
            if(nows==false)
            {
                break;
            }

        }
        return nows;
    }
};

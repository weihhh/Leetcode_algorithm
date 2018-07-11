class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()||array[0].empty())
            return false;
        int rows=array.size();
        int columns=array[0].size();
        int i=0,j=columns-1;
        while((i<rows)&&(j>=0)){
            //始终保持右上角
            if(array[i][j]==target)
                return true;
            else if(array[i][j]>target)
                --j;
            else
                ++i;

        }
        return false;
    }
};
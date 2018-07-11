class Solution {
public:
    void print_start(int start,std::vector<std::vector<int> > &matrix,std::vector<int> &v){
        //从（start，start）开始打印一个顺时针
        //左到右一行
        int i=start,j=start;
        while(j<matrix[0].size()-start)
            v.push_back(matrix[i][j++]);
        j=matrix[0].size()-start-1;//回到最后一列
        ++i;//从下一行开始
        //末尾列从上到下
        while(i<matrix.size()-start)
            v.push_back(matrix[i++][j]);
        if((matrix[0].size()-start*2)==1)
            return;
        i=matrix.size()-start-1;//归位到最后一行
        // 末尾行从右到左
        --j;
        if((matrix.size()-start*2)!=1)
            while(j>=start)
                v.push_back(matrix[i][j--]);
        j=start;//归位到第一列
        --i;
        //第一列从下到上
        while(i>start)
            v.push_back(matrix[i--][j]);

    }

    vector<int> printMatrix(std::vector<std::vector<int> > matrix) {
        //开始点一定是（start，start）
        int start=0;
        int rows=matrix.size(),columns=matrix[0].size();
        std::vector<int> v;
        while((start*2<rows)&&(start*2<columns)){
            print_start(start,matrix,v);
            ++start;
        }
        return v;
    }

};

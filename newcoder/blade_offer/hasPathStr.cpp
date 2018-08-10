class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(str==NULL||rows<=0||cols<=0)
            return false;
        bool *log=new bool[rows*cols]();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++){
                if(matrix[i*cols+j]==str[0]){
                    if(isHsaPath(matrix,rows,cols,str,log,i,j))
                        return true;
                }
            }
        }
        return false;
    }
    bool isHsaPath(char* matrix, int rows, int cols, char* str,bool *log,int x,int y){
        if(*str=='\0')
            return true;
        if(x>=rows||y>=cols||x<0||y<0)
            return false;
        //确定是否访问过,且当前访问元素对应目标元素
        if(log[x*cols+y]||matrix[x*cols+y]!=*str)
            return false;
        //未访问过且对应相等
        log[x*cols+y]=true;
        bool sign=isHsaPath(matrix,rows,cols,str+1,log,x-1,y)
          ||isHsaPath(matrix,rows,cols,str+1,log,x+1,y)
          ||isHsaPath(matrix,rows,cols,str+1,log,x,y-1)
          ||isHsaPath(matrix,rows,cols,str+1,log,x,y+1);
        log[x*cols+y]=false;//访问完这个点需要释放
        return sign;


    }


};
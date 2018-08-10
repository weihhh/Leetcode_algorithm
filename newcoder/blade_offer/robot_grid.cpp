class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *flags=new bool[rows*cols]();//括号,初始化
        int count=moving(threshold,rows,cols,0,0,flags);
        return count;
    }
    int moving(int threshold,int rows,int cols,int x,int y,bool* flags){
        if(x<rows&&x>=0&&y<cols&&y>=0&&flags[x*cols+y]==false&&(get_num_sum(x)+get_num_sum(y)<threshold)){
            flags[x*cols+y]==true;
            return 1+moving(threshold,rows,cols,x+1,y,flags)+moving(threshold,rows,cols,x-1,y,flags)+moving(threshold,rows,cols,x,y+1,flags)+moving(threshold,rows,cols,x,y-1,flags);
        }
        return 0;
    }
    int get_num_sum(int num){
        int sum_positon=0;
        while(num){
            sum_positon+=num%10;
            num/=10;
        }
        return sum_positon;
    }


};
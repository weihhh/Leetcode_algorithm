class Solution {
public:
    void replaceSpace(char *str,int length) {
        //length 为数组总容量
        int i=0;
        int actual_len=0,space_num=0,new_len=0;
        int ori_end,new_end;
        if(str==NULL||length<=0)
            return ;
        while(str[i]!='\0'){
            ++actual_len;
            if(str[i]==' ')
                ++space_num;
            ++i;
        }
        //计算新长度
        new_len=actual_len+2*space_num;
        if(new_len>length)
            return;
        ori_end=actual_len;//ori_end指向\0
        new_end=new_len;
        while(ori_end!=new_end){
            if(str[ori_end]!=' ')
                str[new_end--]=str[ori_end--];
            else{
                --ori_end;
                str[new_end--]='0';
                str[new_end--]='2';
                str[new_end--]='%';
            }
        }
    }
};
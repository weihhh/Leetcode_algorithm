class Solution {
public:
    int getFirstK(vector<int> &data,int start,int end,int target){
        if(start>end)
            return -1;
        int middle_index=(end+start)/2;//注意这里是+
        int middle_data=data[middle_index];
        if(middle_data==target){
            if((middle_index>0&&data[middle_index-1]!=target)||middle_index==start){
                //midlle和目标值相等并且前一个不是目标值，说明midlle就是第一个
                return middle_index;
            }
            else{
                end=middle_index-1;
            }
        }
        else if(middle_data>target){
            //左边
            end=middle_index-1;
        }
        else
            start=middle_index+1;
        return getFirstK(data,start,end,target);
    }
    int getLastK(vector<int> &data,int start,int end,int target){
        if(start>end)
            return -1;
        int middle_index=(end+start)/2;
        int middle_data=data[middle_index];
        if(middle_data==target){
            if((middle_index<end&&data[middle_index+1]!=target)||middle_index==end){
                //midlle和目标值相等并且前一个不是目标值，说明midlle就是第一个
                return middle_index;
            }
            else{
                start=middle_index+1;
            }
        }
        else if(middle_data>target){
            //左边
            end=middle_index-1;
        }
        else
            start=middle_index+1;
        return getLastK(data,start,end,target);
    }
    int GetNumberOfK(vector<int> data ,int k) {
        int num=0;
        int length=data.size();
        if(!data.empty()){
            int first=getFirstK(data,0,length-1,k);
            int last=getLastK(data,0,length-1,k);
            if(first>-1&&last>-1)
                num=last-first+1;
        }
        return num;
    }
};
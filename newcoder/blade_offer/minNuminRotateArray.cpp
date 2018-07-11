#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;

        int length=rotateArray.size();
        int start=0,end=length-1;
        int index=start;//初始化为开头，应对前0个元素放置到末尾的情况
        while(rotateArray[start]>=rotateArray[end]){
            index=(start+end)/2;
            if(end-start<=1){
                index=end;
                break;
            }
            //如果三个位置的元素相等，则无法判断中间数属于那一部分，只能遍历寻找
            if(rotateArray[start]==rotateArray[index]&&rotateArray[index]==rotateArray[end]){
                sort(rotateArray.begin(),rotateArray.end());
                return rotateArray[0];
            }
            if(rotateArray[index]>=rotateArray[start])
                start=index;
            else if(rotateArray[index]<=rotateArray[end])
                end=index;
        }
        return rotateArray[index];    

    }
};

int main(){
    Solution s;
    //vector<int> num = {0,1,2,3,4,5};
    //vector<int> num = {4,5,6,7,1,2,3};
    vector<int> num = {2,2,2,2,1,2};
    int result = s.minNumberInRotateArray(num);
    // 输出
    cout<<result<<endl;
    return 0;
}
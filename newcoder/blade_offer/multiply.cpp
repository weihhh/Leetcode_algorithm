// class Solution {
// public:
//     vector<int> multiply(const vector<int>& A) {
//         int len=A.size();
//         vector<int> result(len,1);
//         if(A.empty())
//             return result;
//         std::vector<int> tmp1(len,1);
//         std::vector<int> tmp2(len,1);
//         for(int i=1;i<len;++i){//从1开始，因为下三角第一行0个元素
//             //左下角元素乘积
//             tmp1[i]=tmp1[i-1]*A[i-1];
//         }
//         for(int j=len-2;j>=0;--j){
//             tmp2[j]=tmp2[j+1]*A[j+1];
//         }
//         for(int x=0;x<len;++x){
//             result[x]=tmp1[x]*tmp2[x];
//         }
//         return result;
//     }
// };

//改进，不需要存上三角的所有元素，直接用一个变量存储，直接乘到下三角结果上
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len=A.size();
        std::vector<int> tmp1(len,1);
        if(A.empty())
            return tmp1;
        for(int i=1;i<len;++i){//从1开始，因为下三角第一行0个元素
            //下三角元素乘积
            tmp1[i]=tmp1[i-1]*A[i-1];
        }
        int tmp2=1;
        for(int j=len-2;j>=0;--j){
            tmp2*=A[j+1];
            tmp1[j]*=tmp2;
        }
        // for(int x=0;x<len;++x){
        //     result[x]=tmp1[x]*tmp2[x];
        // }
        return tmp1;
    }
};
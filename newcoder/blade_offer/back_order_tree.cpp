#include<iostream>
#include<algorithm>
#include<vector>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
    bool help(vector<int>::iterator begin,vector<int>::iterator end,vector<int> &v){
        if(begin==end)
            return true;
        int root=v.back();
        --end;
        vector<int>::iterator tmp1=begin;
        vector<int>::iterator tmp2;
        //因为后续遍历除去根节点后分为两段，左子树段和右子树段，左子树段元素均小于根节点
        while(tmp1!=end&&(*tmp1<root)){
            ++tmp1;
        }
        //此时tmp1指向右子树段第一个或者end
        tmp2=tmp1;
        while(tmp2!=end){
            if(*tmp2<root)
                return false;
            ++tmp2;
        }
        //递归验证子段
        bool lresult=help(begin,tmp1,v);
        bool rresult=help(tmp1,end,v);
        if(lresult&&rresult)
            return true;
        return false;
    }
    //判断一个数组是否为二叉搜索树的后续遍历结果
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        //后续遍历中最后一个元素为根节点
        bool result=help(sequence.begin(),sequence.end(),sequence);
        return result;

    }

};

// int main(){
//     Solution st;
//     int v1[4]={7,4,5,6};
//     int arraysize;
//     GET_ARRAY_LEN(v1,arraysize);
//     std::vector<int> v(v1,v1+arraysize);
//     for(int i=0;i<v.size();++i)
//         cout<<v[i]<<endl;
//     bool result=st.VerifySquenceOfBST(v);
//     cout<<"#############"<<endl;
//     cout<<result<<endl;

// }
//vector push vector 复制
int main(int argc, char const *argv[])
{
    vector<vector<int> > result;
    std::vector<int> v;
    v.push_back(12);
    result.push_back(v);
    cout<<v[0]<<endl;
    cout<<result[0][0]<<endl;
    v[0]=100;
    cout<<result[0][0]<<endl;
    cout<<v[0]<<endl;
    return 0;
}
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void help(TreeNode* root,int expectNumber,int now_sum,vector<int> &now_path,vector<vector<int> > &result){
        if(root==NULL)
            return;
        now_sum+=root->val;
        now_path.push_back(root->val);
        if((now_sum==expectNumber)&&(root->left==NULL)&&(root->right==NULL)){
            vector<int> v(now_path);
            result.push_back(v);
        }
        help(root->left,expectNumber,now_sum,now_path,result);
        help(root->right,expectNumber,now_sum,now_path,result);
        
        now_sum-=root->val;
        now_path.pop_back();
        return ;
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > result;
        int now_sum=0;
        vector<int> now_path;
        if(root==NULL)
            return result;
        help(root,expectNumber,now_sum,now_path,result);
        return result;
    }
};
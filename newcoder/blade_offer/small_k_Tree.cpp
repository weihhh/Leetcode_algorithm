/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    int index=0;
    void median_order(TreeNode* pRoot,TreeNode* &ans){
        if(pRoot){
            median_order(pRoot->left,ans);
            index--;
            if(index==0){
                ans=pRoot;
                return;//找到节点，直接返回
            }
            median_order(pRoot->right,ans);
        }
        return;
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        //儿叉搜索树中序遍历即从小到大排序结果
        if(pRoot&&k>=1){
            index=k;
            TreeNode* ans=nullptr;
            median_order(pRoot,ans);
            return ans;
        }
        return nullptr;
    }    
};
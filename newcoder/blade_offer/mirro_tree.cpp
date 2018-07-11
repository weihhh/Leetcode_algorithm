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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL)
            return;
        if(pRoot->left!=NULL||pRoot->right!=NULL){
            //交换左右子树
            TreeNode *tmp=pRoot->left;
            pRoot->left=pRoot->right;
            pRoot->right=tmp;
            //递归交换左右子树的子树
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};
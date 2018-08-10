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
    bool help(TreeNode* pRoot1,TreeNode* pRoot2){
        if(!pRoot1&&!pRoot2) return true;//左右子树均null，对称
        if(!pRoot1||!pRoot2) return false;//其中一个null，不对称

        if(pRoot1->val!=pRoot2->val) return false;
        return help(pRoot1->left,pRoot2->right)&&help(pRoot1->left,pRoot2->right);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        //镜像即左子树等于右子树，然后左子数的左子数等于右子树的右子树
        return help(pRoot,pRoot);
    }

};
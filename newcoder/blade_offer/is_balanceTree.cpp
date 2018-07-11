class Solution {
public:
    bool help(TreeNode* pRoot,int* depth){
        if(pRoot==NULL){
            *depth=0;
            return true;
        }
        int left,right;
        //首先当前节点左右孩子节点为根节点的树应为平衡树
        if(help(pRoot->left,&left)&&help(pRoot->right,&right)){//第一次只有在到达叶结点的时候才能满足
            //然后判断当前节点为根节点的树为平衡树
            int diff=left-right;
            if(diff>=-1&&diff<=1){
                *depth=max(left,right)+1;
                return true;
            }

        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL)
            reuturn true;//注意空树为平衡树
        int depth=0;
        return help(pRoot,&depth);

    }
};
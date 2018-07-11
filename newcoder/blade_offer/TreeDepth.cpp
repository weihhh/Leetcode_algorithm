/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
// class Solution {
// public:
//     int TreeDepth(TreeNode* pRoot)
//     {
//         int depth=1;
//         int left_depth=0,right_depth=0;
//         if(pRoot!=NULL){
//             if(pRoot->left){
//                 left_depth=TreeDepth(pRoot->left);
//             }
//             if(pRoot->right){
//                 right_depth=TreeDepth(pRoot->right);            
//             }
//         }
//         else{
//             depth=0;
//         }
//         depth+=max(left_depth,right_depth);
//         return depth;
//     }
// };

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        return (left>right)?(left+1):(right+1);
    }
};
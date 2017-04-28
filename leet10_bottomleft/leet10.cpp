/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth=0,value=0;
    void first_order(TreeNode* childroot,int nowdepth){
            if(nowdepth >depth)
            {
                depth=nowdepth;
                value=childroot->val;
            }
            if(childroot->left!=NULL)
            {
                first_order(childroot->left,nowdepth+1);
            }
            if(childroot->right!=NULL)
            {
                first_order(childroot->right,nowdepth+1);
            }

        }
    int findBottomLeftValue(TreeNode* root) {
        
        first_order(root,depth+1);
        return value;
        }

    
};
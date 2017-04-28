#*<font color=DarkSlateGray>leetcode10</font>*
二叉树寻找最底层最左边的值。
####题目描述：
>>Given a binary tree, find the leftmost value in the last row of the tree.


####代码（c++）：	

```c++
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

```
####经验：
1.先序遍历二叉树（先左子树后右子树），递归方法遍历，则深度首次增加的时候就是此层最左边的元素。





/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return construct(pre.begin(),pre.end()-1,vin.begin(),vin.end()-1);
    }
    TreeNode* construct(vector<int>::iterator preorder_begin,vector<int>::iterator preorder_end,vector<int>::iterator inorder_begin,vector<int>::iterator inorder_end){
        //确定根节点的值
        int root_val=*preorder_begin;
        TreeNode* root=new TreeNode(root_val);
        //在中序中找到根节点
        vector<int>::iterator root_it=inorder_begin;
        while(root_it!=inorder_end&&*root_it!=root_val){
            root_it++;
        }
        if(root_it==inorder_end&&*root_it!=root_val){
            // throw std::exception("invalid input!");
            cout<<"invalid"<<endl;
        }
        vector<int>::iterator in_left_tree=inorder_begin;
        vector<int>::iterator in_right_tree=inorder_end;
        int left_element=root_it-in_left_tree;
        int right_element=in_right_tree-root_it;
        if(left_element!=0)
            root->left=construct(preorder_begin+1,preorder_begin+left_element,inorder_begin,root_it-1);
        if(right_element!=0)
            root->right=construct(preorder_begin+left_element+1,preorder_end,root_it+1,inorder_end);
        return root;
    }
};
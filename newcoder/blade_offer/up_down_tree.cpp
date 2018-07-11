/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//广度优先使用队列
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        std::vector<int> v;
        if(root==NULL)
            return v;
        queue<TreeNode*> node_list;
        node_list.push(root);
        TreeNode* now_node=NULL;
        while(!node_list.empty()){
            now_node=node_list.front();
            node_list.pop();
            v.push_back(now_node->val);
            if(now_node->left!=NULL)
                node_list.push(now_node->left);
            if(now_node->right!=NULL)
                node_list.push(now_node->right);
        }
        return v;
    }
};



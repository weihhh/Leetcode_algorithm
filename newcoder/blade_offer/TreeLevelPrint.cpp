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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(!pRoot)
            return result;
        queue<TreeNode*> Tree_queue;
        int level_size=0;
        Tree_queue.push(pRoot);
        while(!Tree_queue.empty()){
            level_size=Tree_queue.size();
            vector<int> now_level; 
            for(int i=0;i<level_size;++i){
                TreeNode* now_node=Tree_queue.front();
                now_level.push_back(now_node->val);
                if(now_node->left)
                    Tree_queue.push(now_node->left);
                if(now_node->right)
                    Tree_queue.push(now_node->right);
                Tree_queue.pop();
            }
            result.push_back(now_level);
        }
        return result;
    }
    
};
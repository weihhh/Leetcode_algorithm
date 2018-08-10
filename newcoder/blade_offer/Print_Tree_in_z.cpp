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
        deque<TreeNode*> deque_tree;
        int level_size=0,level_num=1;
        deque_tree.push_back(pRoot);
        while(!deque_tree.empty()){
            level_size=deque_tree.size();//记录当前层节点数
            std::vector<int> tmp;
            result.push_back(tmp);
            if(level_num&1){
                //奇数从左向右，左节点先进，设定从队尾入
                for(int i=0;i<level_size;++i){
                    TreeNode* node=deque_tree.front();
                    result[level_num-1].push_back(node->val);
                    if(node->left)
                        deque_tree.push_back(node->left);
                    if(node->right)
                        deque_tree.push_back(node->right);
                    deque_tree.pop_front();
                }
            }
            else{
                //奇偶数两次正好方向相反
                for(int i=0;i<level_size;++i){
                    TreeNode* node=deque_tree.back();
                    result[level_num-1].push_back(node->val);
                    if(node->right)
                        deque_tree.push_front(node->right);
                    if(node->left)
                        deque_tree.push_front(node->left);
                    deque_tree.pop_back();
                }
            }
            ++level_num;
        }
        return result;
    }
    
};
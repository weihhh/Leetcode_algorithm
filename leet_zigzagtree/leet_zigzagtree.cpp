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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int> > ();
        }
        vector<vector<TreeNode *>> result;
        vector<TreeNode *> temp;
        temp.push_back(root);
        result.push_back(temp);
        temp.clear();
        int i=0;
        while(!result[i].empty())
        {
            auto iter=result[i].crbegin();
            auto last=result[i].crend();
            
            if(i%2==0){
                while(iter!=last){
                    if((*iter)->right)
                        temp.push_back((*iter)->right);
                    if((*iter)->left)
                        temp.push_back((*iter)->left);
                    ++iter;
                }
                result.push_back(temp);
                temp.clear();
                //transver result[i-1] target->left temp.push_back,target->right temp.push_back,temp result.push_back;
                ++i;
            }
            else{ 
                while(iter!=last){
                    if((*iter)->left)
                        temp.push_back((*iter)->left);
                    if((*iter)->right)
                        temp.push_back((*iter)->right);
                    ++iter;
                }
                result.push_back(temp);
                temp.clear();
                //transver result[i-1] target->left temp.push_back,target->right temp.push_back,temp result.push_back;
                ++i;
            }
         
        }
        //将指针中的值取出，去除最后的空vector
        result.pop_back();
        vector<vector<int>> result_new;
        vector<int> temp_new;
        auto iter1=result.begin();
        auto iter1end=result.end();
        while(iter1!=iter1end){
            for(auto &c:(*iter1)){
                temp_new.push_back(c->val);
            }
            result_new.push_back(temp_new);
            temp_new.clear();
            ++iter1;
        }
        return result_new;

    }
};
//问题在于占用空间过大，每个节点都保存了两份，指针的和值的，考虑队列
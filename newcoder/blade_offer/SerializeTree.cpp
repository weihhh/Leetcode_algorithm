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

    void first_order(TreeNode* node,string &result){
        if(!node){
            result+="#";
            return;
        }
        result+=to_string(node->val);
        result+=",";//数字需要逗号分隔
        first_order(node->left,result);
        first_order(node->right,result);
    }
    char* Serialize(TreeNode *root) {    
        //扩展二叉树的方式
        string result;
        if(!root)
            return nullptr;
        first_order(root,result);
        char* result_c=new char[result.size()+1];
        strcpy(result_c,result.c_str());
        return result_c;

    }
    TreeNode* rebuild(char **str){
        if(**str=='#'){
            //#代表null
            ++(*str);
            return nullptr;
        }
        //要注意上面数字之间使用逗号分隔,且一个数字不一定只占用一位
        int num=0;
        while(**str!='\0'&&**str!=','){
            num=num*10+((**str)-'0');
            ++(*str);
        }
        TreeNode* node=new TreeNode(num);
        if(**str=='\0')//此情况不会发生，因为结尾都是#，不会数字接\0
            return node;
        else
            //逗号，直接跳过
            ++(*str);
        node->left=rebuild(str);
        node->right=rebuild(str);
        return node;
    }
    TreeNode* Deserialize(char *str) {
        if(!str)
            return nullptr;
        TreeNode*result=rebuild(&str);
        return result;

    }
};
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//寻找根节点相同的地方，调用doesTreehassub来确认此节点接下去的左右子树均相同
    {
        bool result=false;
        if(pRoot1!=NULL&&pRoot2!=NULL){
            //从树1中查找树2的根节点值
            //根节点
            if(pRoot1->val==pRoot2->val)
                result=DoesTreehassub(pRoot1,pRoot2);//以当前结点为根节点的树符合条件，即节点对应相等
            if(!result)
                result=HasSubtree(pRoot1->left,pRoot2);
            if(!result)
                result=HasSubtree(pRoot1->right,pRoot2);
        }
        return result;
    }
    bool DoesTreehassub(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot2==NULL)
            return true;//接下去不一样无所谓，只需要有树2那部分结构就可以
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val!=pRoot2->val)
            return false;
        //当前节点相等
        return  DoesTreehassub(pRoot1->left,pRoot2->left)&&DoesTreehassub(pRoot1->right,pRoot2->right);

    }
};
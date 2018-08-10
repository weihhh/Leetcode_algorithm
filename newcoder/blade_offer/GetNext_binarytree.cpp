/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* help(TreeLinkNode* pNode){
        //获得中序遍历第一个,即最左边子叶子
        if(pNode->left==nullptr)
            return pNode;
        return help(pNode->left);
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr)
            return pNode;
        if(pNode->right!=nullptr){
            //如果有右节点，中序遍历右节点第一个即结果
            return help(pNode->right);
        }
        //没有右节点，则往上寻找
        while(pNode->next!=nullptr){
            //如果当前节点是父节点的左节点，那就返回父节点
            if(pNode->next->left==pNode) return pNode->next;
            //当前节点是父节点的右节点，说明父节点已访问，需要再往上寻找是父节点左节点的节点
            pNode=pNode->next;
        }
        return nullptr;

    }
};
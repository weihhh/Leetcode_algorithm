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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)
            return pRootOfTree;
        TreeNode* linklist_end=NULL;//指向已经转换未双向链表的尾部，便于递归过程拼接在后面
        Convert_node(pRootOfTree,&linklist_end);
        //现在*link_end指向链表最后一个元素。
        //往前寻找表头
        TreeNode* linklist_begin=linklist_end;
        while(linklist_begin->left!=NULL)
            linklist_begin=linklist_begin->left;
        return linklist_begin;
    }
    //因为递归过程中传递指针会复制,然后程序中会改变指针，所以传递指针的地址
    void Convert_node(TreeNode* root,TreeNode** linklist_end){
        if(root==NULL)
            return;
        //递归直到访问到最左下，即最小值
        Convert_node(root->left,linklist_end);
        //访问到最小值
        root->left=*linklist_end;
        if(*linklist_end!=NULL)
            (*linklist_end)->right=root;
        *linklist_end=root;
        Convert_node(root->right,linklist_end);
    }
};
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() {}
};
TreeNode* newTree()
{
    TreeNode* node = new TreeNode;
    int x;
    cout<<"input: "<<endl;
    cin >> x;
    cout<<"input end: "<<x<<endl;
    if (cin.eof())node = NULL;
    else
    {
        node->val = x;
        node->left = newTree();
        node->right = newTree();
    }
    return node;
}
vector<int> PrintFromTopToBottom(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    vector<int> v;
    if (!root)
        return v;
    while (!q.empty())
    {
        cout<<"here"<<endl;
        root = q.front();
        q.pop();
        v.push_back(root->val);
        if (root->left)q.push(root->left);
        if (root->right)q.push(root->right);
    }
    return v;
}
int main()
{
    // ios::sync_with_stdio(false);
    vector<int> res;
    TreeNode* root = NULL;
    root = newTree();
    res = PrintFromTopToBottom(root);
    vector<int>::iterator it;
    for (it = res.begin(); it != res.end(); it++)
        cout << *it << " ";
    return 0;
}
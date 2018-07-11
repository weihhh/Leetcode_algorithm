/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector <int>  result;
        std::stack<int> stack_node;
        ListNode* now_node=head;
        while(now_node!=NULL){
            stack_node.push(now_node->val);
            now_node=now_node->next;
        }
        while(!stack_node.empty()){
            result.push_back(stack_node.top());  
            stack_node.pop();
        }
        return result;
    }
};
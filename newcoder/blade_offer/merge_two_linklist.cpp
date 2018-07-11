/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        ListNode* merged_node=NULL;
        if(pHead1->val <pHead2->val){
            merged_node=pHead1;
            merged_node->next=Merge(pHead1->next,pHead2);
        }
        else{
            merged_node=pHead2;
            merged_node->next=Merge(pHead1,pHead2->next);
        }
        return merged_node;
    }
};
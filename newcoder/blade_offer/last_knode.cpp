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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL)
            return NULL;
        ListNode* slow=pListHead;
        ListNode* fast=pListHead;
        unsigned int i=1;
        while((fast!=NULL)&&(i<=k)){
            fast=fast->next;
            ++i;
        }
        if(fast==NULL&&i<=k)//链表长度小于k,即fast已经到null，而没有k个元素
            return NULL;
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;



    }
};
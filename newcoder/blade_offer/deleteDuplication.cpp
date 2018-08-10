/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr)
            return pHead;
        ListNode *walker_last=nullptr;//指向上一个不重复节点
        ListNode *walker=pHead;//指向当前节点
        ListNode *walker_next=nullptr;//指向当前节点下一个节点
        while(walker!=nullptr){
            if(walker->next!=nullptr&&walker->val==walker->next->val){
                //删除此值所有节点
                walker_next=walker->next;
                while(walker_next!=nullptr&&walker_next->next!=nullptr&&walker_next->val==walker_next->next->val)
                    walker_next=walker_next->next;
                //考虑当前节点为首节点
                if(walker==pHead)
                    pHead=walker_next->next;
                else
                    walker_last->next=walker_next->next;
                walker=walker_next->next;
            }
            else{
                //不重复，直接向前，walker_next不用管，确定wakler后再考虑
                walker_last=walker;
                walker=walker->next;
            }
        }
        return pHead;
    }
};
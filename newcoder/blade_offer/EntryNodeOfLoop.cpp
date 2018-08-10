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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==nullptr)
            return pHead;
        ListNode *slow=pHead;
        ListNode *fast=pHead->next;
        while(fast!=nullptr&&fast->next!=nullptr&&fast!=slow){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==nullptr||fast->next==nullptr)
            return nullptr;
        //运行到这里说明fast和slow相遇
        //只要将slow放回起点再出发，相遇即为环起点
        fast=pHead;
        slow=slow->next;//因为fast从phead->next开始，所以相遇后slow需要后移一位
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;//注意这里两各都步长为1
        }
        return slow;
    }
};
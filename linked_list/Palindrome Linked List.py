# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return True
        ori_head=head
        newhead=None
        oldhead=None
        if head.next:
            newhead=ListNode(head.val)
            oldhead=newhead
            head=head.next
        else:
            return True
        while head:
            newhead=ListNode(head.val)
            newhead.next=oldhead
            oldhead=newhead
            head=head.next
        while ori_head:
            if ori_head.val!=newhead.val:
                return False
            ori_head=ori_head.next
            newhead=newhead.next
        return True
'''
回文的简单想法就是将整个待判断对象反过来，再逐位对照，这里是新建了一个翻转链表
c++翻转原链表，三个变量，pre，now，next实现，最后结束时now，next指向相同null
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        } 
        return pre;
    }
};
'''

c++，折半，中间之后反过来即可
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
            
        pre=None
        current_head=head
        while current_head:
            next_node=current_head.next
            current_head.next=pre
            pre=current_head
            current_head=next_node
        return pre


def reverse_linkedlist(head,end):
            if not head:
                return head
            #反转以head为首，end为尾的链表，最后以一个冗余节点None为结尾
            pre=None
            current_head=head
            while current_head is not end:
                next_node=current_head.next
                current_head.next=pre
                pre=current_head
                current_head=next_node
            current_head.next=pre
            return end,head
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or k==1:
            return head

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

        dummy=ListNode(0)
        dummy.next=head
        pre=dummy
        slow,fast=head,head
        while fast:
            #完成一段k个节点的反转和拼接，slow和fast同时位于新的起点
            for i in range(k-1):
                fast=fast.next
                if not fast:#在执行fast=fast.next语句之后，确保循环中和结束后fast一定非空
                    return dummy.next
            #现在fast和slow之间共有k个非空节点
            next_node=fast.next
            #反转之间的所有节点
            left_node,right_node=reverse_linkedlist(slow,fast)
            #拼接
            pre.next=left_node
            right_node.next=next_node
            #将slow和fast放到新的起点
            slow,fast=next_node,next_node
            pre=right_node
        return dummy.next#有可能正好k*n长度，则最后一次不会进入上面的额while，需要这里返回
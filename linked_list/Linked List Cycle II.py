# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        slow,fast=head,head.next
        while slow is not fast :
            if not fast or not fast.next:#因为后面是两个跳，所以要判断到next位置
                return None
            slow=slow.next
            fast=fast.next.next
        #slow meet fast
        fast=head
        slow=slow.next#！！！！！！注意这里，fast一开始就是先一位开始，所以这里要slow补上一位
        while slow is not fast:
            slow=slow.next
            fast=fast.next
        return fast

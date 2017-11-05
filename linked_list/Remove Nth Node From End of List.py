# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:
            return head

        #思想是用一个快游标带着一个落后n的慢游标,以fast.next是否为None为终止标志
        dummy=ListNode(0)
        dummy.next=head
        slow,fast=dummy,dummy
        i=0
        while i<n:
            fast=fast.next
            i+=1
        slow=dummy
        while fast.next:
            fast=fast.next
            slow=slow.next
        slow.next=slow.next.next
        return dummy.next


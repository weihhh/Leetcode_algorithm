# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy=ListNode(0)
        result=dummy
        while l1 and l2:
            if l1.val<=l2.val:
                dummy.next=ListNode(l1.val)
                dummy=dummy.next
                l1=l1.next
            else:
                dummy.next=ListNode(l2.val)
                dummy=dummy.next 
                l2=l2.next 
        if l1:
            dummy.next=l1
        else:
            dummy.next=l2
        #dummy.next=l1 if l1 else l2
        return result.next
#因为给定的是排序好的，所以拼接后的也需要排序好的，这样就是将两个链表的元素相比较取较小的
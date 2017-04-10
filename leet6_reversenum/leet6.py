# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result=0
        n=end=ListNode(0)
        while (l1!= None or l2 !=None) :
            result //=10
            if l1!=None:
                result+=l1.val
                l1=l1.next
            if l2!=None:
                result+=l2.val
                l2=l2.next
            n.next=ListNode(result%10)
            n=n.next
        if result//10==1:
            n.next=ListNode(1)
        return end.next        
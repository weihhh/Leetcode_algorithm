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
        for a in (l1,l2):
            mi=0
            while a.next != None:
                result+=a.val*(10**mi)
                a=a.next
                mi+=1
            result+=a.val*(10**mi)
        string_from_result=str(result)
        n=end=ListNode(0)
        for i in string_from_result[::-1]:
            n.next=ListNode(int(i))
            n=n.next
        return end.next     
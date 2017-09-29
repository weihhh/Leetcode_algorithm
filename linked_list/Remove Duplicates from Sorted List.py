# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        now_in_list=[]
        result=head
        
        previous=head
        now_in_list.append(head.val)
        head=head.next
        #处理好第一个，使之有previous
        
        while head:
            if head.val in now_in_list:
                previous.next=head.next
                head=head.next
                continue#与break的区别！！！！
            now_in_list.append(head.val)
            previous=head
            head=head.next
        return result
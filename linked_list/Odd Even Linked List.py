# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #很直接的，将偶数奇数的节点分别放在一个链表中，然后拼接即可
        if not head:
            return head
        odd=ListNode(0)
        even=ListNode(0)
        odd_cur,even_cur=odd,even
        time=1
        while head:
            if time%2==0:
                even_cur.next=head
                even_cur=even_cur.next
            else:
                odd_cur.next=head
                odd_cur=odd_cur.next
            head=head.next
            time+=1
        odd_cur.next=even.next
        even_cur.next=None
        return odd.next

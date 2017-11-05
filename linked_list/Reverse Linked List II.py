# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if not head or m==n:
            return head
        time=1
        #find start
        point_s=head
        left_point=None#左边待拼接的部分
        while time!=m:
            left_point=point_s
            point_s=point_s.next
            time+=1
        #begin reverse
        point=point_s
        pre=None
        while time!=(n+1):#n保证小于等于长度，所以不会为空
            nextpoint=point.next
            point.next=pre
            pre=point
            point=nextpoint
            time+=1
        #结束后point指向剩余右边需要拼接的部分，pre指向需要翻转的部分最后一个
        if left_point:
            left_point.next=pre
        if point:
            point_s.next=point
        return head if m!=1 else pre




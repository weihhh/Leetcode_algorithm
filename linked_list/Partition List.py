# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if not head:
            return head
        #第一步，建立pre，now的体系,result用来当作最后结果，dummy用来作为第二部分链表的开头
        result=ListNode(0)
        result.next=head
        pre=result
        now=head
        dummy=ListNode(0)
        new=dummy#指示dummy链表中的最后一个元素
        while now:
            if now.val>=x:
                #从原来链表中取出now接在dummy链表中
                new.next=now
                new=new.next
                pre.next=now.next
                now=now.next
                new.next=None

            else:
                pre=now
                now=now.next
        pre.next=dummy.next
        return result.next

#这里应该直接建立两个链表，然后将大于和小于的分别接在各自两个链表后，这样更加清晰
result=ListNode(0)#后面接上小于x的
result2=ListNode(0)#后面接上大于等于x的
now=result
new=result2
while head:#利用了head进行迭代
    if head.val<x:
        now.next=head
        now=now.next
    else:
        now.next=head
        now=now.next
    head=head.next
new.next=None
now.next=result2.next
return result.next

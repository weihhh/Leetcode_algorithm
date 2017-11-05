# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #使用了三个指针，有的解法只用一个指针，然后交换p.next.next和p.next
        if not head:
            return head

        dummy=ListNode(0)
        dummy.next=head
        pre=dummy
        swap1=head
        swap2=head.next
        while swap2:
            swap1.next=swap2.next
            pre.next=swap2
            swap2.next=swap1
            swap1,swap2=swap2,swap1#注意这里需要交换指针指向!!!
            if swap2.next:
                pre=pre.next.next
                swap1=swap1.next.next
                swap2=swap2.next.next
            else:
                break
        return dummy.next
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #直接插入排序
        if not head:
            return head
        result=head#result指向排序好的链表头,首先指向了待排序的首位
        head=head.next
        result.next=None
        while head:
            nextnode=head.next#确定有next，因为while中已经判断head不为空
            #每次插入都是从头开始比较
            node_in_result=result
            last=None
            while node_in_result:
                if head.val>node_in_result.val:
                    last=node_in_result
                    node_in_result=node_in_result.next
                    continue
                else:
                    if last:
                        last.next,head.next=head,node_in_result
                    else:
                        result=head
                        head.next=node_in_result
                    break
            else:
                if last:
                    last.next,head.next=head,node_in_result
                else:
                    result=head
                    head.next=node_in_result

            head=nextnode
        return result

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #直接插入排序,使用dummy头
        if not head:
            return head
        dummy=ListNode(0)#创建一个辅助节点，就不需要考虑上一个节点为空的情况
        while head:
            nextnode=head.next#在循环中会破坏next键，需要事先存好
            pre=dummy
            while pre.next and head.val>pre.next.val:
                pre=pre.next
            #链表插入固定公式
            head.next=pre.next
            pre.next=head
            head=nextnode
        return dummy.next



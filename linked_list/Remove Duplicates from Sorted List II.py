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
        
        result=ListNode(0)#最后提交结果链表，将选出的节点接在其后
        new=result#指示新链表的最后一个节点
        pend=head#指示待定的节点
        head=head.next#指示当前的节点
        dup_tag=False#当前处于处理重复节点还是处理新节点的标志
        
        while head:
            if head.val!=pend.val:
                if dup_tag==False:#说明遇到了不重复节点，放入result链表    
                    new.next=pend
                    new=new.next
                    pend=head#将待定点提到当前结点
                else:#说明正在处理重复节点，但重复状态结束，更改标志，待定点提上来，不增加到result
                    pend=head
                    dup_tag=False
            else:#说明还处于重复状态，跳过
                dup_tag=True
            head=head.next#下一个节点
        if dup_tag==False:#针对处理最后一个节点不重复的情况
            new.next=pend
            new=new.next
        new.next=None#最后要用None结尾，否则会将之后的节点误增
        return result.next

#下面的方法，不同于上面的是将pre提前到了不重复节点，上面的方法pend停在待定点，下面的方法直接跳过重复点，pre指向不重复点是重点，pre.next==cur作为是否有重复的判断
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head               

        dummy=ListNode(0)
        dummy.next=head
        pre=dummy#指示上一个不重复的节点
        cur=head
        while cur:
            while cur.next and cur.val==cur.next.val:
                cur=cur.next
            #退出上面循环，说明到达不同节点点,此时cur指向相同节点，next是不同点
            if pre.next==cur:#如果中间有重复，则pre的next不会是cur
                pre=pre.next
            else:
                pre.next=cur.next
            cur=cur.next

        return dummy.next
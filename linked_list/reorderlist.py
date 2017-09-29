# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """

        def  reverse_list(head):
            #输入起始节点，输出翻转后的起点节点
            if not head or not head.next:
                return head
            pre_node,next_node=None,None
            while head:
                next_node=head.next
                head.next=pre_node
                pre_node=head
                head=next_node#这里注意要用next_node!!!!nextndoe的作用就是在改变head.next之前暂时保存原来的next，如果next为nONE,那么while停止，pre指向的即为新的翻转list头
            return pre_node

        if not head or not head.next:
            return 
        #快慢指针找到中间点
        slow,fast=head,head
        while fast.next and fast.next.next:
            slow=slow.next
            fast=fast.next.next
        #Slow指向中间点，将后面节点翻转，生成两个链表，分别以new-head、slow开头，并都以none结尾，分别命名为a.b
        new_head=reverse_list(slow.next)
        slow.next=None
        #将new_head这个翻转后的链表插入head链表中
        tmp=head
        while tmp and new_head:#根据中点特性，b链表长度小于等于a，只有当前指针都不为none时插入
            next_a=tmp.next
            next_b=new_head.next
            tmp.next=new_head
            new_head.next=next_a
            new_head=next_b
            tmp=next_a
        return 


        

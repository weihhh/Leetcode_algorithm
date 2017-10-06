# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if not head:
            return None
        tmp=head
        #复制节点在节点后
        while tmp:
            nextnode=tmp.next
            newnode=RandomListNode(tmp.label)
            newnode.next=tmp.next
            tmp.next=newnode
            tmp=nextnode
        #复制指向
        tmp=head
        while tmp:
            if tmp.random:    
                tmp.next.random=tmp.random.next 
            tmp=tmp.next.next
        #切断，取出结果链表
        tmp=head
        result=tmp.next
        while tmp:
            nextnode=tmp.next.next
            if tmp.next.next:
                tmp.next.next=tmp.next.next.next
            tmp.next=nextnode
            tmp=tmp.next
        return result

# 1.与正常链表复制的区别在于，这里复制前面节点的时候，其节点中有指针指向后面还没有建立的节点，这个节点的位置还不能确定。
# 2.思路就是在所有节点后复制节点，借此可以利用next记录相对位置
# 3.注释中的第二个解决方案利用了字典记录新旧链表的对应关系


'''
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        nodeDict = dict()
        dummy = RandomListNode(0)
        pointer, newHead = head, dummy
        while pointer:
            newNode = RandomListNode(pointer.label)
            newHead.next = newNode
            nodeDict[pointer] = newNode
            newHead, pointer = newHead.next, pointer.next
        pointer, newHead = head, dummy.next
        while pointer:
            if pointer.random:
                newHead.random = nodeDict[pointer.random]
            pointer, newHead = pointer.next, newHead.next
        return dummy.next

'''
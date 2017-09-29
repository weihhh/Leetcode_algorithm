'''
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or k <=0:
            return head
        l1=head
        len=1
        while head.next:
            head=head.next
            len+=1
        if len==k:
            return l1
        head.next=l1#首尾相连，找到尾巴截断
        head=l1

        if k%len:
            for i in range(len-(k%len)-1):#一次循环就到了第二个元素，所以要减去1
                head=head.next
            l1=head.next
            head.next=None
        # print('ok')
        return l1
'''
#以上代码错在执行首尾相连的位置，在k%len不等与0的时侯，没有截断，导致环状，整个验证程序死循环
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or k <=0:
            return head
        l1=head
        len=1
        while head.next:
            head=head.next
            len+=1
        if k%len:
            head.next=l1#首尾相连，找到尾巴截断,注意这里：只有当k%len的时候首位相接，否则么有必要，直接返回原始就行
            head=l1
            for i in range(len-(k%len)-1):#一次循环就到了第二个元素，所以要减去1
                head=head.next
            l1=head.next
            head.next=None
        # print('ok')
        return l1
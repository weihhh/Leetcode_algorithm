# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head:
            return head

        result_head=head
        while head:
            if head.val!=val:#找到一个不是待找值，于是将其当作pre，head后移，结束当前while
                pre=head
                head=head.next
                break
            head=head.next
            result_head=head#没有找到，即都是目标值，则不断后移最后需要返回的结果链表头
        while head:
            if head.val==val:
                pre.next=head.next
                head=head.next
                continue
            pre=head#只有当不是需要删除的值时才能后移pre，否则是pre的next跳过
            head=head.next
        return result_head

'''
这个题目比较烦人的就是开头那个元素，因为删除元素需要知道前一个元素，如果链表开始就是需要删除，
那么这是还没有pre，
我的方法用了两个while来解决初始即需要删除的情况，很不美观。
改进
1.可以通过在链表之前加上一个dummy元素，最后返回的时候直接返回dummy之后的元素即可
    x=ListNode(0)
    x.next=head
    head=x
    #以上替换成head, head.next = ListNode(0), head也行
    p = head
    while p.next:
        if p.next.val == val:
            p.next = p.next.next
        else: p = p.next
    return head.next
2.递归，从后往前删除
public ListNode removeElements(ListNode head, int val) {
        if (head == null) return null;
        head.next = removeElements(head.next, val);
        return head.val == val ? head.next : head;
}
'''
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
        now_in_list=[]
        result=head
        
        previous=head
        now_in_list.append(head.val)
        head=head.next
        #处理好第一个，使之有previous
        
        while head:
            if head.val in now_in_list:
                previous.next=head.next
                head=head.next
                continue#与break的区别！！！！
            now_in_list.append(head.val)
            previous=head
            head=head.next
        return result
#上面的方法可行，但是针对的是未排序和排序状况都行，而本题是已经排好序的，所以可以更加简单，重复的一定排在一起
public ListNode deleteDuplicates2(ListNode head) {
        if(head == null || head.next == null) return head;
        
        ListNode list = head;
         while(list.next != null) 
         {
             if (list.val == list.next.val)
                 list.next = list.next.next;
             else 
                 list = list.next;
         }

         return head;
    }
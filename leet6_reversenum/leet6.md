#*<font color=DarkSlateGray>leetcode5</font>*
链表加整数各位相加取出的问题。
####题目描述：
>>You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.
>Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8


####代码（python）： 

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result=0
        n=end=ListNode(0)
        while (l1!= None or l2 !=None) :
            result //=10
            if l1!=None:
                result+=l1.val
                l1=l1.next
            if l2!=None:
                result+=l2.val
                l2=l2.next
            n.next=ListNode(result%10)
            n=n.next
        if result//10==1:
            n.next=ListNode(1)
        return end.next 
下面是第二种，投机取巧，使用了str（），速度相对于上面慢。
result=0
        for a in (l1,l2):
            mi=0
            while a.next != None:
                result+=a.val*(10**mi)
                a=a.next
                mi+=1
            result+=a.val*(10**mi)
        string_from_result=str(result)
        n=end=ListNode(0)
        for i in string_from_result[::-1]:
            n.next=ListNode(int(i))
            n=n.next
        return end.next            
```
####经验：
1.逐位相加，单个位考虑10，用取整进位，取余赋值。





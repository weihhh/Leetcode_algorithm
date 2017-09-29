# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head:
            return None
        
        def findmid(head,end):
            if  head is end:
                return None
            slow=head
            fast=head
            while fast.next is not end and fast.next.next is not end:
                slow=slow.next
                fast=fast.next.next
            return slow
        def mkbst(head,end):
            if  head is end:
                return None
            mid=findmid(head,end)
            node=TreeNode(mid.val)
            node.left=mkbst(head,mid)
            node.right=mkbst(mid.next,end)
            return node

        return mkbst(head,None)
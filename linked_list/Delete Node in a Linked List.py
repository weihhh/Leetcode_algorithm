# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if not node:
            return 
        while node.next:
            node.val=node.next.val
            if node.next.next==None:
                node.next=None
                return
            node=node.next
'''
首先要考虑输入为None的情况，然后相当于将后一个元素的值给到当前元素，
然后在 当前循环判断后一个的后一个是否为None，若是，则切断当前元素与之后元素的连接，
前移完成，最后一个元素不要
'''        

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if not node:
            return 
        node.val=node.next.val
        node.next=node.next.next

'''
这个方法更聪明，想法是删除当前要删除的下一个元素，但是先复制下一个的信息，将当前元素变为下一个元素，相当于删除当前元素
c++方法，同理，将后一个复制到前一个
void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}
'''    
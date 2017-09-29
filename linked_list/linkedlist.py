#在命令行运行，再输入逗号分隔的数字即可
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def findmid(start,end):
            #右边大，左边小
            if start == end or start.next == end:#表示只有一个或者空
                return start
            key=start.val
            findsmall=start#首先往前寻找小于key值的位置并与pointbig交换，跳过不交换的是大于等于key的
            pointbig=start#交换后指向小的值，next是大于等于的
            while findsmall !=end:
                if findsmall.val <key:
                    pointbig=pointbig.next
                    pointbig.val,findsmall.val=findsmall.val,pointbig.val
                findsmall=findsmall.next
                print('once')
            pointbig.val,head.val=head.val,pointbig.val#将首位的中间值交换过来
            return pointbig
        def quicksort(start,end):
            if start == end or start.next == end:
                return
            mid=findmid(head,end)
            quicksort(start,mid)
            quicksort(mid.next,end)
        if not head or head.next is None:
            return head
        quicksort(head,None)
        return head


def stringToIntegerList(input):
    input = input.strip()
    print(input.split(","))
    return [int(number) for number in input.split(",") if number]

def stringToListNode(input):
    # Generate list from the input
    numbers = stringToIntegerList(input)

    # Now convert that list into linked list
    dummyRoot = ListNode(0)
    ptr = dummyRoot
    for number in numbers:
        ptr.next = ListNode(number)
        ptr = ptr.next

    ptr = dummyRoot.next
    return ptr

def listNodeToString(node):
    result = ""
    while node:
        result += str(node.val) + ", "
        node = node.next
    return result[:-2]

import sys
def readlines():
    for line in sys.stdin:
        yield line.strip('\n')

def main():
    lines = readlines()
    while True:
        try:
            line = next(lines)
            head = stringToListNode(line)
            
            ret = Solution().sortList(head)

            out = listNodeToString(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()
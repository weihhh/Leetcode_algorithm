class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lenth=len(nums)
        if lenth==0:
            return True
        def jumpnow(nowposition):
            if nowposition<=(lenth-1):
                if nowposition==(lenth-1):
                    return True
                for i in range(1,nums[nowposition]+1):
                    tag=jumpnow(nowposition+i)
                    if tag==True:
                        return True  
            return False
        result=jumpnow(0)
        return result
#递归方法，最后几个数量大的例子无法通过，这里相当于采用了动态规划，但这题其实不用，因为每一格代表的是最大步数，采用底下这种更新最大能到达位置的方法更好，最大能到达位置之前的位置都能到达，因为最小步数就是一步步走。
#
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lenth=len(nums)
        reach=0#当前最远位置
        for step in range(lenth):
            if step<=reach:#最远位置之前位置都能到，但之后位置不确定，所以一步一步向后拓展
                reach=max(reach,step+nums[step])
                if reach>=lenth-1:
                    return True
            else:
                break
        return False

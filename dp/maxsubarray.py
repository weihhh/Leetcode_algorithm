class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not list:
            return 0
        #dp[i]表示一定以nums[i]结尾的所有序列最大,相当于求解了前0：i连续序列的最大值问题
        #dp[i]表示的是局部最有解，利用max_sub记录全局最优
        dp=[]
        max_sub=nums[0]
        dp.append(nums[0])
        for i,element in enumerate(nums[1:],1):
            now_max=element if dp[i-1]<0 else element+dp[i-1]
            dp.append(now_max)
            max_sub=max_sub if max_sub>now_max else now_max
        return max_sub


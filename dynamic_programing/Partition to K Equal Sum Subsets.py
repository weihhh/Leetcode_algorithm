class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        #确定分块内数值总和，若不能均分，直接退出
        target, rem = divmod(sum(nums), k)
        if rem or max(nums) > target: return False

        memo = [None] * (1 << len(nums))#记录在used表示的nums使用情况下，是否能够成功
        memo[-1] = True#1<<len(nums)表示2的len次方，因当全部nums使用时used为len个1，数值为2的len次方-1，memo[-1]表示当全部使用时，一定成功了
        
        #used记录nums中已使用数0001表示第一个数已使用，todo记录nums总和剩余
        def search(used, todo):
            if memo[used] is None:
                #相当于todo%target
                targ = (todo - 1) % target + 1
                memo[used] = any(search(used | (1<<i), todo - num)#used | (1<<i)表示第i个已使用
                                 for i, num in enumerate(nums)
                                 if (used >> i) & 1 == 0 and num <= targ)#used>>i & 1 表示查看第i个数是否已经使用
            return memo[used]

        return search(0, target * k)
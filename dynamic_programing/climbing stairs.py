class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        #关键思想：要知道到达n台阶的方式总数，可以通过到n-1步的方法总数加上到n-2步的方法总数得到
        #n-1步到n步和n-2走到n步都只需要一次，n-2步若选择一步一步走两步，则此方法是包含在n-1步到n步的方法里的

        if n==0:
            return 0
        if n==1:
            return 1
        if n==2:
            return 2
        all_ways=0
        one_step_before=2
        two_step_before=1
        for i in range(3,n+1):#从第三步开始
            all_ways=one_step_before+two_step_before

            #下面是为下一步做准备
            two_step_before=one_step_before
            one_step_before=all_ways
        return all_ways
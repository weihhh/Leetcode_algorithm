#*<font color=DarkSlateGray>leetcode</font>*
很久以前就注册leetcode，但都没有开始做，前几天的华为比赛没能准备充分，c++也是临时熟悉起来，更让人泄气的是自己的基本功太差，所以决定开始每天做几道题目。这次是随机取的一道题目：
####题目描述：
>>Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
>For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
####代码（python）：	

```python
	import time
	start =time.clock()
	class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        results=[]
        if not nums:
        	return results
        nums.sort()
        end=len(nums)-1
        if nums[0]*4>target or nums[end]*4<target:
        	return results
        def findnext(pre,i,x,result,results):
        	
        	remaining=target-pre
        	if nums[0]*(4-x)>remaining or nums[end]*(4-x)<remaining:
        		return
        	#print(x,i,result,results)
        	for j,a in enumerate(nums[i+1:],i+1):
        		if x==3:
        			if a==remaining:
        				if not (result+[a]) in results:
        					results.append(result+[a])
        					break
        			else:
        				continue
        		else:
        			findnext(pre+a,j,x+1,[a]+result,results)
                    
         
        findnext(0,-1,0,[],results)
        return results
        
	test=Solution()
	print(test.fourSum([-1，3，4，7，5],333))

	end = time.clock()
	print('Running time: %s Seconds'%(end-start))
```
####经验：
1. python的调试过程还得学习，自己输出变量的方式还是太低效，pudb需要在类unix环境下才能运行，windows底下还得再找一种更好的工具。
2. 递归要注意列表传入会被改变，所以这里 findnext(pre+a,j,x+1,[a]+result,results)使用了[a]+result新创建一个列表传入。
3. 一开始程序正确，但是超时严重，需要在进行循环前检查是否最大值和最小值的限制，比如如果4个最小值都比结果大，那么不需要进行计算。



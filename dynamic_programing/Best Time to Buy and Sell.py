
'''
class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        smallest,biggest=[0,prices[0]],[0,prices[0]]
        profitmax=0
        for i,num in enumerate(prices):
            if num<smallest[1]:
                smallest[1]=num
                smallest[0]=i
            if num>biggest[1]:
                biggest[1]=num
                biggest[0]=i
            if biggest[0]<smallest[0]:
                biggest[1]=prices[i+1] if i+1<len(prices) else prices[i]
                biggest[0]=i+1 if i+1<len(prices) else i
            profitmax=max(profitmax,biggest[1]-smallest[1])
        return profitmax
'''
class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #重点是不需要记录最高点，只需要不断去更新比最小大的值减去最小的差即可
        if not prices:
            return 0
        smallest=prices[0]
        profitmax=0
        for num in prices:
            if num<=smallest:
                smallest=num
            else:
                profitmax=max(num-smallest,profitmax)
        return profitmax
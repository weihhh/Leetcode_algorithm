class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #find the sell point and buy point
        #存在问题：无法应对恒定不变的段
        gap=[]
        for i in range(1,len(prices)):
            gap.append(prices[i]-prices[i-1])
        pre=-1
        buy=[]
        sell=[]
        for i in range(len(gap)):
            if pre*gap[i] <=0:
                if gap[i]>=0:
                    #极小
                    buy.append(i)
                else:
                    #极大
                    sell.append(i)
            pre=gap[i]
        op=[]
        j=0
        while sell:
            op.append((buy.pop(0),sell.pop(0)))
        if buy:
            op.append((buy.pop(),len(prices)-1))
        print(op)
        profit=0
        loss=0
        for i in range(len(op)):
            if i==len(op)-1:
                profit+=prices[op[i][1]]-prices[op[i][0]]
                break
            if op[i+1][0]-op[i][1]==1:
                loss+=min(prices[op[i][1]]-prices[op[i][1]-1],prices[op[i+1][0]+1]-prices[op[i+1][0]])
            profit+=prices[op[i][1]]-prices[op[i][0]]
        print(profit,loss)
        return profit-loss


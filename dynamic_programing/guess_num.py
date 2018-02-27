class Solution:
    
    def dp(self,table,s,e):
    	
    	if s>=e:
    		return 0
    	if table[s][e]!=0:
    		return table[s][e]
    	#保证最后都是能够成功猜出，且最坏情况，但每层选择哪个是可以加入策略的，所以要遍历，选择最小的那个
    	res=0xFFFFFFFF
    	for i in range(s,e+1):
    		#max保证最坏情况
    		tmp=i+max(self.dp(table,s,i-1),self.dp(table,i+1,e))
    		res=min(tmp,res)
    	table[s][e]=res
    	return res
    
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0:
        	return 0
        #因为表中存储的最大为1到n，即table[1][n],而编程是从0开始，要有n的话几句需要n+1,
        #虽然这样浪费了[0]的位置
        table=[[0 for i in range(n+1)] for i in range(n+1)]
        # print(table)
        return self.dp(table,1,n)

test=Solution()
test.getMoneyAmount(2)
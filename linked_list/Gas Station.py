class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        #重要结论：如果从A点出发不能到达B（B是A出发第一个不能到达的点），则A和B之间的点也不可能到达B点（因为从A后面点出发,diff——A肯定是正的，那么会会少了A的剩余油，那肯定是到不了的），
        #还有若total>=0,则必定存在这样一个起点可以转圈

        if not gas or not cost:
            return -1

        total=0
        sum_diff=0#之前站累计的剩余油
        start=0
        for i,(x,y) in enumerate(zip(gas,cost)):
            total+=(x-y)
            if sum_diff<0:#说明之前的油不足以到达此战，则从当前站出发
                start=i
                sum_diff=x-y
                continue
            sum_diff+=(x-y)
        if total>=0:
            return start
        else:
            return -1


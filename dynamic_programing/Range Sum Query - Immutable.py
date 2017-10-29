class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums=nums
        self.sum_material=[] 
        sum_now=0
        self.sum_material.append(sum_now)
        for items in nums:#累加和
            sum_now+=items
            self.sum_material.append(sum_now)
    
    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if not self.nums:
            return 0
        return self.sum_material[j+1]-self.sum_material[i]#因为开头要增加一个0，作为最初

             

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
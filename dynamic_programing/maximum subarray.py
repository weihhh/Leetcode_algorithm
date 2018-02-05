class Solution:
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        len_a=len(A)
        len_b=len(B)
        max_len=0
        #因为迭代中需要使用之前信息，所以这里数组长度要比实际长一个，0位置作为初始0
        #注意下面的range内也需要增加一个
        result=[[0 for _ in range(len_b+1)] for _ in range(len_a+1)]
        for i in range(len_a+1):
            for j in range(len_b+1):
                #表示以A[i]和B[j] 结尾的（不包含）的两个子序列
                if i==0 or j==0:
                    result[i][j]=0
                else:
                    if A[i-1]==B[j-1]:
                        result[i][j]=result[i-1][j-1]+1
                        max_len=result[i][j] if result[i][j]>max_len else max_len
        return max_len

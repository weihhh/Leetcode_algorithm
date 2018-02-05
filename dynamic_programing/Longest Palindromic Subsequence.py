# #循环版本,超时
# class Solution:
#     def longestPalindromeSubseq(self, s):
#         """
#         :type s: str
#         :rtype: int
#         """
#         n=len(s)
#         #dp[i][j]表示i到j子串最长度,i<j时dp为0
#         #If s[i] == s[j], dp[i][j] = 2 + dp[i+1][j - 1]
#         #Else, dp[i][j] = max(dp[i+1][j], dp[i][j-1])
#         dp=[[0 for _ in range(n)] for _ in range(n)]
#         #主要思想：由内到外
#         for i in reversed(range(n)):
#             dp[i][i]=1
#             for j in range(i+1,n):
#                 if s[i]==s[j]:
#                     dp[i][j]=2+dp[i+1][j - 1]
#                 else:
#                     dp[i][j] = max(dp[i+1][j], dp[i][j-1])

#         return dp[0][n-1]

#递归版本
class Solution:
    

    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        def helper(s,i,j,dp):
            if dp[i][j] !=-1:
                return dp[i][j]
            if i>j:
                return 0
            if i==j:
                return 1
            if s[i]==s[j]:
                dp[i][j]=helper(s,i+1,j-1,dp)+2
            else:
                dp[i][j]=max(helper(s,i+1,j,dp),helper(s,i,j-1,dp))
            return dp[i][j]


        n=len(s)
        #dp[i][j]表示i到j子串最长度,i<j时dp为0
        #If s[i] == s[j], dp[i][j] = 2 + dp[i+1][j - 1]
        #Else, dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        dp=[[-1 for _ in range(n)] for _ in range(n)]
        #主要思想：由内到外

        return helper(s,0,n-1,dp)


def test(s):
    test_class=Solution()
    result=test_class.longestPalindromeSubseq(s)
    return result

if __name__ == '__main__':
    print(test('aabaa'))
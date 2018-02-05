class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        count=0
        def extend(s,left,right):
            nonlocal count
            while left>=0 and right<len(s) and s[left]==s[right]:
                count+=1
                left-=1
                right+=1

        for i in range(len(s)):
            extend(s,i,i)
            extend(s,i,i+1)
        return count


class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        #扩展原字符串，避免区分奇数偶数长度，@和$是为了编程时从1开始而不用考虑i-p[i]-1会小于0，相当于dummy
        s_new='@#'+'#'.join(s)+'#$'
        center=right=0
        p=[0]*len(s_new)
        for i in range(1,len(s_new)-1):
            #i处在回文内，关于i对称的点已计算，可利用
            if i<right:
                p[i]=min(right-i,p[2*center-i])
            #若上面p[i]取p[2*center-i]，说明未超出right，下面会直接跳出while
            while s_new[i-p[i]-1]==s_new[i+p[i]+1]:
                p[i]+=1
            #更新中心
            if (p[i]+i)>right:
                center=i
                right=p[i]
        #加1是因为p存储的是半径，但本身（即半径为0）也是一个回文
        #除2是因为：#b#a#b#,这里a，半径为3，但其实是1，b半径为1，其实为0（增加一个回文，就会增加一个#），注意这里的整除
        return sum((v+1)//2 for v in p)

test=Solution()
result=test.countSubstrings('abddba')
print(result)
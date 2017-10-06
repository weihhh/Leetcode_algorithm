class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        if not g or not s:
            return 0
        g.sort()
        s.sort(reverse=True)
        result=0
        for i in s:
            while True:
                try:
                    greedy=g.pop()#这里用了pop，应该是使用下标更快
                    if i>=greedy:
                        result+=1
                        break
                except:
                    return result
        return result
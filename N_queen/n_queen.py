class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        result=[]
        columns=[]
        tmp=[]
        for _ in range(n):
            columns.append(0)
        # print(columns)
        def angleline(i,j):
            for dot in tmp:
                if abs(dot[0]-i)==abs(dot[1]-j):
                    return True
                else:
                    continue
            return False
        # def angleline(i,j):
        #     for dot in tmp:
        #         if abs(dot[0]-i)==abs(dot[1]-j):
        #             return True
        #         else:
        #             return False
        #上面这个函数导致程序判断对角线错误，它没有判断全部的前面已经存在的点，只要它计算到与前面的任一点不在对角线他就返回false  
        def my_nqueen(row):

            for j in range(n):
                # print('dot: ',row,j)
                if columns[j]!=1 and  not angleline(row,j):
                    columns[j]=1
                    # print(columns)
                    tmp.append((row,j))
                    if row==n-1:
                        result.append(tmp[:])#list[:]会复制列表
                        #print('ok')
                        tmp.pop()
                        columns[j]=0
                    else:
                        # print(tmp)
                        my_nqueen(row+1)
                        tmp.pop()
                        columns[j]=0

        my_nqueen(0)
        # print(result[0:4])
        # print(len(result))
        result_str=[]
        for answer in result:
            tmp_str=[]
            for dot in answer:
                x=''
                for i in range(n):
                    if i !=dot[1]:
                        x+='.'
                    else:
                        x+='Q'
                tmp_str.append(x)
            result_str.append(tmp_str)
        return result_str
test=Solution()
a=test.solveNQueens(8)
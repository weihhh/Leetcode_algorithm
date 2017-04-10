#*<font color=DarkSlateGray>leetcode5</font>*
一个网格最小路径题目。
####题目描述：
>>Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path. Note: You can only move either down or right at any point in time.


####代码（python）：	

```python
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        length_horizontal=len(grid[0])
        length_vertical=len(grid)
        for i in range(length_vertical):
        	for j in range(length_horizontal):
        		if i==0 and j!=0:
        			grid[i][j]=grid[i][j]+grid[i][j-1]#只能从左面过来
        		elif i!=0 and j==0:
        			grid[i][j]=grid[i][j]+grid[i-1][j]#只能从上面过来
        		elif i!=0 and j!=0:
        			grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j]#只能从上面或左面过来
        return grid[length_vertical-1][length_horizontal-1]

```
####经验：
1.一个网格如果被经过的话，只能从上或者左边，除了第一行和第一列特殊。





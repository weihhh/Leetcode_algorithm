#*<font color=DarkSlateGray>leetcode9</font>*
全排列的问题，主要思路就是要注意数字末尾的减序列。
####题目描述：
>>Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
>1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


####代码（python）： 

```python
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1) return;
        
        int i = (int)num.size() - 1;
        while (i > 0 && num[i] <= num[i-1])
            --i;
        if (i == 0) {
            reverse(num.begin(), num.end());
            return;
        }
        
        --i;
        int j = (int)num.size() - 1;
        while (!(num[i] < num[j])) 
            --j;
        
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
    }
};         
```
####经验：
1.i为末尾减序列往前数顶部的位号，则在这个减序列中找到比i-1位号处数字稍大的数，交换，然后将末尾减序列倒过来即可。





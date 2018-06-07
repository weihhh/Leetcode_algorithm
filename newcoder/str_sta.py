import sys
from collections import Counter
input_str1=sys.stdin.readline().strip('\n')
c=Counter(input_str1.lower())
# print(c)
result=[]
for i in input_str1.lower():
    if c[i]==1:
        result.append('(')
    else:
        result.append(')') 
print(''.join(result))
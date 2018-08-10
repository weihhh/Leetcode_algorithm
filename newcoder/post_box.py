import sys
input_str=list(sys.stdin.readline().strip().split(' '))
# print(input_str)
# exit()
input_str=[int(i) for i in input_str]
# input_str=list('H kz k xif.'.upper())
N=input_str[-1]
homes=input_str[:-1]

f=[[10000 for _ in range(len(homes)+1)] for _ in range(N+1)]
#递推关系f[i][j]代表i个邮局覆盖前j村庄，f[i][j]=min(f[i-1][k]+cal_dis[k+1][j])
#cal_dis计算用一个邮局覆盖x到y之间村庄带来的路程
def cal_dis(x,y):
    middle=(x+y)//2#中位数序号
    tmp=0
    for i in range(x,y+1):
        tmp+=abs(homes[i]-homes[middle])
    return tmp

#首先设置起始条件，用一个邮局去覆盖k个村庄
for i in range(1,len(homes)+1):
    f[1][i]=cal_dis(0,i-1)
for i in range(2,N+1):#1已经算过
    for j in range(2,len(homes)+1):#前j个
        for k in range(i,len(homes)):#不会用多于村庄数的邮局去覆盖
            f[i][j]=min(f[i][j],f[i-1][k]+cal_dis(k,j-1))
            # print(f)
            # print('\n')

print(f[N][len(homes)])
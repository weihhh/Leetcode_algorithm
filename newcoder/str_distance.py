# a='ixotitbgzoknoghrrjjwageedzjaghsjvqeqptfphqkvdtevqjjxqgdwfqunvxpxthzzjeprbcvmyphduapyoargbqmizivhfryqdonlritniosmdvuiyhdoykojzvauymskrzrncufasqzuerdehpqceclpbjtvbebuullzaqtokgkfzznumkvvdgwvuiacetbcbmbcrdoemcfjbuw'
# b='nqbgetlzozptuajfmvpzqqkuuxrwlhjcuyohpcnzpgkgmieuuavdetngrrxlxfauugyccklhjbsdqriznggbgvmcbamzdtdffpujnxhosgvbllnyoqpvuamsylyxtpqhcbfxhrdznwswmcxhvmrhttipapeshhdzjpmkucwqtztfsyxzwupmdgmlcatlqqwglekqmrojldjfjmthmiriyyavtznlosbixdtjxsjtzfyvvvwsqqfpmxbnkzwotuelfqjlctoaobu'
import sys
# a=sys.stdin.readline().strip()
# b=sys.stdin.readline().strip()
cd=1#delete
ci=1#insert
cr=1#replace

def calstrdis(a,b):
    lena=len(a)
    lenb=len(b)

    dis=[[0 for j in range(lenb+1)] for i in range(lena+1) ]

    for i in range(lena+1):
        dis[i][0]=i
    for j in range(lenb+1):
        dis[0][j]=j
    for i in range(1,lena+1):
        for j in range(1,lenb+1):
            #delete
            cost_d=dis[i-1][j]+cd
            #insert
            cost_i=dis[i][j-1]+ci
            if a[i-1]==b[j-1]:
                #right
                cost_r=dis[i-1][j-1]
            else:
                #replace
                cost_r=dis[i-1][j-1]+cr
            dis[i][j]=min((cost_d,cost_i,cost_r,cost_r))
    print(dis[lena][lenb])
while True:
    try:
        #方案一
        a=sys.stdin.readline().strip()
        b=sys.stdin.readline().strip()
        # if not a:
        #     break
        #方案二
        # a=input()
        # b=input()
        # print(a,b)
        # print(len(a),len(b))
        calstrdis(a,b)
    except:
        # print('except!')
        break


###########################
# def editDistance(str1, str2):
#     len1, len2 = len(str1) + 1, len(str2) + 1
#     dp = [[0 for i in range(len2)] for j in range(len1)]
#     for i in range(len1):
#         dp[i][0] = i
#     for j in range(len2):
#         dp[0][j] = j
#     for i in range(1, len1):
#         for j in range(1, len2):
#             dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (str1[i - 1] != str2[j - 1]))
#     return dp[-1][-1]
# while True:
#     try:
#         print(editDistance(input(), input()))
#     except:
#         break
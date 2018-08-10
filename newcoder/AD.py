import sys
input_str=list(sys.stdin.readline().strip().split(' '))
# print(input_str)
# exit()
input_str=[int(i) for i in input_str]
# input_str=list('H kz k xif.'.upper())
N=input_str[-1]

def cal_sum(y,homes,best):
    min_tmp=0
    now_place=homes[y]
    for i,home in enumerate(homes):
        if best[i]>abs(home-now_place):
            min_tmp+=(best[i]-abs(home-now_place))
    return min_tmp
def update(y,homes,best):
    now_place=homes[y]
    for i in range(len(homes)):
        if best[i]>abs(homes[i]-now_place):
            best[i]=abs(homes[i]-now_place)

places=[0 for home in input_str[:-1]]
# best=[sys.maxsize for home in input_str[:-1]]
best=[200 for home in input_str[:-1]]
# print(best)
for i in range(N):
    # best=[100000 for home in input_str[:-1]]
    tmp_sum=0
    tmp_i=None
    for j,place in enumerate(places):
        if place==1:
            continue
        now_best=cal_sum(j,input_str[:-1],best)
        print(now_best)
        if now_best>tmp_sum:
            tmp_sum=now_best
            tmp_i=j
    places[tmp_i]=1
    update(tmp_i,input_str[:-1],best)
    print(tmp_i)
    print(best)

print(sum(best))





# for i,s in enumerate(input_str):
#     s_upper=s.upper()
#     if s_upper in natural_key:
#         str_index=natural_key.index(s_upper)
#         if s.islower():
#             input_str[i]=key_st[str_index].lower()
#         else:
#             input_str[i]=key_st[str_index]
# print(''.join(input_str))
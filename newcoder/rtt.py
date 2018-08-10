import sys
input_str=list(sys.stdin.readline().strip().split(' '))
# print(input_str)
# exit()
input_str=[int(i) for i in input_str]
# input_str=list('H kz k xif.'.upper())
N=input_str[-1]
homes = input_str[0:-1]
split_index = []
home_index = []
L = 0
cnt = 0
for i in range(len(homes) - 1):
    for j in range(N - 1):
        if homes[i] <= (homes[-1]*(j + 1))/N and homes[i+1] >= (homes[-1]*(j + 1))/N :
            split_index.append(i)
split_index.append(len(homes) - 1)

for i in range(len(split_index)):
    if i == 0:
        home_index.append(int(split_index[i]/2))
    else:
        home_index.append(int((split_index[i] + split_index[i - 1] + 1)/2))
for i in  range(len(homes)):
    if homes[i] <= homes[split_index[cnt]]:
        L = L + abs(homes[i] - homes[home_index[cnt]])
    else:
        cnt = cnt + 1

        L = L + abs(homes[i] - homes[home_index[cnt]])
print(L)

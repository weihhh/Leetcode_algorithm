# import sys
import re
# input_str=list(sys.stdin.readline().strip().split(':'))
input_str='FE81:0001:0000:0000:FF01:0203:0405:0607'
input_str=input_str.split(':')
# print(bin(int(input_str[0],16))[2:])
# print(bin(int(input_str[1],16))[2:])
okchar=[str(i) for i in range(10)]+['A','B','C','D','E','F']
tmp=[]
for i in input_str:
    for char in i:
        if char not in okchar:
            print('Error')
    binary=list(bin(int(i,16))[2:])
    binary_full=list('0'*16)
    for j in range(-1,-len(binary)-1,-1):
        binary_full[j]=binary[j]
    binary_full=''.join(binary_full)
    tmp.append(binary_full)
# tmp=[bin(int(i,16))[2:] for i in input_str]
tmp=''.join(tmp)
# print(len(tmp),tmp)
if tmp=='0'*128:
    print('Unspecified')
else:
    if tmp.find('1111111010',0,10)!=-1:
        print('LinkLocal')
    else:
        if tmp=='0'*127+'1':
            print('Loopback')
        else:
            if tmp.find('1111111011',0,10)!=-1:
                print('SiteLocal')
            else:
                if tmp.find('11111111',0,8)!=-1:
                    print('Multicast')
                else:
                    print('GlobalUnicast')

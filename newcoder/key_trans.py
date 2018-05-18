import sys
key_st=list('QWERTYUIOPASDFGHJKLZXCVBNM')
natural_key=list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
input_str=list(sys.stdin.readline().strip())
# input_str=list('H kz k xif.'.upper())
for i,s in enumerate(input_str):
    s_upper=s.upper()
    if s_upper in natural_key:
        str_index=natural_key.index(s_upper)
        if s.islower():
            input_str[i]=key_st[str_index].lower()
        else:
            input_str[i]=key_st[str_index]
print(''.join(input_str))
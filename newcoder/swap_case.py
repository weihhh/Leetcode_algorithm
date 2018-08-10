import sys
input_str=list(sys.stdin.readline().strip().split(';'))[:-1]
target=sys.stdin.readline().strip()
inplacekeys=['int','float','long','double','bool']
type_dict={}
for i,line in enumerate(input_str):
    keys=list(line.split(' '));
    if(len(keys)!=3):
        print('none')
        exit()
    if(keys[0]!='typedef'):
        print('none')
        exit()
    base=keys[1]
    base_index=keys[1].find('*')
    point=None
    if base_index!=-1:
        base=keys[1][:base_index]
        point=keys[base_index:]
    if i==0:
        if(base not in inplacekeys):
            print('none')
            exit()
        type_dict[keys[2]]=keys[1]
    else:
        if (base not in inplacekeys) and (base not in type_dict):
            print('none')
            exit()
        type_dict[keys[2]]=keys[1]

answer=target
point_all=''
if target in inplacekeys:
    print(target)
    exit()
# print(type_dict)
while (answer in type_dict):
    answer=type_dict[answer]
    # print(answer)
    base_index=answer.find('*')
    # print(base_index)
    if base_index!=-1:
        point_all+=answer[base_index:]
        answer=answer[:base_index]
point_all=list(point_all)       
if answer in inplacekeys:
    print(answer+' '+' '.join(point_all))
    exit()
print('none')
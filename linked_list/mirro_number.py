target=3
def create_mirro(n):
    result=[]
    if n==1:
        return ['0','1','8']
    if n==2 and target==2:
        return ['11','88','69','96']
    if n==2 and target !=2:
        return ['00','11','88','69','96']
    list_of_innermirro=create_mirro(n-2)
    for i in list_of_innermirro:
        if n!=target:
            result.append('0'+i+'0')#最外层不能为0，否则位数不对
        result.append('8'+i+'8')
        result.append('6'+i+'9')
        result.append('9'+i+'6')
        result.append('1'+i+'1')
    return result
x=create_mirro(target)
# result=[i for i in x if int(i)!=0 or target==1]
#c++可以考虑用字符串n次拼接后相等
print(x)


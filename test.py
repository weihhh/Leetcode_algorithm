   
'''
def accessVarFromNestedFunc():  
    localVarInParent = [1]; #here just define a list, first value is what we want to use  
    x=2
    def nestedFunc(): #  
        localVarInParent[0] = localVarInParent[0] + 1 ; # localVarInParent[0] is the first value of above list value: localVarInParent, and its initial value is 1  
        nonlocal x
        x=x+1
        print ("In nested func, localVarInParent[0]=",localVarInParent[0],':',x);#2,3,4,5,6  
    
    for i in range(5):  
        nestedFunc();  
        # here can got value is 6, which is changed after nested function  
        print ("In current parent nesting func, localVarInParent[0]=",localVarInParent[0],x); #In current parent nesting func, localVarInParent[0]= 6  
       
if __name__ == "__main__":  
    accessVarFromNestedFunc(); 
'''
for i in range(5,0,-1):
    print(i)
#堆排序算法,原始数据存于数组中（list的子类）这里i都是以1开始计算，所以data[]的时候都减一

class array_for_heap(object):
    """docstring for array_for_heap"""
    def __init__(self, data,length):
        super(array_for_heap, self).__init__()
        self.length =length
        self.data_list=data
        
#维护堆
def max_heapify(data,i):
    '''
    data:原始数据数组（list的子类）
    i：对序号为i的节点的子树进行排序
    '''
    #根据完全二叉树性质得到左右孩子序号
    left_i=i*2
    right_i=i*2+1
    if left_i<=data.heapsize and data.data_list[left_i-1]>data.data_list[i-1]:#如果序号小于等于数组中有效堆元素的个数，则左孩子存在
        largest=left_i
    else:
        largest=i
    if right_i<=data.heapsize and data.data_list[right_i-1]>data.data_list[largest-1]:
        largest=right_i
    if largest!=i:
        data.data_list[i-1],data.data_list[largest-1]=data.data_list[largest-1],data.data_list[i-1]#交换值
        #改变了当前三角的位置，可能造成子树的不正确，所以递归进行维护
        max_heapify(data,largest)
#建造堆
def build_heap(data):
    #data:初始数据，只进行一次建堆
    data.heapsize=data.length
    for i in range(data.length//2,0,-1):
        max_heapify(data,i)
#进行排序
def heapsort(data):
    build_heap(data)
    for i in range(data.length,1,-1):#不包含最后的1，进行n-1次循环
        data.data_list[i-1],data.data_list[0]=data.data_list[0],data.data_list[i-1]#将最大的元素放到末尾,最后的元素放到第一位，这个元素会影响整个堆，所以最后进行重新维护，即不断将后面的元素放到第一位
        data.heapsize-=1#将最后的元素排除到堆之外，表示已经排好序
        max_heapify(data,1)
data=[1,5,3,7,56,8,11,6]
test=array_for_heap(data,len(data))  

heapsort(test)   
print(test.data_list)

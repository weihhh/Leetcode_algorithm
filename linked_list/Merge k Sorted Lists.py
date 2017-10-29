# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        class least_prio_queue(object):
            """docstring for least_prio_queue
                data:需要在队列中维护的原始数据列表
                key:用于得到比较元素大小的特征的函数

            """
            def __init__(self,data,key=lambda x:x):
                super(least_prio_queue, self).__init__()
                self.data = data
                self.key=key
                self.length=len(data)#记录了当前存储堆的列表长度，其中有些部分可能没有用作堆
                self.heapsize=self.length#记录堆长度
                self.build_heap(self.data,self.key)

            #维护堆
            def max_heapify(self,data,i,key=lambda x:x):
                '''
                data:原始数据数组（list的子类）
                i：对序号为i的节点的子树进行排序
                '''
                #根据完全二叉树性质得到左右孩子序号
                left_i=i*2
                right_i=i*2+1
                if left_i<=self.heapsize and key(data[left_i-1])<key(data[i-1]):#如果序号小于等于数组中有效堆元素的个数，则左孩子存在
                    smallest=left_i
                else:
                    smallest=i
                if right_i<=self.heapsize and key(data[right_i-1])<key(data[smallest-1]):
                    smallest=right_i
                if smallest!=i:
                    data[i-1],data[smallest-1]=data[smallest-1],data[i-1]#交换值
                    #改变了当前三角的位置，可能造成子树的不正确，所以递归进行维护
                    self.max_heapify(data,smallest)

            #建造堆
            def build_heap(self,data,key=lambda x:x):
                #data:初始数据，只进行一次建堆
                for i in range(self.length//2,0,-1):
                    self.max_heapify(data,i,key)
            #返回最小元素
            def heap_min(self):
                return data[0]
            #返回最小并删除最小的元素
            def heap_extract_min(self):
                if self.heapsize<1:
                    print('no element!')
                max_element=self.data[0]
                self.data[0]=self.data[self.heapsize-1]
                self.heapsize-=1
                self.max_heapify(self.data,1,self.key)#因堆逻辑中以1为第一个序号
                return max_element
            #打印当前堆
            def show_heap(self):
                print(data[:self.heapsize])
            #增加序号为x的元素的值到k(只针对数据对象为数字，而不是包含数字的类)
            def decrease_key(self,x,k):
                if k<self.key(data[x-1]):
                    print('err : not bigger than before!')
                data[x-1]=k
                while x>1 and self.key(data[x//2-1])>self.key(data[x-1]):#因为是减小，所以往上交换即可，下面肯定还是满足堆特性
                    data[x//2-1],data[x-1]=data[x-1],data[x//2-1]
                    x=x//2
            #插入元素
            def insert(self,element):
                self.heapsize+=1
                if self.heapsize>self.length:#堆长度超过用于存储的列表长度，加长列表
                    self.data.extend([0,0,0,0,0])
                self.data[self.heapsize-1]=element
                i=self.heapsize
                while i>1 and self.key(self.data[i//2-1])>self.key(self.data[i-1]):#因为是减小，所以往上交换即可，下面肯定还是满足堆特性
                    self.data[i//2-1],self.data[i-1]=self.data[i-1],self.data[i//2-1]
                    i=i//2


        if not lists:
            return None

        dummy=ListNode(0)
        now=dummy
        nodes=len(lists)
        my_queue=least_prio_queue([i for i in lists if i],lambda x:x.val)
        while my_queue.heapsize>=1:
            now_node=my_queue.heap_extract_min()
            if now_node.next:
                my_queue.insert(now_node.next)
            now.next=now_node
            now=now.next
        return dummy.next




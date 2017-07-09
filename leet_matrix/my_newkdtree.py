#可以多维数据的kd树
import my_Traversal_binarytree
import numpy as np
import math


#data= [[0,1,1,0,0],[0,1,1,0,0],[0,1,0,0,1],[1,1,1,1,0],[1,0,0,1,0]]
data=[[1, 1, 0, 0, 1, 0, 0, 1, 1, 0], [1, 0, 0, 1, 0, 1, 1, 1, 1, 1], [1, 1, 1, 0, 0, 1, 1, 1, 1, 0], [0, 1, 1, 1, 0, 1, 1, 1, 1, 1], [0, 0, 1, 1, 1, 1, 1, 1, 1, 0], [1, 1, 1, 1, 1, 1, 0, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 0, 0, 1], [1, 1, 1, 1, 1, 0, 0, 1, 1, 1], [0, 1, 0, 1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 0, 1, 0, 1, 1, 1, 1]]

class my_kdtree_node(object):
    """docstring for my_kdtree_node"""
    def __init__(self, point,split):
        super(my_kdtree_node, self).__init__()
        self.point = point
        self.split=split#当前用于切分的维度
        self.left = None
        self.right =None


def biuld_my_mutikdtree(datalist):
    """ 
    data_list:数据点的集合(无序) 
    return:构造的KDTree的树根 
    """ 
    length=len(datalist)
    if length==0:
        return
    
    dimension=len(datalist[0])#数据的维度
    max_var=0
    split=0
    for i in range(dimension):#确定数据各个维度中哪个方差最大
        tmplist=[]
        for t in datalist:
            tmplist.append(t[i])#将某一维度中的数据放进tmplist
        var=computevar(tmplist)
        if var>max_var:
            max_var=var
            split=i
    datalist.sort(key=lambda x:x[split])#确定维度后根据此维度进行排序
    point=datalist[length//2]
    root=my_kdtree_node(point,split)
    root.left=biuld_my_mutikdtree(datalist[:(length//2)])
    root.right=biuld_my_mutikdtree(datalist[(length//2)+1:])
    return root

def computevar(datalist):
    return np.var(datalist)
    # for ele in datalist:  
    #     ele = float(ele)  
    # LEN = len(datalist)  
    # array = np.array(datalist)  
    # sum1 = array.sum()  
    # array2 = array * array  
    # sum2 = array2.sum()  
    # mean = sum1 / LEN  
    # #D[X] = E[x^2] - (E[x])^2  
    # variance = sum2 / LEN - mean**2  
    # return variance  

def find_nearest_node(tree_root,target):
    """ 
    tree_root:KDTree的树根 
    target:查询点 
    return:返回距离data最近的点NN，同时返回最短距离min_dist 
    """  
    #初始化为root的节点
    nearest_point=tree_root.point
    min_dist=computedist(target,nearest_point)
    path_nodes=[]
    now_node=tree_root
    while now_node:#监测是否到底，到底则子节点为None
        path_nodes.append(now_node)
        now_dist=computedist(target,now_node.point)
        if now_dist<min_dist:
            nearest_point=now_node.point
            min_dist=now_dist
        split_dimension=now_node.split
        if target[split_dimension] <= now_node.point[split_dimension]:
            now_node=now_node.left
        else:
            now_node=now_node.right
    #经过这样一路二叉选择下来，记录了路径，还有所有路过点到目标点的距离最小值及对应点
    #下面开始回溯，查找是否需要对另一边子树进行查找最近点，回溯的过程就是确定是否有必要进入相邻子空间进行搜索，确定的依据就是当前点到最近点的距离d是否大于当前点到分割面（在二维空间中实际上就是一条线）的距离L
    print([(i.point,i.split) for i in path_nodes])
    while path_nodes:
        #利用list模拟栈，后进先出
        point_get=path_nodes.pop() 
        split_dimension=point_get.split
        # print() 
        #判断是否进入此节点的子节点空间,现在的目标点肯定在某一边，且这一边的点都进行过距离计算，不会比min_dist小，所以不会来回反复的进入
        if abs(target[split_dimension]-point_get.point[split_dimension])<=min_dist:
            #判断是在左还是右子节点
            if target[split_dimension]<=point_get.point[split_dimension]:
                tmp_node=point_get.right
            else:
                tmp_node=point_get.left
            if tmp_node:
                cur_point,cur_dist=find_nearest_node(tmp_node,target)
                if min_dist>cur_dist:
                    min_dist=cur_dist
                    nearest_point=cur_point
    return nearest_point,min_dist

def computedist(pt1, pt2):  
    """ 
    计算两个数据点的距离 
    return:pt1和pt2之间的距离 
    """  
    sum = 0.0  
    for i in range(len(pt1)):  
        sum = sum + (pt1[i] - pt2[i]) * (pt1[i] - pt2[i])  
    return math.sqrt(sum)  



T=list()
for x,one_list in enumerate(data):
    for y,data in enumerate(one_list):
        if data==0:
            T.append([x,y])
kd_tree=biuld_my_mutikdtree(T)
print(find_nearest_node(kd_tree,[9,8]))
test=my_Traversal_binarytree.my_btree(kd_tree)
test.show_tree() 

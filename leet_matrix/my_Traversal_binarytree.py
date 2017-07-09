#Traversal_binarytree

import matplotlib.pyplot as plt

class my_btree(object):
    """docstring for my_btree"""
    def __init__(self, btree):
        super(my_btree, self).__init__()
        self.btree=btree
        self.ori_x = 0
        self.ori_y=0
        self.fig = plt.figure()
        self.ax = plt.axes(xlim=(-10, 10), ylim=(-10, 10))
        self.x_list=[]
        self.y_list=[]
        self.gap=100#控制xy的增量，即间隔
        self.gap_add=10#控制x，y之间的间隔差

    def my_traversal(self,btree,x,y,gap):
        if btree:
            self.add_node(btree.point,x,y)
            if btree.left:
                self.my_traversal(btree.left,x-gap+self.gap_add,y-gap,gap-gap/7)
                line, = self.ax.plot([], [], 'g', lw=2)
                line.set_data([x,x-gap+self.gap_add], [y, y-gap])
            if btree.right:
                self.my_traversal(btree.right,x+gap-self.gap_add,y-gap,gap-gap/2)
                line, = self.ax.plot([], [], 'g', lw=2)
                line.set_data([x,x+gap-self.gap_add], [y, y-gap])

    def add_node(self,point,x,y):
        #label_1 = self.ax.text([x], [y],str(point[0])+','+str(point[1]))#第一列表x，第二个y，最后字符串为显示的字符串
        label_1 = self.ax.text([], [], '')
        label_1.set_text(point)#设置label的文字
        label_1.set_position([x, y])#设定标注label的x，y位置
        self.x_list.append(x)
        self.y_list.append(y)

        #print(point)    

    def show_tree(self):
        self.my_traversal(self.btree,self.ori_x,self.ori_y,self.gap)
        plt.plot(self.x_list,self.y_list, 'bo')
        plt.axis([min(self.x_list)-2,max(self.x_list)+2,min(self.y_list)-2,max(self.y_list)+2])
        plt.grid(True)#产生网格
        plt.xlabel('x')
        plt.ylabel('y')
        plt.title('plot tree')
        plt.show()

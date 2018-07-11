#include<iostream>
#include<algorithm>
#include<vector>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


void PrintList(RandomListNode* pHead)
{
    while (pHead != NULL)
    {
        if(pHead->random!=NULL)
            cout << pHead->label<<":"<<pHead->random->label<< " ";
        else
            cout << pHead->label<<":"<<"NULL"<< " ";
        pHead = pHead->next;
    }
    cout << endl;
}

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //第一步复制链表元素到每个元素之后
        if(pHead==NULL)
            return pHead;
        RandomListNode* node=pHead;
        cout<<"here1"<<endl;
        while(node!=NULL){
            RandomListNode* tmp=new RandomListNode(node->label);
            tmp->next=node->next;
            node->next=tmp;
            node=tmp->next;
        }
        //定位random,指向原节点之后一个，即为复制后的random
        node=pHead;
        RandomListNode* cloned=NULL;
        cout<<"here2"<<endl;
        while(node!=NULL){
            cloned=node->next;
            if(node->random)//注意这里random可能为null
                cloned->random=node->random->next;
            node=cloned->next;
        }
        PrintList(pHead);
        //拆分为两个链表
        cout<<"here3"<<endl;
        node=pHead;
        RandomListNode* copy_begin=node->next;
        cloned=copy_begin;
        node->next=cloned->next;
        node=node->next;//注意node要往前
        while(node!=NULL){
            cloned->next=node->next;
            cloned=cloned->next;//注意cloned和node都要向前
            node->next=cloned->next;
            node=node->next;
        }
        return copy_begin;
    }
};



int main(int argc, char const *argv[])
{

    RandomListNode* pHead=new RandomListNode(1);
    RandomListNode* node1=new RandomListNode(2);
    RandomListNode* node2=new RandomListNode(3);
    pHead->next=node1;
    node1->next=node2;
    node1->random=pHead;
    node2->random=node1;
    PrintList(pHead);
    Solution st;
    RandomListNode* copy=st.Clone(pHead);
    PrintList(copy);
    return 0;
}
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL||(pHead->next)==NULL)//注意这里为或
            return pHead;
        //共需要三个指针相邻往后移动
        ListNode* walker_before=NULL,*walker_now=pHead;
        ListNode* tmp=pHead->next;
        
        while(walker_now!=NULL){
            walker_now->next=walker_before;
            if(tmp==NULL)
                break;
            walker_before=walker_now;
            walker_now=tmp;
            tmp=walker_now->next;
        }
        return walker_now;
    }
};
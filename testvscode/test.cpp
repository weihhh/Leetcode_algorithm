#include<iostream>
using namespace std;  
  
struct ListNode  
{  
    int m_Value;  
    ListNode* pNext;  
};  
  
ListNode* CloneList(ListNode* pHead)  
{  
    ListNode* pNode = pHead;  
    ListNode* pCloneHead, *pCloneNode;  
    if (pNode != NULL)  
    {  
        pCloneHead = new ListNode();  
        pCloneHead->m_Value = pNode->m_Value;  
        pCloneHead->pNext = NULL;  
        pCloneNode = pCloneHead;  
        pNode = pNode->pNext;  
    }  
    while (pNode != NULL)  
    {  
        ListNode* pTempNode = new ListNode();  
        pTempNode->m_Value = pNode->m_Value;  
        pTempNode->pNext = NULL;  
        pCloneNode->pNext = pTempNode;  
        pCloneNode = pCloneNode->pNext;  
        pNode = pNode->pNext;  
    }  
    return pCloneHead;  
}  
  
bool printList(ListNode* pHead)  
{  
    ListNode* pNode = pHead;  
    if(pNode == NULL)  
        return false;  
    while(pNode)  
    {  
        cout<<pNode->m_Value<<endl;  
        pNode = pNode->pNext;  
    }  
    return true;  
}  
  
ListNode * CreatList()  
{  
    ListNode * pHead = new ListNode();  
    pHead->m_Value = 1;  
    pHead->pNext = NULL;  
    ListNode* pNode = pHead;  
    for(int i=2;i<=10;i+=2)  
    {  
        ListNode* pTempNode = new ListNode();  
        pTempNode->m_Value = i;  
        pTempNode->pNext = NULL;  
        pNode->pNext = pTempNode;  
        pNode = pNode->pNext;  
    }  
    return pHead;     
}  
int main()  
{  
    ListNode* pHead = CreatList();  
    if (CloneList(pHead))  
    {  
        printList(pHead);  
    }  
    else  
    {  
        cout<<"Initial the list erro!!"<<endl;  
    }  
    system("pause");  
    return 0;  
}  


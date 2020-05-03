struct  ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* ReverseList(ListNode *pHead)
{
    ListNode* pReversedHead=nullptr;
    ListNode* pNode=pHead;
    ListNode* pPrev=nullptr;
    while (pNode!=nullptr)
    {
        ListNode* pNext=pNode->m_pNext;
        if(pNext==nullptr)
            pReversedHead=pNode;
        
        pNode->m_pNext=pPrev;
        pNode=pNext;
    }
    return pReversedHead;
}
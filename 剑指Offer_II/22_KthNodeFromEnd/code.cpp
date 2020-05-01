struct  ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* FindKthToTail(ListNode* pListHead,unsigned int k)
{
    if(pListHead==nullptr||k<=0)
        return nullptr;

    ListNode *pAhead=pListHead;
    ListNode *pBehind=nullptr;

    for(unsigned int i=0;i<k-1;i++)
    {
        if(pAhead->m_pNext!=nullptr)
            pAhead=pAhead->m_pNext;
        else
            return nullptr;
    }

    pBehind=pListHead;
    while(pAhead->m_pNext!=nullptr)
    {
        pAhead=pAhead->m_pNext;
        pBehind=pBehind->m_pNext;
    }
    return pBehind;
}

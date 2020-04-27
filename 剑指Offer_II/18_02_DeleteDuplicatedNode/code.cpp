struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void DeleteDuplication(ListNode** pHead)
{
    if(pHead==nullptr||*pHead==nullptr)
        return;

    ListNode* pPreNode=nullptr;
    ListNode* pNode=*pHead;
    while (pNode!=nullptr)
    {
        ListNode* pNext=pNode->m_pNext;
        bool needDelete=false;
        if(pNext!=nullptr&&pNext->m_nValue==pNode->m_nValue)
            needDelete=true;
        
        if(!needDelete)
        {
            pPreNode=pNode;
            pNode=pNode->m_pNext;
        }else
        {
            int value=pNode->m_nValue;
            ListNode* pToBeDel=pNode;
            while(pToBeDel!=nullptr&&pToBeDel->m_nValue==value)
            {
                pNext=pToBeDel->m_pNext;

                delete pToBeDel;
                pToBeDel=pNext;
            }
            if(pPreNode==nullptr)
                *pHead=pNext;
            else
                pPreNode->m_pNext=pNext;
            pNode=pNext;
        }
    }
    
}
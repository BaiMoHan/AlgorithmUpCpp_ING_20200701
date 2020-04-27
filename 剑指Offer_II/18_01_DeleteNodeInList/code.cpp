struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
    if(!pListHead||!pToBeDeleted)
        return;

    //要删除的节点不是尾节点
    if(pToBeDeleted->m_pNext!=nullptr)
    {
        ListNode* pNext=pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue=pNext->m_nValue;
        pToBeDeleted->m_pNext=pNext->m_pNext;

        delete pNext;
        pNext=nullptr;
    }

    //链表只有一个节点,删除头节点(也是尾节点)
    else if(*pListHead==pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted=nullptr;
        *pListHead=nullptr;
    }
    //删除尾节点
    else
    {
        ListNode* pNode=*pListHead;
        while(pNode->m_pNext!=pToBeDeleted)
        {
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext=nullptr;
        delete pToBeDeleted;
        pToBeDeleted=nullptr;
    }
}
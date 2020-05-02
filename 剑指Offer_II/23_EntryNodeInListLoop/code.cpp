struct  ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* MeetingNode(ListNode* pHead)
{
    if(pHead==nullptr)
        return nullptr;

    ListNode *pSlow=pHead->m_pNext;
    if(pSlow==nullptr)
        return nullptr;

    ListNode *pFast=pSlow->m_pNext;
    while (pFast!=nullptr&&pSlow!=nullptr)
    {
        if(pFast==pSlow)
            return pFast;

        pSlow=pSlow->m_pNext;
        pFast=pFast->m_pNext;
        if(pFast!=nullptr)
            pFast=pFast->m_pNext;
    }
    return nullptr;
}
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode *meetingNode=MeetingNode(pHead);
    if(meetingNode==nullptr)
        return nullptr;

    //得到环中节点的数目
    int nodeInLoop=1;
    ListNode *pNode1=meetingNode;
    while (pNode1->m_pNext!=meetingNode)
    {
        pNode1=pNode1->m_pNext;
        ++nodeInLoop;
    }

    //先移动pNode1，次数为环中节点的数目
    pNode1=pHead;
    for(int i=0;i<nodeInLoop;i++)
        pNode1=pNode1->m_pNext;
    
    //再移动pNode1和pNode2
    ListNode *pNode2=pHead;
    while (pNode1!=pNode2)
    {
        pNode1=pNode1->m_pNext;
        pNode2=pNode2->m_pNext;
    }
    return pNode1;
    
}
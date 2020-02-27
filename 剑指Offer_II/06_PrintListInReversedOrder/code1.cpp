void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;
     
    ListNode* pNode=pHead;
    while(pNode!=nullptr)
    {
        nodes.push(pNode);
        pNode=pNode->m_pNext;
    }

    while (!node.empty())
    {
        pNode=nodes.top();
        printf("%d\t",pNode->m_nValue);
        nodes.pop();
    }
}
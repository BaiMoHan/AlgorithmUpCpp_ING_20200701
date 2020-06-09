struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
void Print(BinaryTreeNode* pRoot)
{
    if(pRoot==nullptr)
        return ;
    
    std::stack<BinaryTreeNode*> levels[2];
    int current=0;
    int next=1;
    
    levels[current].push(pRoot);
    while(!levels[0].empty()||!levels[1].empty())
    {
        BinaryTreeNode* pNode=levels[current].top();
        levels[current].pop();

        printf("%d",pNode->m_nValue);

        if(current==0)
        {
            if(pNode->m_pLeft)
                levels[next].push(pNode->m_pLeft);
            if(pNode->m_pRight)
                levels[next].push(pNode->m_pRight);
        }else
        {
            if(pNode->m_pRight)
                levels[next].push(pNode->m_pRight);
            if(pNode->m_pLeft)
                levels[next].push(pNode->m_pLeft);
        }
        if(levels[current].empty())
        {
            printf("\n");
            current=1-current;
            next=1-next;
        }
    }
}
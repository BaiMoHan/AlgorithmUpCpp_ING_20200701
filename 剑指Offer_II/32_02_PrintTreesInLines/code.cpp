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

    std::queue<BinaryTreeNode*>nodes;
    nodes.push(pRoot);
    int nextLevel=0;
    int toBePrinted=1;
    while(!nodes.empty())
    {
        BinaryTreeNode* pNode=nodes.front();
        printf("%d",pNode->m_nValue);
        if(pNode->m_pLeft)
        {
            nodes.push(pNode->m_pLeft);
            ++nextLevel;
        }
        if(pNode->m_pRight)
        {
            nodes.push(pNode->m_pRight);
            ++nextLevel;
        }
        nodes.pop();
        --toBePrinted;
        if(toBePrinted==0)
        {
            printf("\n");
            toBePrinted=nextLevel;
            nextLevel=0;
        }
    }
}
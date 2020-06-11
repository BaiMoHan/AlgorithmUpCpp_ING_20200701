struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
    if(pRoot==nullptr)
        return;
    
    std::vector<int>path;
    int currentSum=0;
    FindPath(pRoot,expectedSum,path,currentSum);
}
void FindPath(BinaryTreeNode* pRoot,int expectedSum,std::vector<int>& path,int currentSum)
{
    currentSum+=pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    //如果是叶节点且路径上节点值的和等于输入的值，则打印出这条路径
    bool isLeaf=pRoot->m_pLeft==nullptr&&pRoot->m_pRight==nullptr;
    if(currentSum==expectedSum&&isLeaf)
    {
        printf("A path is found:");
        std::vector<int>::iterator iter=path.begin();
        for(;iter!=path.end();++iter)
            printf("%d\t",*iter);

        printf("\n");
    }

    //如果不是叶节点，则遍历它的子节点
    if(pRoot->m_pLeft)
        FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
    if(pRoot->m_pRight)
        FindPath(pRoot->m_pRight,expectedSum,currentSum);

    //在返回父节点前，路径上删除当前节点
    path.pop_back();
}
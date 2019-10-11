struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
}

/*
 * 题目: 从上到下打印二叉树
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 从上到下打印二叉树
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot){
    if(!pTreeRoot){
        return ;
    }
    std::deque<BinaryTreeNode* > dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);

    while(dequeTreeNode.size()){
        BinaryTreeNode* pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        printf("%d", pNode->m_nValue);
        if(pNode->m_pLeft){
            dequeTreeNode.push_back(pNode->m_pLeft);
        }
        if(pNode->m_pRight){
            dequeTreeNode.push_back(pNode->m_pRight);
        }
    }
}

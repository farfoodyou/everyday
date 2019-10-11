
/*
 * 题目: 二叉搜索树与双向链表
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 将二叉搜索树转化为中序的双向链表
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree){
    BinaryTreeNode* pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while(pHeadOfList != nullptr && pHeadOfList->m_pLeft !=nullptr) {
        pHeadOfList = pHeadOfList->m_pLeft;
    }
    return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList){
    if(pNode == nullptr){
        return ;
    }

    BinaryTreeNode* pCurrent = pNode;

    if(pCurrent->m_pLeft != nullptr){
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    }

    pCurrent->m_pLeft = *pLastNodeList;

    if(*pLastNodeInList != nullptr){
        (*pLastNodeInList)->m_Right = pCurrent;
    }

    *pLastNodeInList = pCurrent;

    if(pCurrent->m_pRight != nullptr) {
        CunvertNode(pCurrent->m_pRight, pLastNodeInList);
    }

}

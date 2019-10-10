/*
 * 输入参数: 二叉树某一个结点
 * 输出参数: 无
 * 返回结果: 二叉树当前结点的下一个结点
 * 描述: 返回中序遍历的下一个结点
 * 
*/
BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
    if(pNode == nullptr){
        return nullptr;
    }
    BinaryTreeNode* pNextr = nullptr;
    if(pNode->m_pRight != nullptr) {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != nullptr) {
            pRight = pRight->m_pLeft;
        }
        pNext = pRight;
    } else if {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight) {
            pCurrent = pParent;
            pParent=pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}


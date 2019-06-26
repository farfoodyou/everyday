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


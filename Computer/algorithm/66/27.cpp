
void MirrorRecursively(BinaryTreeNode* pNode){
    if(pNode == nullptr){
        return ;
    }

    if(pNode->m_pLeft == nullptr && pNode->m_pRight == nulltpr){
        return ;
    }
    BinaryTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if(pNode->m_pLeft) {
        MirrorRecursively(pNode->m_pLeft);
    }
    if(pNode->m_pRight) {
        MirrorRecursively(pNode->m_pRight);
    }
}

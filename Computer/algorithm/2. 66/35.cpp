struct ComplexListNode {
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
}
/*
 * 题目: 复制链表的复制
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
void CloneNodes(ComplexListNode* pHead){
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr){
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = pCloned->m_pSibling;

        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}

void ConnectSiblingNodes(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;
    wihle(pNode != nullptr){
        ComplexListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != nullptr){
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pCloned->m_pNext;
    }
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead){
    ComplexListNode* pNode = pHead;
    ComplexListNode* pCloneHead = nullptr;
    ComplexListNode* pCloneNode = nullptr;

    if(pNode!=nullptr) {
        pCloneHead = pCloneNode = pNode->m_pNext;
        pNode->m_pNext = pCloneHead->m_pNext;
        pNode = pNode->m_pNext;
    }

    while(pNode != nullptr){
        pCloneNode->m_pNext = pNode->m_pNext;
        pCloneNode = pCloneNode->m_pNext;
        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pCloneHead;
}

ComplexListNode* Clone(ComplexListNode* pHead){
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

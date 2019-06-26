struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
}

ListNode* ReverseList(ListNode* pHead){
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pRev - nullptr;

    while(pNode != nulltpr){
        ListNode* pNext = pNode->m_pNext;
        if(pNext == nullptr){
            pReversedHead = pNode;
        }
        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

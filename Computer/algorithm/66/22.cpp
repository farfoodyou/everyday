struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
}

ListNode* FindKthToTail(ListNode* pListNode, unsigned int k) {
    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;

    // err
    for(unsigned int i = 0; i<k - 1; ++i){
        if(pAhead->m_nNext != nullptr){
            pAhead = pAhead->m_pNext;
        } else  {
            return nullptr;
        }
    }

    pBegin = pListHead;
    while(pAhead->m_pNext != nullptr){
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}


struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(pHead1 == nullptr){
        return pHead2;
    } else if(pHead2 == nullptr) {
        return pHead1;
    }

    ListNode* pMergeHead = nullptr;
    if(pHead1->m_nValue < pHead2->m_nValue) {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }
    return pMergeHead;
}

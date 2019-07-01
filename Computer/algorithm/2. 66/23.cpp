
ListNode* MeetingNode(ListNode* pHead){
    if(pHead == nullptr) {
        return nullptr;
    }

    ListNode* pSlow = pHead->m_pNext;
    if(pSlow == nullptr){
        return nullptr;
    }

    ListNode* pFast = pSlow->m_pNext;
    while(pFast != nullptr && pSlow !=nullptr) {
        if(pFast == pSlow){
            return pFast;
        }
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
        if(pFast != nullptr){
            pFast = pFast->m_pNext;
        }
    }
    return nullptr;
}

ListNode* EntryNodeOfLoop(LsitNode* pHead) {
    ListNode* meetingNode = MeetingNode(pHead);
    if(meetingNode == nullptr) {
        return nullptr;
    }

    int nodesInLoop = 1;
    ListNode* pNode1 = meetingNode;
    while(pNode1->m_pNext != meetingNode){
        pNode1 = pNode1->m_pNext;
        ++nodesInLoop;
    }

    pNode1 = pHead;
    for(int i = 0; i<nodesInLoop; ++i){
        pNode1 = pNode1->m_pNext;
    }

    ListNode* pNode2 = pHead;
    while(pNode1 != pNode2){
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;
}

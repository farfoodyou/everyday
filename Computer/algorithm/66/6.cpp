struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
};

void PrintListReversingly_Iteratively(ListNode* pHead){
    std::stack<ListNode*> node;
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        node.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty()){
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
    }
}

void PrintListReversingly_Rcursively(ListNode* pHead) {
    if(pHead !=nullptr){
        if(pHead->m_pNext !=nullptr){
            PrintListReversingly_Rcursively(pHead->m_nKey);
        }
        printf("%d\t", pHead->m_nValue);
    }
}


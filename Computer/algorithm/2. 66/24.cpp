struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
}
/*
 * 题目: 反转链表
 * 输入参数: 链表头节点
 * 输出参数: 反转后的头节点
 * 返回结果: 
 * 描述: 如数一个链表头结点, 将其反转后, 反转后的头结点.
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
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

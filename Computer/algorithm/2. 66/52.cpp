struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
}
/*
 * 题目: 两个链表的第一个公共节点
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 输入两个链表找出第一个公共节点
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);
    int nLengthDiff = nLength - nLength2;

    ListNode* pListHeadLong = pHead1;
    ListNode* pListHeadSort = pHead2;
    if (nLength2 > nLength1) {
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }

    for (int i= 0; i< nLengthDif ; ++i){
        pListHeadLong = pListHeadLong->m_pNext;
    }

    while((pListHeadLong != nullptr) && (pListHeadShort !=nullptr) && (pListHeadLong != pListHeadShort)){
        pListHeadLong = pListHeadLong->m_pNext;
        pListHeadShort = pListHeadShort->m_pNext;
    }

    ListNode* pFirstCommonNode = pListHeadLong;

    return pFirstCommonNode;

}

unsigned int GetListLength(ListNode* pHead){
    unsigned int nLength = 0;
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        ++nLength;
        pNode = pNode->m_pNext;
    }

    return nLength;
}

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
}
/*
 * 题目: 链表中的倒数第k个节点
 * 输入参数: 链表头指针, 数字k
 * 输出参数: 
 * 返回结果: 第k个节点
 * 描述: 输入一个链表, 输出单链表中倒数第k个节点. 题目中链表从1开始算
 * 例如: 
 * 思路: 第一个指针先走k-1步,然后第二个指针再出发
 * 注意事项: 输入的头节点是空指针, 节点数少于k个, k为0等情况
*/
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

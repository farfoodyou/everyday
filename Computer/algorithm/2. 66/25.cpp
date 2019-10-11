
struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
}
/*
 * 题目: 合并连个排序的链表
 * 输入参数: 链表头节点A,列表头节点B
 * 输出参数: 
 * 返回结果: 
 * 描述: 合并两个排序的链表
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
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

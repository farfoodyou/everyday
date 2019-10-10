struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
}
/*
 * 题目: 删除链表的节点
 * 输入参数: 给定单向链表的头指针和一个节点指针, 定义在o1 时间内删除该节点
 * 输出参数: 
 * 返回结果: 
 * 描述: 给定单向链表的头指针和一个节点指针, 定义在o1 时间内删除该节点
 * 例1 输入 1->2->3  2  效果 1->3
 * 
*/
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);


void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
    if(!pListHead || !pToBeDeleted) {
        return;
    }
    if(pToBeDeleted->m_pNext!=nullptr){
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue=pNext->m_nValue;
        pToBeDeleted->m_pNext=pNext->m_pNext;

        delete pNext;
        pNext = nullptr;
    } else if(*pListHead == pToBeDeleted){
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    } else {
        ListNode * pNode = *pListHead;
        while(pNode->m_pNext!= pToBeDeleted){
            pNode = pNode->m_pNext;
        }

        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

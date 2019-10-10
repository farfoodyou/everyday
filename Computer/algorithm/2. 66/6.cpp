/*
 * 链表的结点, 包含了一个值类型, 和指向下一个结点的指针;
*/
struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
};

/*
 * 输入参数: 链表的头指针
 * 输出参数: 无
 * 返回结果: 无
 * 描述: 从尾到头打印链表, 用栈来存储暂时不能打印的结点
 * 
*/
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

/*
 * 输入参数: 链表的头指针
 * 输出参数: 无
 * 返回结果: 无
 * 描述: 从尾到头打印链表, 通过递归来打印
 * 
*/
void PrintListReversingly_Rcursively(ListNode* pHead) {
    if(pHead !=nullptr){
        if(pHead->m_pNext !=nullptr){
            PrintListReversingly_Rcursively(pHead->m_nKey);
        }
        printf("%d\t", pHead->m_nValue);
    }
}


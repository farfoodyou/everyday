/*
 * 题目: 对称的二叉树
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 判断二叉树是否对称
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
bool isSymmetrical(BinaryTreeNode* pRoot){
    return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
    if(pRoot1 == nullptr && pRoot2 == nullptr){
        return true;
    }
    if(pRoot1 == nullptr || pRoot2 == nullptr) {
        return false;
    }
    if(pRoot1->m_nValue != pRoot2->m_nValue){
        return false;
    }
    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) 
        && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}


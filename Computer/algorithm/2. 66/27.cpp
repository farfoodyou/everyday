/*
 * 题目: 二叉树的镜像
 * 输入参数: 二叉树
 * 输出参数: 
 * 返回结果: 
 * 描述: 输入一棵二叉树, 返回它的镜像
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
void MirrorRecursively(BinaryTreeNode* pNode){
    if(pNode == nullptr){
        return ;
    }

    if(pNode->m_pLeft == nullptr && pNode->m_pRight == nulltpr){
        return ;
    }
    BinaryTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if(pNode->m_pLeft) {
        MirrorRecursively(pNode->m_pLeft);
    }
    if(pNode->m_pRight) {
        MirrorRecursively(pNode->m_pRight);
    }
}

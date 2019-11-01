struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
}
/*
 * 题目: 二叉树的深度
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 给一颗二叉树, 求它的深度
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
int TreeDepth(BinaryTreeNode* pRoot){
    if(pRoot == nullptr){
        return 0;
    }
    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}


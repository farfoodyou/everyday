/*
 * 题目: 二叉树搜索树的第a大节点
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 给一颗二叉搜索树, 找到其中第k大的节点
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k){
    if(pRoot == nullptr || k==0){
        return nullptr;
    }
    return KthNodeCore(pRoot, k);
}

BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int &k){
    BinaryTreeNode* target = nullptr;
    if(pRoot->m_pLeft != nullptr){
        target = KthNodeCore(pRoot->m_pLeft, k);
    }
    if(target == nullptr){
        if(k==1){
            target = pRoot;
        }
        k--;
    }
    if(target == nullptr && pRoot->m_pRight != nullptr){
        target = KthNodeCore(pRoot->m_pRight, k);
    }

    return target;
}

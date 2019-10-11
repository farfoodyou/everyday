struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode():m_nValue(0),m_pLeft(NULL),m_pRight(NULL){}
    /* data */
};
/*
 * 题目: 二叉树中和为某一值的路径
 * 输入参数: 二叉树和 某一值
 * 输出参数: 
 * 返回结果: 
 * 描述: 二叉树中和为某一值的路径
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
void FindPath(BinaryTreeNode* pRoot, int expectedSum){
    if(pRoot == nullptr){
        return ;
    }

    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int> & path, int currentSum){
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
    if(currentSum == expectedSum && isLeaf){
        printf("A path is found:");
        std::vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); iter++){
            printf("%d\t", *iter)z
        }
        printf("\n");
    }

    if(pRoot->m_pLeft!=nullptr){
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    }
    if(pRoot->m_pRight!=nullptr){
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
    }

    path.pop_back();
}

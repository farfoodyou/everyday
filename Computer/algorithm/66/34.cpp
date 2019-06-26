struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode():m_nValue(0),m_pLeft(NULL),m_pRight(NULL){}
    /* data */
};

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

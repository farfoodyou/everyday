/*
 * 树节点, 包括了一个值类型, 和指向左右子节点的指针.
*/
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRitht;
}

/*
 * 输入参数: 先序遍历数组, 中序遍历数组, 数据的长度
 * 输出参数: 无
 * 返回结果: 根据输入参数构建好的二叉树
 * 描述: 通过先序遍历结果和中序遍历结果来重新构建二叉树结构
 * 
*/
BinaryTreeNode* Construct(int* preorder, int* inorder,int length){
    if(preorder == nullptr || inorder==nullptr||length <=0){
        return nullptr;
    }
    return ConstructCore(preorder, preorder + length - 1,
        inorder, inorder + length-1);
}

/*
 * 输入参数: 先序遍历数组开头, 先序遍历数组结尾, 中序遍历数组开头, 中序遍历数组结尾
 * 输出参数: 无
 * 返回结果: 根据输入参数构建好的二叉树
 * 描述: 通过先序遍历结果和中序遍历结果来重新构建二叉树结构
 * 
*/
BinaryTreeNode* ConstructCore(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder
) {
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if(startPreorder == endPreorder) {
        if(startInorder == endPreorder && *startPreorder == * endPreorder){
            return root;
        } else {
            throw std::exception("IOnvalid input");
        }
        int* rootInorder = startInorder;
        while(rootInorder <= endInorder && *rootInorder !=rootValue) {
            ++rootInorder;
        }
        if(rootInorder == endInorder && *rootInorder != rootValue){
            throw std::exception("Invalid input");
        }

        int leftLength = rootInorder - startInorder;
        int *leftPreorderEnd = startPreorder + leftLength;
        if(leftLength > 0){
            root->m_pLeft - ConstructCore(startPreorder+1,
            leftPreorderEnd,startInorder, rootInorder -1);
        }
        if(leftLength < endPreorder -startPreorder){
            root->m_pRigth = ConstructCore(leftrPreorderEnd + 1, 
            endPreorder, rootInorder + 1, endInorder);
        }
        return root;
    }
}

/*
 * 题目: 二叉搜索书的后序序列
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 输入一个整数数组, 判断是否是某二叉搜索树的后序序列
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
bool VerifySquenceOfBST(int sequence[], int length){
    if(sequence == nullptr || length <= 0){
        return false;
    }
    int root = sequence[length - 1];

    int i = 0;
    for(;i < length; ++i){
        if(sequence[i] > root) {
            break;
        }
    }

    int j = i;
    for(;j < length- 1; ++j){
        if(sequence[j] < root){
            return false;
        }
    }

    bool left = true;
    if(i >0) {
        left = VerifySquenceOfBST(sequence, i);
    }

    bool right = true;
    if(i < length -1){
        right = VerifySquenceOfBST(sequence+ i, length -i -1);
    }

    return (left && right);
}


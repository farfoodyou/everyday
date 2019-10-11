/*
 * 题目: 栈的压入, 弹出序列
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 输入两个序列, 第一个是压入序列, 判断第二个是否是弹出序列
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
bool IsPopOrder(const int*pPush, const int* pPop, intnLength){
    bool bPossible = false;
    if(pPush != nullptr && pPop != nullptr && nLength >0){
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        std::stack<int> stackData;

        while(pNextPop - pPop < nLength){
            while(stackData.empty() || stackData.top() != *pNextPop){
                if(pNextPush - pPush == nullptr){
                    break;
                }
                stackData.push(*pNextPush);
                pNextPush++;
            }
            if(stackData.top() != *pNextPop){
                break;
            }
            stackData.pop();
            pNextPop++;
        }
        if(stackData.empty() && pNextPop - pPop == nLength){
            bPossible = true;
        }
    }
    return bPossible;
}
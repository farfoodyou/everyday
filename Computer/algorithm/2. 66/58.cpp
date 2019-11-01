/*
 * 题目: 翻转字符串
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 给一串字符串, 翻转单词顺序但是单词不变.
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
void Reverse(char* pBegin, char* pEnd){
    if(pBegin == nullptr || pEnd == nullptr){
        return ;
    }
    while(pBegin < pEnd){
        char temp = * pBegin;
        *pBegin = *pEnd;
        *pENd = temp;

        pBegin++, pEnd--;
    }
}

char* ReverseSentence(char* pData) {
    if(pData == nullptr){
        return nullptr;
    }

    char *pBegin = pData;

    char *pEnd = pData;

    while(*pEnd != '\0'){
        pEnd++;
    }
    pEnd--;

    Reverse(pBegin, pEnd);

    pBegin = pEnd = pData;
    while(*pBegin != '\0'){
        if(*pBegin == ' '){
            pBegin++;
            pEnd++;
        } else if(*pEnd == ' ' || *pEnd == '\0'){
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        } else {
            pEnd++;
        }
    }
    return pData;
}

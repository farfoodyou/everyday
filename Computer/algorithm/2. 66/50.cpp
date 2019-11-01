/*
 * 题目: 第一个只出现一次的字符
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 
 * 例如: 在字符串中第一个只出现一次的字符
 * 思路: 
 * 注意事项: 
*/
char FirstNotRepeatingChar(char* pString){
    if(pString == nullptr){
        return '\0';
    }
    const int tableSize = 256;
    unsigned int hastTable[tableSize];
    for(unsigned int i = 0; i < tableSize; ++i){
        hashTable[i] = 0;
    }
    char* pHashKey = pString;
    wihle(*(pHashKey)!='\0'){
        hashTable[*(pHashKey++)]++;
    }
    pHashKey = pString;
    while(*pHashKey != '\0') {
        if(hashTable[*pHashKey] == 1) {
            return *pHashKey;
        }
        pHashKey++;
    }
    return '\0';
}

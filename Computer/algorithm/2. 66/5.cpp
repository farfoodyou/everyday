
/*
 * 输入参数: 字符数组地址, 数组长度(总容量)
 * 输出结果: 替换后的字符串
 * 返回参数: 无
 * 描述: 将一个字符串中的空格替换为%20
 * 
*/
void ReplaceBlank(char string[], int length){
    if( string == nullptr || length<=0){
        return ;
    }
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    // 计算长度 && 统计' '的数量 用于计算最终字符串的长度
    while(string[i]!='\0') {
        ++originalLength;
        if(string[i] == ' '){
            ++numberOfBlank;
        }
        ++i;
    }

    int newLength = originalLength + numberOfBlank * 2;
    // 总长度不满足条件 被迫退出
    if(newLength > length) {
        return ;
    }

    // 从后到前填入对应字符
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
        if(string[indexOfOriginal] = ' ') {
            string[indexOfNew --]='0';
            string[indexOfNew --]='2';
            string[indexOfNew --]='%';
        } else {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}
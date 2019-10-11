/*
 * 题目: 表示数值的字符串
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 实现一个函数用来判断字符串是否表示数值(包括整数和小数). 
 * 例如, 字符串 +100 5e2 -123 3.1416 -1E-16 都是数字, 12e 1a3.14 1.2.3 +-5等不是
 * 
*/
bool isNumberic(const char* str){
    if(str == nullptr){
        return false;
    }
    bool numeric = scanInteger(&str);

    if(*str =='.' ){
        ++str;
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    if(*str=='e' || *str == 'E'){
        ++str;
        numeric = numeric && scanIneger(&str);
    }
    return numeric && *str == '\0';
}

bool scanUnsignedInteger(const char** str) {
    const char* before = *str;
    while(**str !='\0' && **str >= '0' && **str <='9') {
        ++(*str);
    }
    return *str > before;
}

bool scanInteger(const char **str){
    if(**str =='+' || **str == '-') {
        ++(*str);
    }
    return scanUnsignedInteger(str);
}


/*
 * 题目: 数字序列中某一位的数字
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
int digitAtIndex(int index) {
    if (index < 0) {
        return -1;
    }
    int digits = 1;
    while(true) {
        int numbers = countOfIntegers(digits);
        if (index < numbers * digits) {
            return digitAtIndex(index, digits);
        }
        index -= digits * numbers;
        digits++;
    }
    return -1;
}

int countOfIntegers(itn digits) {
    if (digits == 1) {
        return 10;
    }
    int count = (int)std::pow(10, digits - 1 );
    return 9 * count;
}

int digitAtIndex(int index, int digits) {
    int number = beginNumber(digits) + index / digits;
    int indexFormRight = digits - index % digits;
    for (int i = 1; i < indexFromtRight; ++i) {
        number /= 10;
    }
    return number % 10;
}

int beginNumber(int digits) {
    if (digits == 1) {
        return 0;
    }
    return (int) std::pow(10, digits - 1);
}

/*
 * 题目: 把数字翻译成字符串
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 把数字翻译成字母, 输出有多少种方法.
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
int GetTranslationCount(int number) {
    if (number < 0) {
        return 0;
    }

    string numberInString = to_string(number);
    return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& number) {
    int length = number.length();
    int *counts = new int[length];
    int count = 0;
    for (int i = length - 1; i >= 0; --i) {
        count = 0;
        if (i < length - 1) {
            count = counts[i+1];
        } else {
            count = 1;
        }

        if (i < length - 1) {
            int digit1 = number[i] - '0';
            int digit2 = number[i+1] - '0';
            int converted = digit1 * 10 + digit2;
            if (converted >= 10 && converted <= 25) {
                if (i < length - 2) {
                    count += counts[i + 2];
                } else {
                    count += 1;
                }
            }
        }
        counts[i] = count;
    }
    count = counts[0]
    delete[] counts;

    return count;
}


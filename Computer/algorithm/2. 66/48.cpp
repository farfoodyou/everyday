/*
 * 题目: 最长不含重复字符的子字符串
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
int longestSubstringWithoutDuplication(const std::string& str) {
    int curLength = 0;
    int maxLength = 0;
    int *position = new int[26];
    for (int i = 0; i<26; ++i) {
        position[i] = -1;
    }
    for (int i = 0; i<str.length(); ++i) {
        int prevIndex = position[str[i]-'a'];
        if (prevIndex < 0||i-prevIndex > curIndex) {
            ++curLength;
        } else {
            if (curLength > maxLength) {
                maxLength = curLength;
            }
            curLength = i - prevIndex;
        }
        position[str[i]-'a'] = i;
    }
    if (curLength > maxLength){
        maxLength = curLength;
    }
    delete[] position;
    return maxLength;
}

/*

asa
a
aa
''

*/
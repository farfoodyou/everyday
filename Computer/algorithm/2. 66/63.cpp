/*
 * 题目: 股票的最大利润
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 股票价格按时间顺序存在数组中, 买卖一次的最大利润是多少?
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
int MaxDiff(const *numbers ,unsigned length){
    if (numbers == nullptr && length < 2){
        return 0;
    };
    int min = numbers[0];
    int maxDiff = numbers[1] - min;
    for(int i = 2 ; i<length; ++i){
        if(numbers[i-1] < min) {
            min = numbers[i-1];
        }
        int currentDiff = numbers[i] - min;
        if (currentDiff > maxDiff) {
            maxDiff = currentDiff;
        }
        return maxDiff;
    }
}

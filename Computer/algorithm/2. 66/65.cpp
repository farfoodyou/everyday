/*
 * 题目: 不用加减乘除做加法
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 不用加减乘除做加法
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
int Add(int num1, int num2){
    int sum, carry;
    do {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    } while(num2 != 0);

    return num1;
}

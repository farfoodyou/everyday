/*
 * 题目: 和为s的数字
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 给一个递增数字和一个数s, 输出一对数字, 它们的和为s
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
bool FindNumbersWithSum(int data[], int length, int sum,int*num1, int* num2){
    bool found = false;
    if(length < 1 || num1 == nullptr || num2 == nullptr){
        return found;
    }

    int ahead = length - 1;
    int behind = 0;

    while(ahead > behind){
        long long curSum = data[ahead] + data[behind];

        if(curSum == sum){
            *num1 = data[behind];
            *num2 = data[ahead];

            found = true;
            break;
        }
    } else if(curSum > sum){
        ahead --;
    } else {
        behind ++;
    }

    return found;
} 

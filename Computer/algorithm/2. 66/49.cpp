/*
 * 题目: 丑数
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 包含因子 2 3 5的数, 求从小到大的第n个丑数
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
bool IsUgly (int number) {
    while(number % 2==0) {
        number /= 2;
    }
    while(number % 3 == 0){
        number /= 3;
    }
    while(number % 5 ==0){
        number /= 5;
    }
    return  (number ==1) ? true:false;
}

int GetUglyNumber_Solution2(int index) {
    if(index <=0){
        return 0;
    }
    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1

    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;

    while(nextUglyIndex < index){
        int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        pUglyNumbers[nextUglyIndex] = min;
        while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex]){
            ++pMultiply2;
        }
        while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex]){
            ++pMultiply3;
        }
        while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex]){
            ++pMultiply5;
        }
        ++nextUglyIndex;
    }
    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete[] pUglyNumbers;
    return ugly;
}

int Min(int number1, int number2, int number3){
    int min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;
    return min;
}

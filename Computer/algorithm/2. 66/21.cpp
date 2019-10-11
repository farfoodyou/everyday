/*
 * 题目: 调整数组顺序使奇数位位于偶数位前面
 * 输入参数: 一个整数数组
 * 输出参数: 
 * 返回结果: 
 * 描述: 输入一个整数数组, 实现一个函数来调整该数组中数组的顺序,所有的奇数位位于数组前半部分, 所有偶数位位于数组的后半部分
 * 例如, 1 2 3 4 5 -> 1 3 5 2 4
 * 思路: 奇数位比偶数位 小/大
*/
void RecorderOddEven(int* pData, unsigned int length) {
    if(pData == nullptr || length == 0){
        return ;
    }
    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd){
        while(pBegin < pEnd && (*pBegin & 0x1 ) != 0){
            pBegin++;
        }
        while(pBegin < pEnd && (*pEnd & Ox1) == 0){
            pEnd--;
        }
        if(pBegin<pEnd){
            //swap(*pBegin, *pEnd);
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEndd = temp;
        }
    }
}

void Recorder(int* pData, unsigned int length, bool (*func)(int)) {
    if(pData == nullptr || length == 0){
        return ;
    }
    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd){
        while(pBegin < pEnd && !func(*pBegin)){
            pBegin++;
        }
        while(pBegin < pEnd && func(*pEnd)){
            pEnd--;
        }
        if(pBegin<pEnd){
            //swap(*pBegin, *pEnd);
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEndd = temp;
        }
    }
}

bool isEven(int n){
    return (n & 1) == 0;
}

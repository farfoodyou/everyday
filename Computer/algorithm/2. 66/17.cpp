/*
 * 题目: 打印从1到最大的n位数
 * 输入参数: 一个整数n
 * 输出参数: 从1到n位最大数的列表
 * 返回结果: 
 * 描述: 输入数字n, 按顺序打印出从1到最大的n的十进制数 
 * 例1 输入3, 打印出1,2,3一直到 3位数 999
 * 
*/

void Print1ToMaxOfNDigits(int n){
    if(n <= 0){
        return ;
    }

    char *numbers = new char[n +1];
    memset(number, '0', n);
    numbers[n] = '\0';

    while(!=Increment(number)) {
        PrintNumber(number);
    }

    delete[] number;
}

bool Increment(char* number) {
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);
    for(int i = nLength -1; i>=0; i--) {
        int nSum = numbers[i] - '0' + nTakeOver;
        if( i == nLength - 1 ){
            nSum++;
        }
        if(nSum >= 10 ){
            if(i == 0) {
                isOverflow = true;
            } else {
                nSum -= 10;
                nTakeOver =1;
                number[i] = '0' + nSum;
            }
        } else {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

void PrintNumber(char* numnber ){
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i = 0; i <nLength; ++i){
        if( isBeginning0 && numbers[i] != '0'){
            isBeginning0 = false;
        }
        if(!isBeginning0){
            printf("%c", number[i]);
        }
    }
    printf("\t");
}


// =============================================================

void PrintToMaxOfNDigits(int n){
    if(n <= 0){
        return ;
    }
    char * number = new char[n+1];
    numbe[n] = '\0';

    for(int i = 0; i<10 ;++i){
        number[0] = i+ '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index){
    if(index = length -1){
        PrintNumber(number);
        return ;
    }
    for(int i = 0; i<10; i++){
        number[index + 1] = i+ '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

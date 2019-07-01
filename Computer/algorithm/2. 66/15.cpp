
// 负数会死循环
int NumberOf1(int n){
    int count = 0;
    while(n){
        if(n&1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

// 可以用负数
int NumberOf1(int n){
    int count = 0;
    unsigned int flag =1;
    while(flag) {
        if(n&flag){
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

// 更快
int NumberOf1(int n){
    int count = 0;
    while(n) {
        ++count;
        n = (n -1 ) & n;
    }
    return count;
}

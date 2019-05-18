#include <cstdio>

int fun1 (int value) {
    int ret = 0;
    if (value > 90) {
        ret = 1;
        goto FUN_END;
    } else {
        ret = -1;
    }
    FUN_END:
    return ret;
}

int fun2 (int value) {
    int ret = 0;
    do {
        if (value > 90) {
            ret = 1;
            break;
        } else {
            ret = -1;
            break;
        }
    } while(0);
    return ret;
}

int main(){
    printf("%d\n",fun1(4));
    printf("%d\n",fun2(98));
    return 0;
}

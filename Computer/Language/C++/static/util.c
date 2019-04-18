#include "util.h"

int echo_printf(){
    printf("echo hi\n");
    return 0;
}

char* echo_chars(){
    static char z[] = "are you ok?\n";
    char * str = (char*)malloc(sizeof("are you ok?\n"));
    return z;
}

/*
* 用来记录该函数的调用次数
* @param void
# @return int 函数调用的次数
*/
int add_time(){
    static int time = 0;
    return ++time;
}
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){
    echo_printf();

    printf("%s \nover\n",echo_chars());

    printf("%d %d %d",add_time(),add_time(),add_time());
    return 0;
}

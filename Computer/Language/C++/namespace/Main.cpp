#include "Base.h"
#include <cstdio>

int main(){
    YL::TRY::Base o;
    printf("%d\n", o.get());
    printf("%d\n", ::YL::TRY::echo());
    int array[100];
    for (int i = 0; i<100; i++) {
        array[i] = i*i;
    }
    
    return 0;
}
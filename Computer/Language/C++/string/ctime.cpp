
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>

int test1(){
    printf("========[ 1 ]==========\n");
    int64_t a =  std::time(0);
    char ctime[64] ;
    sprintf(ctime,  "%lld" , a);
    printf("%lld  %s \n",a,ctime);
    std::string  time_str(ctime);
    std::cout << time_str << std::endl;
    return 0;
}

int test2(){
    char ctime[64] ;
    printf("========[ 2 ]==========\n");
    std::time_t a =  std::time(0);
    sprintf(ctime,  "%ld" , a);
    printf("%ld  %s \n",a,ctime);
    std::string  time_str(ctime);
    std::cout << time_str  << std::endl;
    return 0;
}

int test3(){
    char ctime[64] ;
    printf("========[ 3 ]==========\n");
    time_t a =  std::time(0);
    sprintf(ctime,  "%ld" , a);
    printf("%ld  %s \n",a,ctime);
    std::string  time_str(ctime);
    std::cout << time_str  << std::endl;
    return 0;
}

int test4(){
    char ctime[64] ;
    printf("========[ 3 ]==========\n");
    time_t a =  std::time(0);
    sprintf(ctime,  "%ld" , a);
    printf("%ld  %s \n",a,ctime);
    std::string  time_str(ctime);
    std::cout << time_str  << std::endl;
    return 0;
}
int test5(){
    printf("\033[47;31mThis is a color test.\n\033[0m");
    printf("\033[40;31mThis is a color test.\n\033[0m");
    printf("\033[40;32mThis is a color test.\n\033[0m");
    return 0;
}
int main(){

    // int to char *[] string
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;  
}
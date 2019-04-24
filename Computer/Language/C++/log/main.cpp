#include <cstdio>
//#include "log.h"
#include <stdio.h>
#include <time.h>
 
#define LOG(s) do{													\
    time_t t;														\
    struct tm* ti;													\
    time(&t);														\
    ti = localtime(&t);												\
    printf("%s[%s: %d]  %s\n", asctime(ti), __FILE__, __LINE__, s); \
}while(0)

#define DEBUG
#ifdef	DEBUG
#define debug(fmt,args...)	printf (fmt ,##args)
#define debugX(level,fmt,args...) if (DEBUG>=level) printf(fmt,##args);
#else
#define debug(fmt,args...)
#define debugX(level,fmt,args...)
#endif	/* DEBUG */

int main() {

    LOG("[ --- debug --- ]");
    printf("===== over =====");
    return 0;
}
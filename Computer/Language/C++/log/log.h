// 正常日志info打印
#include <ctime>
#include <cstdio>

#define LOG_INFO(format, ...)                                                                           \
{                                                                                                       \
    time_t t = time(0);                                                                                 \
    struct tm ttt = *localtime(&t);                                                                     \
    fprintf(stdout, "[INFO] [%5d %4d-%02d-%02d %02d:%02d:%02d] [%s:%d] " format "",                     \
            GetCurrentProcessId(), ttt.tm_year + 1900, ttt.tm_mon + 1, ttt.tm_mday, ttt.tm_hour,        \
            ttt.tm_min, ttt.tm_sec, __FUNCTION__ , __LINE__, ##__VA_ARGS__);                            \
}

// 错误日志error打印
#define LOG_ERR(format, ...)                                                                            \
{                                                                                                       \
    time_t t = time(0);                                                                                 \
    struct tm ttt = *localtime(&t);                                                                     \
    fprintf(stderr, "[ERROR] [%5d %4d-%02d-%02d %02d:%02d:%02d] [%s:%d] " format "",                    \
            GetCurrentProcessId(), ttt.tm_year + 1900, ttt.tm_mon + 1, ttt.tm_mday, ttt.tm_hour,        \
            ttt.tm_min, ttt.tm_sec, __FUNCTION__ , __LINE__, ##__VA_ARGS__);                            \
}

// tag: log, macro, log macro
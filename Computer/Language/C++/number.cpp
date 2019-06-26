#include <cstdio>

int main(){
    long long x = 9090;
    long long y = 10000;
    long long z = 8000;
            printf("[Latency]\n"
                   "  avg     %10lld us  %lf%% \n"
                   "  50%%     %10lld us %lf%% \n"
                   "  90%%     %10lld us\n",
                   x, (double)(y-x)/x * 100,
                   x, (double)(z-x)/x * 100,
                   1000.0);
    return 0;
}
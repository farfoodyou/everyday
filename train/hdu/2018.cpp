#include <cstdio>
#include <cstring>
int main(){
    long long big[60],small[60],n;
    memset(big,0,sizeof(big));
    memset(small,0,sizeof(small));
    big[1]=1;big[2]=2;big[3]=3;big[4]=4;
    for(int i = 4; i <60; i++){
        big[i] = big[i-1]+big[i-3];
    }
    while(scanf("%d",&n)==1 && n){
        printf("%lld\n",big[n]);
    }
    return 0;
}


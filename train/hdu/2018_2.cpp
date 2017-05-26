#include <cstdio>
#include <cstring>
int main(){
    long long big[60],small[60],n;
    memset(big,0,sizeof(big));
    memset(small,0,sizeof(small));
    big[1]=1;big[2]=1;big[3]=1;big[4]=1;
    small[1]=0;small[2]=1;small[3]=2;small[4]=3;
    for(int i = 5; i <60; i++){
        big[i] = big[i-3] + small[i-3];
        small[i] = big[i-1]+small[i-1];
        printf("#%d %lld %lld %lld\n",i,big[i],small[i],big[i]+small[i]);
    }
    while(scanf("%d",&n)==1 && n){
        printf("%lld\n",big[n]+small[n]);
    }
    return 0;
}


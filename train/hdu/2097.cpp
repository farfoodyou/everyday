#include <cstdio>
#include <cstring>

int solve(int m){
    int zsum=0,bsum=0;
    int t = m;
    while(t){
        zsum+=t%10;
        t/=10;
    }
    t = m;
    while(t){
        bsum+=t%16;
        t/=16;
    }
    if(bsum!=zsum)return 0;
    t = m;
    bsum = 0;
    while(t){
        bsum+=t%12;
        t/=12;
    }
    if(bsum!=zsum)return 0;
    return 1;
}
int main(){
    int n;
    while(scanf("%d",&n)==1 && n){
            if(solve(n))printf("%d is a Sky Number.\n",n);
            else printf("%d is not a Sky Number.\n",n);
    }
    return 0;
}

#include <cstdio>
#include <cstring>

int ah,am,as,bh,bm,bs;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
        ah+=bh;
        am+=bm;
        as+=bs;
        am += as/60;
        as = as%60;
        ah += am/60;
        am = am%60;
        printf("%d %d %d\n",ah,am,as);
    }
    return 0;
}

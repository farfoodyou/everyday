#include <cstdio>
#include <cstring>

int solve(int m){
    int rmb[7];
    int num = 0;
    rmb[1]=100;rmb[2]=50;rmb[3]=10;rmb[4]=5;rmb[5]=2;rmb[6]=1;
    for(int i =1; i<= 6; i++){
        num += m / rmb[i];
        m = m%rmb[i];
    }
    return num;
}
int main(){
    int n;
    while(scanf("%d",&n)==1 && n){
        int ans = 0;
        for(int i =1; i<= n; i++){
            int t;
            scanf("%d",&t);
            ans+=solve(t);
        }
        printf("%d\n",ans);
    }
    return 0;
}

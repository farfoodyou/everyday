#include <cstdio>
#include <cstring>

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)==2&&a&&b){
        int t = a*10;
        int ans[150],cnt=0;
        for(int i = 0; i<=9;i++){
            if((t+i)%b==0)ans[cnt++]=i;
        }
        t = a * 100;
        for(int i = 10; i<=99; i++){
            if((t+i)%b==0)ans[cnt++]=i;
        }
        for(int i= 0; i<cnt; i++){
            if(ans[i]<10)printf("0%d%c",ans[i],i==cnt-1?'\n':' ');
            else printf("%d%c",ans[i],i==cnt-1?'\n':' ');
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && n && m){
        int num;
        for(int i = 1; i<= n; i++){
        scanf("%d",&num);
        //printf("%d%c",num,i==n?'\n':' ');
        if(m<num){
            printf("%d%c%d%c",m,' ',num,i==n?'\n':' ');
            m = 2000000000;
        }else{
            printf("%d%c",num,i==n?'\n':' ');
        }
        }
    }
}

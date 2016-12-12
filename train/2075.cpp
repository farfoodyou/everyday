#include <cstdio>

int a,b;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&a,&b);
        if(a%b==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

#include <cstdio>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        a%=100;
        b%=100;
        printf("%d\n",(a+b)%100);
    }
    return 0;
}

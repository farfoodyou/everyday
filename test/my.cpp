#include <cstdio>

int main(){
        int a;
        scanf("%d",&a);
        int t = a;
        while(a){
          printf("%d\n",a%10);
          a/=10;
        }
        printf("your input is %d\n",t);
        printf("you\n");
        return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct num{
    int num;
    int value;
    bool operator < (const struct num &t)const{
        return value > t.value;
    }
}N[150];

int main(){
    int n;
    while(scanf("%d",&n)==1 && n){
        for(int i = 1; i<= n; i++){
            int t;
            scanf("%d",&t);
            N[i].num = t;
            if(t<0)t = -t;
            N[i].value = t;
        }
        sort(N+1,N+n+1);
        for(int i= 1; i<= n; i++)printf("%d%c",N[i].num,i==n?'\n':' ');
    }
    return 0;
}

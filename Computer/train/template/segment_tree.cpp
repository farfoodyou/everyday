#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 100005  
#define LL long long  
LL a[maxn];  
  
int main ()  
{  
    LL m,n;  
    while(~ scanf("%lld%lld",&m,&n))  
    {  
        if(m == 0 && n == 0) break;  
        LL ans=0;  
        for(LL i = 1; i <= min(m,n); i+=2) {  
            ans += (m-i+1)*(n-i+1)*(i/2*2+1);  
        }  
        printf("%lld\n",ans);  
    }  
}  
#include <cstdio>
#include <cstring>
const int maxn = 10005;
bool isNotPrime[maxn];
int num_prime=0,prime[maxn+5];
void solve()
{
    isNotPrime[1]=1;
    for(long i = 2 ; i < maxn ; i ++)
    {
        if(! isNotPrime[i])
            prime[num_prime ++]=i;
        //关键处1
        for(long j = 0 ; j < num_prime && i * prime[j] <  maxn ; j ++)
        {
            isNotPrime[i * prime[j]] = 1;
            if( !(i % prime[j] ) )  //关键处2
                break;
        }
    }

}
int main(){
    int n;

    memset(isNotPrime,-1,sizeof(isNotPrime));
    solve();
    for(int i = 0; i <20;i++){
        //printf("p = %d\n",prime[i]);
    }
    while(scanf("%d",&n)==1&&n){
        int ans = 0;
        for(int i = 0; i <num_prime;i++){
            if(prime[i]<n/2&&!isNotPrime[n-prime[i]]){
                //printf("%d %d\n",prime[i],n-prime[i]);
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}

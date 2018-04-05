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
        //¹Ø¼ü´¦1
        for(int k = i*i; k < maxn; k+=i)
        {
            isNotPrime[k] = 1;
        }
    }

}
int main(){
    int n;

    memset(isNotPrime,0,sizeof(isNotPrime));
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

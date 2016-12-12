
const int maxn = 10005;
bool isNotPrime[maxn];
int num_prime=0,prime[maxn+5];
void solve()
{
    memset(isNotPrime,0,sizeof(isNotPrime));
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




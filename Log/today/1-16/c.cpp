#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define LL long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 500100;
LL sum[maxn] = {0};
int n,x,inc[maxn];
int main() {
    int t,i,lt,rt,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&x);
        for(i = 1; i <= n; i++){
            scanf("%lld",sum+i);
            sum[i] += sum[i-1];
        }
        lt = 0;
        inc[0] = rt = 1;
        ans = n+1;
        for(i = 2; i <= n; i++){
            while(lt < rt && sum[i] <= sum[inc[rt-1]]) rt--;
            inc[rt++] = i;
            while(lt + 1 < rt && sum[i] - sum[inc[lt]] >= x){
                ans = min(ans,i-inc[lt]);
                lt++;
            }
        }
        ans == n+1?puts("-1"):printf("%lld\n",ans);
    }
    return 0;
}


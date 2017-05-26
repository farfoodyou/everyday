#define LOCAL

#include <bits/stdc++.h>   
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int inf = 1e9+5;
const int maxn = 1e5+5;

int i,j,k;
long long dp[66];
long long myabs(long long x){
    if(x <0)return -x;
    else return x;
}
long long cha(long long num){
    for(int i = 0; i <63;i ++){
        if(dp[i+1]>num && dp[i] <= num){
            printf("%lld  %d  %lld\n", num - dp[i], i,dp[i]);
            return num - dp[i];
        }
    }
    return -1;
}
long long cha2(long long num){
    for(int i = 0; i <63;i ++){
        if( dp[i] >= num){
            printf("last  %lld\n",dp[i] - num);
            return dp[i] - num;
        }
    }
    return -1;
}
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    dp[0] = 1;
    for(int i = 1; i < 64; i++){
        dp[i] = dp[i-1] * 2;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,n,k;
        scanf("%d%d",&n,&k);
        long long ta = 0;
        long long ans = 0,tta;

        for(int j = 0; j < k-1; j++ ){
            if(j == 0){
                
                ta = cha((long long)n);
                tta = ta;
                continue;
            }
            
            if(ta == -1){
                printf("find 1\n");
                ans = cha2(tta);
                break;
            }
            tta = ta;
            ta = cha(ta);
        }
        if(ta != -1){
            printf("find 2\n");
            ans = cha2(tta);
            //break;
        }
        printf("ans = %lld\n",ans);
    }



    return 0;
}




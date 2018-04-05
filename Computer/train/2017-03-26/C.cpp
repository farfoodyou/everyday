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
const int MOD = 10007;
int mp[150][150];
int i,j,k;
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int dp[50];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < 33; i++){
        if(i <= 1){
            dp[i] = (dp[i] + dp[i-1])%MOD;
        }
        if(i > 1 && i <= 2){
            dp[i] = (dp[i] + dp[i-1] +dp[i-2])%MOD;
        }
        if(i >=3){
            dp[i] = (dp[i] + dp[i-1] +dp[i-2] + dp[i-3])%MOD;
        }
    }
    for(int i = 1; i <22; i++){
        //printf("%d ",dp[i]);
    }//printf("%d \n",dp[2]);
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,n;
        int ans = 1;
        scanf("%d",&n);
        for(int k = 1; k<= n-1; k++){
            scanf("%d",&a);
            //printf("%d \n",ans);
            ans = (dp[a] * ans )% MOD;
        }
        printf("%d\n",ans);
        ans = 1;
        
    }



    return 0;
}




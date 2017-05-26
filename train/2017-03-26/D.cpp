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
int mp[150][150];
int i,j,k;
long long dp[66];
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < 64; i++){
        dp[i] = dp[i-1] * 2;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int num = a / 10;
        printf("%d\n",(a/30)*c + a*b);
        
    }



    return 0;
}




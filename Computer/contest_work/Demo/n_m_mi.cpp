#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print2V(vector<vector<int> > input) {
    for(int i = 0; i< input.size(); i++) {
        for(int j = 0; j< input[i].size(); j++) {
            if(j)std::cout << " ";
            std::cout << input[i][j] ;
        }
        std::cout << std::endl;
    }
}

int g_dp[31][11];
int g_n = 30;
int g_m = 10;
int g_cap[10] = {10,10,10,10,10,10,10,10,10,10};
int run(int n, int v){
    //std::cout << n << " " << v << std::endl;
    if(n ==0 && v==0){
        return 1;
    } else if(v==0){
        return 0;
    }
    if(g_dp[n][v] != 0) {
        return g_dp[n][v];
    }
    int res = 0;

    for(int k= g_cap[v-1]; k>=0 ; k--){
        if(n-k>=0)
            res += run(n-k, v-1);
    }

    g_dp[n][v] =res;
    return g_dp[n][v];
}

int main(){

    int n = 30;
    int m = 10;
    vector<int > cap(g_cap, g_cap+10);
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    dp[0][0] = 1;
    for(int i = 1; i<=m; i++) {
        for(int j = 0; j<=n; j++){
            for(int k = cap[i-1]; k>=0; k--){
                if(j-k>=0)
                    dp[j][i] += dp[j-k][i-1];
            }
        }
    }
    print2V(dp);
    std::cout << dp[n][m] << std::endl;

    memset(g_dp, 0, sizeof(g_dp));
    g_dp[0][0] = 1;
    std::cout << run(g_n,g_m) << std::endl;

    for(int i=0; i<= g_n; i++){
        for(int j = 0; j<= g_m; j++){
            if(j)std::cout << " ";
            std::cout << g_dp[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}

/*
给定n个球，m个桶，每个桶的最大容量是[公式]，[公式]和n的大小不定，但是所有桶的容量和大于n，可以允许有桶不放球，问有多少种方法？

dp[i][j] 表示 i个球, m个桶的方法数
dp[i][j] = dp[i-k][j-1]  k>=0 && k<= min(i,cap[j])

球放入桶问题，有多少种组合？ - 知乎
https://www.zhihu.com/question/29840334
*/
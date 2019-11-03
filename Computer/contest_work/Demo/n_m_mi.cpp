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

int main(){

    int n = 30;
    int m = 10;
    vector<int > cap(m, 10);
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    dp[0][0] = 1;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++){
            for(int k = cap[j-1]; k>=0; k--){
                if(i-k>=0)
                    dp[i][j] += dp[i-k][j-1];
            }
        }
    }
    print2V(dp);
    std::cout << dp[n][m] << std::endl;
    return 0;
}

/*
给定n个球，m个桶，每个桶的最大容量是[公式]，[公式]和n的大小不定，但是所有桶的容量和大于n，可以允许有桶不放球，问有多少种方法？

类似有限制的都可以用动态规划来搞, 第一个想的是从这个桶出发, 这个桶存0个或者 1个
*/
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
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int num = c / 4;
        int ans = 0;
        for(int ans = 0; ans <= num; ans++){
            if(((a/2 - ans )   +  (b - ans ) + ans) == num){
                printf("%d\n",ans);
                break;
            }
        }
        //printf("no\n");
    }



    return 0;
}




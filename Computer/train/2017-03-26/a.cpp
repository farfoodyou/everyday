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
int myabs(int x){
    if(x < 0)return -x;
    else return x;
}
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,x,y;
        scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
        if(a%2==0){
            printf("-1\n");
        }else{
            if(a >= myabs(b-x)+myabs(c-y)){
                printf("2\n");
            }else
            printf("1\n");
        }
        //printf("no\n");
    }



    return 0;
}




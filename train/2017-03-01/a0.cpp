#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;

int main(){
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif
        int mp[150];
        int cases,N;
        scanf("%d",&cases);
        while(cases--) {
            memset(mp,0,sizeof(mp));
                scanf("%d",&N);
                for(int z = 1; z <= N ; z++){
                   int i,j,k;
                   cin >> i >> j >> k;
                   for(int x = i ; x <= j-1; x++){
                     if(mp[x]<k) mp[x] = k;
                   }
                }
                int ans = 0;
                for(int x = 0; x <= 120; x++){
                  ans += mp[x];
                  //printf(" %d ",mp[x]);
                }//printf("\n");
                cout<< ans << endl;
        }
        return 0;
}




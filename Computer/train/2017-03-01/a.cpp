#define LOCAL

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
        int cases;
        scanf("%d",&cases);
        while(cases--) {
            int n;
            memset(mp,0,sizeof(mp));
            scanf("%d",&n);
            for(int x = 1; x<= n; x++){
              cin >> i >> j >> k;
              int zx,zy,yx,yy;
              zy = 0;
              zx = i;
              yx = j;
              yy = k;
              for(int i = zx; i <= yx; i++ ){
                for(int j = zy; j <= yy; j++){
                  mp[i][j] = 1;
                }
              }
            }
            int ans = 0;
            for(int i = 0; i <= 120;i++){
              for(int j = 0; j <= 120; j++){
                  if(mp[i][j] && mp [i+1][j+1] && mp[i+1][j] && mp[i][j+1])ans ++;
              }
            }
            for(int i = 0; i <= 10;i++){
              for(int j = 0; j <= 10; j++){
                //  printf(" %d ",mp[i][j]);
                  
              }
            //  printf("\n");
            }
            cout<< ans << endl;
        }
        return 0;
}




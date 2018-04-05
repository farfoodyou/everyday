#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>



using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M,K;
int mp[1005][1005];
int main（）{
  #ifdef LOCAL
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
  #endif
  
    while(scanf("%d%d",&N,&M)==2){
       for(int i = 1 ; i <= M; i++){
           int a,b;
           scanf("%d%d",&a,&b);
           mp[a][b] = inf;
           mp[b][a] = inf;
       }
       
    }
    return 0;
}




#define LOCAL
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>



using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M,K,ans;
std::vector<int> G[20005];
bool p[20005];
int main(){
  #ifdef LOCAL
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
  #endif
    while(scanf("%d%d",&N,&M)==2){
      memset(ru,0,sizeof(ru));
      memset(p,0,sizeof(p));
      for(int i = 1; i<= M; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        ru[v]++;
        
      }
      ans = N;
      //if()
      printf("%d\n",ans);
    }
    return 0;
}




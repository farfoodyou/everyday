#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M,K,a,b,c,ans;
int s[4];
int dfs(int len ,int d){
  if(len == 0){
    ans = d;
    return 1;
  }else if(len < 0)return inf;
  for(int i = 0; i<3; i++){
    dfs(len - s[i],d+1);
  }
}
int main(){
  #ifdef LOCAL
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
  #endif
  
    while(scanf("%d%d%d%d",&N,&a,&b,&c)==4){
      s[0] = a; s[1] = b; s [2] = c;
      sort(s,s+3); 
      ans = -1;
      dfs(N,0);
      printf("%d\n",ans);
    }
    return 0;
}




#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>



using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M,K;
struct ch{
  int v;
  int num;
}c[30];

bool cmp(struct ch a,struct ch b){
  return (b).v - (a).v;
}

int num[3000];
int main(){
  #ifdef LOCAL
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
  #endif
      
    int cases;
    scanf("%d",&cases);
    while(cases--){
      scanf("%d",&N);
      for(int i = 0; i < N; i++){
        scanf("%d%d",&c[i].v,&c[i].num);
      }      
      sort(c,c+N,cmp);
      int xi = 1;
      for(int i = 0; i<N; i++){
             
      }
    }
    return 0;
}




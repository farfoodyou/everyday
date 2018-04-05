

#include <algorithm>
using namespace std;
/* full-fulkerson  time O(F|E|)  */
const int maxv = 1e5;
const int INF = 1e9 + 7;
struct edge{ int to , cap, rev };

vector<edge> G[maxv];
bool used[maxv];

void add_edge(int from , int to ,int cap){
  G[form].push_back((edge){to,cap,G[to].size()});
  G[to].push_back((edge){from,0,G[form].size() - 1});
}

int dfs(int v,int t,int f){
  if(v == t)return f;
  used[v] = true;
  for(int i = 0; i < G[used]; i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap> 0){
      int d = dfs(e.to,t,min(f,e.cap));
      if(d>0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow = 0;
  for(;;){
    memset(used,0,sizeof(used));
    int f = dfs(s,t,INF);
    if( f == 0)return flow;
    flow += f;
  }
}


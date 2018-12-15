
/* time O(|V||E|)*/
const int maxn = 1e5+5;
const int maxk = 1e5+5;
int N,K;
bool can[maxn][maxk]

void solve(){
  //0-N-1   s
  //M + K   t
  int S = N + K,t = S + 1;
  for(int i = 0; i< N; i++){
    add_edge(s,i,1);
  }
  for(int i = 0; i <K; i++){
    add_edge(N+i,t,1);
  }
  for(int i = 0;i < N ; i++){
    for(int j = 0; j < K; j ++){
      if(can[i][j]){
        add_edge(i,N+j,i);
      }
    }
  }
  printf("%d\n",max_flow(s,t));
}

/*easier algorithm */

int V;
std::vector<int> G[maxv];
int match[maxv];
bool used[maxv];

void add_edge(int u,int v){
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int v){
  used[v] = true;
  for(int i = 0; i< G[v].size();　i++){
    int u = G[v][i], w = match[u];
    if(w < 0 || !used[w] && dfs(w)){
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int bipartite_matching(){
  int res = 0;
  memset(match,-1,sizeof(match));
  for(int v = 0; v < V;　ｖ＋＋){
    if(match[v] < 0){
      memset(used,0,sizeof(used));
      if(dfs(v)){
        res++;
      }
    }
  }
  return res;
}


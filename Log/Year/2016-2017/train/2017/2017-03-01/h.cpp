#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;

int n,m,f;
int dist[105][105],pos[15];

void get_min(){
  int k,i,j;
  for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
}

int main(){
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif
        int cases,i,j,x,y,z;
        scanf("%d",&cases);
        for(int zz=1;zz<=cases;zz++) {
          scanf("%d%d%d",&n,&m,&f);
          for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
              dist[i][j]=dist[j][i]=100000;
            }
          }
          for(i=1;i<=m;i++){
            scanf("%d%d%d",&x,&y,&z);
            dist[x][y]=dist[y][x]=min(dist[x][y],z);
          }
          get_min();
          for(i=1;i<=f;i++)
            scanf("%d",&pos[i]);
          pos[0]=1;
          pos[f+1]=n;
          sort(pos+1,pos+f+1);
          int ans = -1;
          do{
            int sum = 0;
            for(i=1;i<=f+1;i++){
              sum+=dist[pos[i]][pos[i-1]];
            }
            if(sum<ans||ans==-1)ans=sum;
            
          }while(next_permutation(pos+1,pos+f+1));
          printf("Case %d: %d\n",zz,ans);

        }
        return 0;
}




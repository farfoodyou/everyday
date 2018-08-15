#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;




int X[] = {-1,-1,1,1};
int Y[] = {-1,1, -1,1};
int a,b,c,d,n;
int dist[22][22],visited[22][22];

int bfs(){
	queue < pair < int ,int > > q;
	q.push(make_pair( a, b));
	dist[a][b] = 0;
	visited[a][b] = 1;
	while(!q.empty()){
		pair < int ,int > cur = q.front();
		q.pop();
		if(cur.first == c && cur.second == d)
			return dist[c][d];
		for(int i = 0; i < 4 ; i++){
			int x = cur.first + X[i] , y = cur.second + Y[i];
			if( x >= 0 && x < n && y >=0 && y < n && ! visited[x][y]){
				dist[x][y] = dist[cur.first][cur.second] + 1;
				visited[x][y] = 1;
				q.push(make_pair ( x, y));
			}
		}
	}
	return -1;
}

int main(){
	int t;
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif
	scanf("%d%d",&t,&n);
	for(int i = 1; i<= t; i++){
		memset(visited,0,sizeof(visited));
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int res = bfs();
		if(res == -1)
			printf("can't reach!\n");
		else 
			printf("%d\n",res);
	}
	return 0;
}





#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
#define maxn 20005

int fr[maxn + 5];

int main(){
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif
	int tc,i,j,n,x;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		memset(fr,0,sizeof(fr));
		int mx = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&x);
			fr[x] = fr[x-1] + 1;
			mx = max(mx,fr[x]);
		}
		printf("%d\n",mx);
	}
	return 0;
}



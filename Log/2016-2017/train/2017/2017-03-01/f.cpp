#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;

int main(){
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif
        int cases;
        int n,a[1200],i,j,sum,pe,cnt;
        scanf("%d",&cases);
        for(int k = 1; k<= cases; k++){
                
                cin >> n;
                for(int i = 0; i< n; i++){
                  cin >> a[i];
                }
                sort(a,a+n);
                cnt = 0; pe=0; sum = 0;
                for(int i = 0; i < n; i++){
                  if(sum+ a[i] <= 300)sum += a[i],pe +=sum,cnt++;
                  else break;
                }
                printf("Case %d: %d %d\n",k,cnt,pe);
        }
        return 0;
}




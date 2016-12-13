#include <stdio.h>
#include <bitset>
#include <string.h>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <math.h>
#include <queue>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define pi (acos(-1.0))
#define fi first
#define se second
#define lson (o<<1),l,mid
#define rson (o<<1|1),mid+1,r
#define MP make_pair
#define sqr(x) ((x)*(x))
const double eps = 1e-9 ;
const int inf = 0x3f3f3f3f ;
const ll INF = (ll)4e18 ;
const int MOD=(int)1e9+7,BAS=257,invBAS=70038911;
int sign(double x){return x<-eps?-1:x>eps;}
const int maxn = 1e6+4;

int n,num[maxn];

int main(){
	while(scanf("%d",&n)==1){
		for(int i = 1; i<= n; i++){
			scanf("%d",&num[i]);
		}
		int flag = 1;
		for(int i = 1; i<=(int)2e9; i++){
			flag = 1; // i is ok
			for(int j = 1; j<=n; j++){
				if((i % num[j])!=0){
					flag = 0;
					break;
				}
			}
			if(flag){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}




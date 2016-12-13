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

int num[50][50];

int main(){
	int n;
	while(scanf("%d",&n)==1){
		for(int i = 1; i<= n; i++){
			for(int j = 1; j<= i; j++){
				if(j==1&&j==i){
					num[i][j]=1;
					continue;
				}
				num[i][j] = num[i-1][j-1] + num[i-1][j];
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= i ;j++){
				printf("%d%c",num[i][j],j==i?'\n':' ');
			}
		}
		printf("\n");
	}
	return 0;
}




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


int str[213];
int len;

int main(){
	int n,r;
	while(scanf("%d%d",&n,&r)==2){
		int fu = 0; // n > 0
		if(n<0){fu = 1; n = -n;}
		len = 0;
		while(n){
			str[len++] = n % r;
			n /= r;
		}
		if(fu)printf("-");
		while(len){
			len--;
			if(str[len]>=10){
				printf("%c",str[len]-10+'A');
			}else{
				printf("%d",str[len]);
			}
		}
		printf("\n");
	}
	return 0;
}


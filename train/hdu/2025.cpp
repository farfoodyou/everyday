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

char str[150];

int main(){
	while(scanf("%s",str)==1){
		int max = 0,i;
		for( i = 0; str[i] != '\0'; i++){
			if(str[i]>max)max = str[i];
		}
		for( i = 0; str[i] != '\0'; i++){
			if(str[i]==max)printf("%c(max)",str[i]);
			else printf("%c",str[i]);
		}
		printf("\n");
	}
	return 0;
}


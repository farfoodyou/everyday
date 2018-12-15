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
int scan(char *s){
	char t = getchar();
	if(t==EOF)return 0;
	int cnt = 0;
	while(t!='\n'){
		s[cnt++] = t;
		t = getchar();
	}
	s[cnt] = '\0';
	return 1;
}

int isfirst(char *s,int i){
	if(i == 0 && isalpha(s[i]))return 1;
	if(s[i-1]==' '&&isalpha(str[i]))return 1;
	return 0;
}

int main(){
	while(scan(str)){
		for(int i = 0; str[i]!='\0';i++){
			if(isfirst(str,i) && islower(str[i]))str[i] = str[i] - 'a' + 'A';
		}
		printf("%s\n",str);
	}
	return 0;
}

	


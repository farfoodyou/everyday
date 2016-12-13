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
int N;
char str[100];
int judge(char t){
	if(t>='a'&& t<='z')return 1;
	if(t>='A'&& t<='Z')return 1;
	if(t>='0'&& t<='9')return 1;
	if(t == '_')return 1;
	return 0;
}
int scan(char *s){
	char t = getchar();
	int cnt = 0;
	while(t!='\n'){
		//printf("t = %c\n",t);
		s[cnt++] = t;
		t = getchar();
	}
    s[cnt]= '\0';
	//printf("str is %s\n",s);
	return 1;
}
int main(){
	scanf("%d",&N);
	getchar();
	while(N--){
		scan(str);
		int flag = 1; // string is ok;
		if(str[0]>='0'&&str[0]<='9')flag = 0; // first char cann't be num;
		for(int i = 0; str[i]!= '\0';i++){
			if(!judge(str[i])){
				flag = 0; // string is wrong;
				break;
			}
		}
		if(flag)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}


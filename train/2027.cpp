
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

char str[110];

int scan(char *s){
	char t = getchar();
	if(t==EOF)return 0;
	int cnt=0;
	while(t!='\n'&&t!=EOF){
		s[cnt++] = t;
		t = getchar();
	}
	return 1;
}

int main(){
	int n,ans[6];
	scanf("%d",&n);
	getchar();
	while(n--){
		memset(ans,0,sizeof(ans));
		//scan(str);
		gets(str);
		//printf("%s\n",str);
		//for(int i = 0; str[i]!= '\0'; i++){
		//	if(isupper(str[i]))str[i] = str[i] - 'A' + 'a';
		//}
		for(int i = 0; str[i]!= '\0'; i++){
			switch(str[i]){
				case 'a':
					ans[1]++;break;
				case 'e':
					ans[2]++;break;
				case 'i':
					ans[3]++;break;
				case 'o':
					ans[4]++;break;
				case 'u':
					ans[5]++;break;
			}
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",ans[1],ans[2],ans[3],ans[4],ans[5]);
		if(n != 0)printf("\n");
	}
	return 0;
}




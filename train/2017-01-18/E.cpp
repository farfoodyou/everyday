#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>



using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M,K,a,b,c,ans;
int s[4];


int main(){
  #ifdef LOCAL
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
  #endif
  
    while(scanf("%d%d%d%d",&N,&a,&b,&c)==4){
      s[0] = a; s[1] = b; s [2] = c;
      sort(s,s+3); 
      ans = -1;
      int flag = 1;
      //printf("   %d %d %d \n",s[0],s[1],s[2]);
      for(int i = N/s[0]  ; i >= 0 && flag ; i--){
        for(int j = N/s[1]  ; j >= 0 && flag ; j--){
            if((N - s[0]* i - s[1]* j) % s[2]==0 
            && (N - s[0]* i - s[1]* j)>=0
            && (N - s[0]* i - s[1]* j)/s[2]>=0){
              //printf(" %d %d %d\n",i,j,(N - s[0]* i - s[1]* j)/s[2]);
              int x = i + j + (N - s[0]* i - s[1]* j)/s[2];
              if(ans < x)ans = x;
            }  
        }
      }
      printf("%d\n",ans );
    }
    return 0;
}

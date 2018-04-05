#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>



using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M,K;


int main(){
    
    while(scanf("%d%d",&N,&M)==2){
        int t = 240;
        t -= M;
        int ans = 0;
        for(int i = 1; i <= N;i++){
           if(t - i*5>=0){
              ans++;
              t -= 5*i;
           }else{
              break;
           }
        }
        printf("%d\n",ans);
    }
    return 0;
}




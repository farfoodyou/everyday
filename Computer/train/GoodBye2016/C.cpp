#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>



using namespace std;
const int inf = 1e9+5;
int N,M,K;
double jin,wei;
const double D = 40000 ;
double eps = 1e-5;
double mabs(double t){
  if(t<0)return -t;
  return t;
}
const int maxn = 200005;
int ud[maxn],ran[maxn];
int Last=inf;
int judge_r(int sco,int r){
  if(sco>=1900&&r==1){
    return 1;
  }else if(sco<=1899 && r==2){
    return 1;
  }else{
    return 0;
  }
}
int judge_s(int sco){
  for(int i= 1; i<=N;i++){
    if(judge_r(sco,ran[i])==0){
      return 0;
    }
    sco += ud[i];
  }
  Last = sco;
  return 1;
}

int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif  
    while(scanf("%d",&N)==1){
        jin=0;
        wei=D/4;
        int flag = 0;
        for(int i = 1; i<= N; i++){
          scanf("%d%d",&ud[i],&ran[i]);
        }  
        int ans = 0;
        int l = 0,r = 2000000;
        for(int i = r; i>=0; i--){
          if(judge_s(i)==1){
            ans = i;flag = 1;break;
          }
        }
        int wu = judge_s(20000005);
        if(flag && wu==0)printf("%d\n",Last);
          else if(wu)printf("Infinity\n");
          else printf("Impossible\n");
    }
    return 0;
}




#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>



using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M,K;
double jin,wei;
const double D = 40000 ;
double eps = 1e-5;
double mabs(double t){
  if(t<0)return -t;
  return t;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif  
    while(scanf("%d",&N)==1){
        jin=0;
        wei=D/4;
        int flag = 1;
        for(int i = 1; i<= N; i++){
          int dis;
          char dir[10];
          scanf("%d%s",&dis,dir);
          double tw = (double)dis;
          double tj = (double)dis;
          if(wei == D/4 && dir[0]!='S')flag = 0;
          if(wei == -D/4 && dir[0]!='N')flag = 0;
          switch(dir[0]){
            case 'N':
                 
               if(wei+tw <= D/4)wei+=tw;
               else {
                 flag = 0;
               }
               break;
            case 'S':
               if(wei-tw >= -D/4)wei-=tw;
               else{
                 flag = 0;
               }
            
          }
          //printf("%f %f %s  %d\n",(double)tw,wei,dir,flag);
        
        }  if(mabs(wei-D/4)<eps && flag )printf("YES\n");
          else printf("NO\n");
    }
    return 0;
}




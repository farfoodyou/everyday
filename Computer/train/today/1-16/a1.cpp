#define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;

pair <int,int> e[25];
int cmp(pair <int,int>  p,pair <int,int>  q){
  if(p.second < q.second)return 1;
  return 0;
}
int main(){
  
  int n,ans = 0;
  //#ifdef LOCAL
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
  //#endif
  scanf("%d",&n);
  //printf("t = %d\n",t);
  while(n--){
    int cnt = 0;
    //printf("-----------\n");
    for(cnt = 0;;cnt++){
      int x,y;
      scanf("%d%d",&x,&y);
      if(x == 0 && y == 0){
        break;
      }
      e[cnt].first = x;
      e[cnt].second = y;
    }
    //printf("--------===\n");
    cnt --;
    sort(e,e+cnt,cmp);
    //printf("--------=====\n");
    int p = 0,i=0,pt,ppt;
    pt = 0;
    for(int i=0;i<=cnt;i++)  
    {   
      if(e[i].first>=pt)  
       {  
         //printf(" %d %d\n",e[i].first,e[i].second);
         ans++;  
         pt=e[i].second;  
       }  
    } 
      printf("%d\n",ans);
     ans =0;
  }

  return 0;
}
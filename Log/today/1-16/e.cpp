#define LOCAL
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long zuhe[50];
#define ll long long
ll comb(int a,int b) //计算组合数C(n,m)
{
    ll sum=1; //线性计算
    ll n = a,m = b;
    for(ll i=1,j=n;i<=m;i++,j--)
        sum=sum*j/i;
    return sum;
}

int main(){

  #ifdef LOCAL
      freopen("in.txt","r",stdin);
      //freopen("out.txt","w",stdout);
  #endif
  zuhe[1]=1;
  //puts("bdd");
  for(int i = 2; i <=33 ; i++)
     zuhe[i] = zuhe[i-1]*i;
  int n,m,t;
  while(scanf("%d%d%d",&n,&m,&t)==3){
    //puts("dd");
    //printf(" %d %d %d\n",n,m,t);
      int b = 4,g = 1;
      long long ans = 0;
      for(int i = 4; i <= n ;i++){
        if(t-i <=m && t>i){
          //printf("%d %d %lld",i,t-i,ans );
           ans += comb(n,i) * comb(m,t-i);
        }
      }
      cout << ans <<endl;
  }
  
  //printf("%d\n",ans);
  return 0;
}
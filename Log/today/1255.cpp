#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M,K;
long long l,r;
int lenl,lenr;
int L[100];
int R[100];

int lc(int *s,int &len,long long x){
  len = 0;
  while(x){
    if(x & 1){
      s[len++] = 1;
    }else {
      s[len++] = 0;
    }
    //cout << x << endl;
    x = x>>1;
  }
  return len;
}
long long cl(int *s,int len){
  int i=len;
  long long x = 0;
  while(i){
  //cout << "s = " << x << endl; 
      x = x<<1;
      if(s[i]==1)x = x | 1;
      i--;
      
  }
  x = x<<1;
  if(s[i]==1)x = x | 1;
  //cout << "s = " << x << endl;
  return x;
}

int main(){
    //#ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //#endif  
    while(
      cin>>l>>r){
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        lenr = lenl = 0;
        lc(L,lenl,l);
        lc(R,lenr,r);
        int mlen = lenr;
        int flag = 1;
        //if(lenr > mlen)mlen = lenr;
        for(int i = mlen ; i >=0 ; i--){
          if(R[i]==1&&L[i]==0){
            for(int k = i; k >= 0; k-- ){
              R[k] = 1;
            }
            //for(int k = i+2; k <=80; k++){
            //  R[k] = 0;
            //}
            flag = 0;
            //printf("+\n");
            break;
          }else {
            R[i] = 0;
            //printf("=");
          }
        }
        long long ans = cl(R,lenr);
        //if(flag == 1)printf("0\n");
        //else 
        if (flag)ans = 0;
        cout << ans << endl;
        
        
   }
   return 0;
 }
 

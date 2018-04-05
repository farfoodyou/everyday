#define LOCAL
#include <cstdio>

int main(){
  double l,w,d,wei;
  int t,ans = 0;
  #ifdef LOCAL
      freopen("in.txt","r",stdin);
      //freopen("out.txt","w",stdout);
  #endif
  scanf("%d",&t);
  //printf("t = %d\n",t);
  while(t--){
    scanf("%lf%lf%lf%lf",&l,&w,&d,&wei);
    //printf("intput is %f %f %f %f\n",l,w,d,wei);
    if((l<=56.00 && w <=45.00 && d<=25.00 && wei <=7.00)||(wei<=7.00 && (l+w+d)<=125.0)){
      ans ++;
      printf("1\n");
    }else{
      printf("0\n");
    }
  }
  printf("%d\n",ans);
  return 0;
}
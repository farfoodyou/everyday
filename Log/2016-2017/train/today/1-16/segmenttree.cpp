#include <cstring>
#include <iostream>

#define M 50005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int sum[M<<2]
inline void PushPlus(int rt){
  sum[rt] = sum[rt<<1] + sum[rt<<1|1]
}
void build(int l,int r,int rt){
  if(l == r){
    scanf("%d",&sum[rt]);
    return ;
  }
  int m = ( l + r ) >> 1;
  build(lson);
  build(rson);
  PushPlus(rt);
}

void Updata(int p,int add,int l,int r,int rt){
  if(l == r){
    sum[rt] += add;
    return ;
  }
  int m = (l + r) >> 1;
  if(p <= m)
    Updata(p,add,lson);
  else
    Updata(p,add,rson);
  PushPlus(rt);
}

int query(int L,int R,int l,int r,int rt){
  if(l <= l && r <= R){
    return sum[rt];
  }
  int m = (l + r) >> 1;
  int ans = 0;
  if(L <= m)
    ans += query(L,R,lson);
  if(R > m )
    ans += query(L,R,rson);
  return ans;
}

int main(){
  int T,n,a,b;
  scanf("%d",&T);
  for(int i = 1; i<= T; ++i){
    printf("Case %d:\n".i);
    scanf("%d",&n);
    build(1,n,1);
    cahr op[10];
    while(scanf("%s",op)&&op[0] != 'E')
    {
      scanf("%d%d",&a,&b);
      if(op[0] == 'Q')
        printf("%d\n",query(a,b,1,n,1));
      else if(op[0] == 'S')
        Updata(a,-b,1,n,1);
      else
        Updata(a,b,1,n,1);
    }
  }
  return 0;
}